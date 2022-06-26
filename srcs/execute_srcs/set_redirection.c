#include "exec.h"

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

	iolst = cmd->iolst;
	if (set_heredoc(cmd, data) == FAIL)
		return (FAIL);
	if (set_fd(iolst) == FAIL)
	{
		close_fd(iolst);
		return (FAIL);
	}
	cmd->infile = set_last_in(iolst);
	cmd->outfile = set_last_out(iolst);
	return (SUCESS);
}
