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

t_heredoc_cont	*make_heredoc_cont(t_dlst *iolst, t_data * data, int i)
{
	t_heredoc_cont	*new;
	char			*index;

	new = malloc(sizeof(t_heredoc_cont) * 1);
	if (!new)
		return (NULL);
	index = ft_itoa(i);
	new->delimeter = ft_strdup(GET_FILEPATH(iolst));
	new->tmpname = ft_strjoin("/tmp/.temp", index);
	free(index);
	if (exec_heredoc(new, data) == FAIL)
		return (NULL);
	GET_FD(iolst) = open(new->tmpname, O_RDONLY);
	return (new);
}

int	set_heredoc(t_cmd_cont *cmd, t_data *data)
{
	t_dlst			*iolst;
	t_heredoc_cont	*cont;
	int				i;

	iolst = cmd->iolst;
	i = 0;
	while (iolst)
	{
		if (GET_IOTYPE(iolst) == W_HERE_DOC)
		{
			cont = make_heredoc_cont(iolst, data, i);
			if (!cont)
				return (FAIL);
			ft_dlst_pushback(&(cmd->heredoclst.lst), ft_dlst_new(cont));
			i++;
		}
		iolst = iolst->next;
	}
	return (SUCESS);
}

int	set_append(t_dlst *iolst)
{
	int	fd;

	fd = open(GET_FILEPATH(iolst), O_CREAT|O_WRONLY|O_APPEND, 0644);
	if (fd < 0)
		return (FAIL);
	GET_FD(iolst) = fd;
	return (SUCESS);
}

int	set_output(t_dlst *iolst)
{
	int	fd;

	fd = open(GET_FILEPATH(iolst), O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd < 0)
		return (FAIL);
	GET_FD(iolst) = fd;
	return (SUCESS);
}

int	set_input(t_dlst *iolst)
{
	int	fd;

	fd = open(GET_FILEPATH(iolst), O_RDONLY);
	if (fd < 0)
		return (FAIL);
	GET_FD(iolst) = fd;
	return (SUCESS);
}

int	set_fd(t_dlst *iolst)
{
	int	status;

	status  = SUCESS;
	while (iolst)
	{
		if (GET_IOTYPE(iolst) == W_APPENDING_TO)
			status = set_append(iolst);
		else if (GET_IOTYPE(iolst) == W_REDIRECTION_OUTPUT)
			status = set_output(iolst);
		else if (GET_IOTYPE(iolst) == W_REDIRECTION_INPUT)
			status = set_input(iolst);
		if (status == FAIL)
			return (FAIL);
		iolst = iolst->next;
	}
	return (SUCESS);
}

void	close_fd(t_dlst *iolst)
{
	while (iolst)
	{
		if (GET_FD(iolst) != -1)
			close(GET_FD(iolst));
		iolst = iolst->next;
	}
}

int	set_last_in(t_dlst *iolst)
{
	int	last;
	enum e_word_type	type;

	last = -1;
	while (iolst)
	{
		type = GET_IOTYPE(iolst);
		if (type == W_HERE_DOC || type == W_REDIRECTION_INPUT)
		{
			if (last != -1)
				close(last);
			last = GET_FD(iolst);
		}
		iolst = iolst->next;
	}
	return (last);
}

int	set_last_out(t_dlst *iolst)
{
	int	last;
	enum e_word_type	type;

	last = -1;
	while (iolst)
	{
		type = GET_IOTYPE(iolst);
		if (type == W_APPENDING_TO || type == W_REDIRECTION_OUTPUT)
		{
			if (last != -1)
				close(last);
			last = GET_FD(iolst);
		}
		iolst = iolst->next;
	}
	return (last);
}

int	set_redir(t_cmd_cont *cmd, t_data *data)
{
	t_dlst	*iolst;

	cmd->heredoclst.num = set_heredocnum(cmd->iolst);
	cmd->heredoclst.lst = NULL;
	iolst = cmd->iolst;
	if (cmd->heredoclst.num)
	{
		if (set_heredoc(cmd, data) == FAIL)
		{
			close_fd(iolst);
			return (FAIL);
		}
	}
	if (set_fd(iolst) == FAIL)
	{
		close_fd(iolst);
		return (FAIL);
	}
	cmd->infile = set_last_in(iolst);
	cmd->outfile = set_last_out(iolst);
	return (SUCESS);
}
