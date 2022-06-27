/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 03:48:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 23:37:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	open_file(t_dlst *iolst, enum e_word_type type)
{
	int	fd;

	if (type == W_APPENDING_TO)
		fd = open(GET_FILEPATH(iolst), O_CREAT|O_WRONLY|O_APPEND, 0644);
	else if (type == W_REDIRECTION_OUTPUT)
		fd = open(GET_FILEPATH(iolst), O_CREAT|O_WRONLY|O_TRUNC, 0644);
	else if (type == W_REDIRECTION_INPUT)
		fd = open(GET_FILEPATH(iolst), O_RDONLY);
	else
		return (SUCESS);
	if (fd < 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (FAIL);
	}
	GET_FD(iolst) = fd;
	return (SUCESS);
}

int	set_fd(t_dlst *iolst)
{
	int	status;

	status  = SUCESS;
	while (iolst)
	{
		status = open_file(iolst, GET_IOTYPE(iolst));
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

int	set_last(t_dlst *iolst, enum e_word_type one, enum e_word_type two)
{
	int	last;
	enum e_word_type	type;

	last = -1;
	while (iolst)
	{
		type = GET_IOTYPE(iolst);
		if (type == one || type == two)
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
	{
		close_fd(iolst);
		return (FAIL);
	}
	if (set_fd(iolst) == FAIL)
	{
		close_fd(iolst);
		return (FAIL);
	}
	cmd->infile = set_last(iolst, W_HERE_DOC, W_REDIRECTION_INPUT);
	cmd->outfile = set_last(iolst, W_APPENDING_TO, W_REDIRECTION_OUTPUT);
	return (SUCESS);
}
