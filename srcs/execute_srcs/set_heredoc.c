#include "exec.h"

int	set_heredocnum(t_dlst *iolst)
{
	int	c;

	c = 0;
	while (iolst)
	{
		if (GET_IOTYPE(iolst) == W_HERE_DOC)
			c++;
		iolst = iolst->next;
	}
	return (c);
}

int	exec_heredoc(t_heredoc_cont *new, t_data *data)
{
	int		fd;
	char	*input;
	char	*trimmed;
	char	*replaced;

	fd = open(new->tmpname, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd > 0)
	{
		while (1)
		{
			input = get_next_line(0);
			trimmed = ft_strtrim(input, "\n");
			if (!input || ft_strcmp(new->delimeter, trimmed) == 0)
			{
				free(input);
				free(trimmed);
				break ;
			}
			replaced = get_replaced(data, input);
			write(fd, replaced, ft_strlen(replaced));
			free(replaced);
			free(trimmed);
		}
		close(fd);
		return (SUCESS);
	}
	else
		return (FAIL);
}

int	set_heredoc_cont(t_dlst *iolst, t_data *data, int i)
{
	char	*index;

	index = ft_itoa(i);
	GET_TMPNAME(iolst) = ft_strjoin("/tmp/.temp", index);
	free(index);
	if (exec_heredoc(new, data) == FAIL)
		return (FAIL);
	GET_FD(iolst) = open(GET_TMPNAME(iolst), O_RDONLY);
	return (SUCESS);
}

int	set_heredoc(t_cmd_cont *cmd, t_data *data)
{
	t_dlst	*iolst;
	int		i;

	cmd->heredoclst.num = set_heredocnum(cmd->iolst);
	iolst = cmd->iolst;
	i = 0;
	if (cmd->heredoclst.num)
	{
		while (iolst)
		{
			if (GET_IOTYPE(iolst) == W_HERE_DOC)
				set_heredoc_cont(iolst, data, i++);
			iolst = iolst->next;
		}
	}
}
