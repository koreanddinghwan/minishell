/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 17:37:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void	execute_child(t_data *data, t_dlst *cmd, int *fd[2], int *pipe_num)
{
	int	status;
	int	infile;
	int	outfile;
	int	i;

	status = 0;
	infile = ((t_cmd_cont *)cmd->content)->infile;
	outfile = ((t_cmd_cont *)cmd->content)->outfile;
	i = 0;
	execute_dup2(data, i, fd, *pipe_num);
	if (set_redir(cmd->content, data) == FAIL)
		exit(1);
	if (infile != -1)
		dup2(infile, STDIN_FILENO);
	if (outfile != -1)
		dup2(outfile, STDOUT_FILENO);
	if (check_builtin(GET_CMD(cmd)))
		execute_builtin(data, GET_CMD(cmd), GET_ARGS(cmd));
	else
	{
		if (execve(GET_CMD(cmd), GET_ARGS(cmd), data->env) == -1)
			check_execve_error(cmd);
	}
	exit(status);
}

void	execute_pipe(t_data *data, t_dlst *cmd, int *pipe_num, int *fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		execute_child(data, cmd, fd, &(*pipe_num));
	}
}

void	close_pipe(t_data *data, int pipe, int fd[][2], int *status)
{
	while (pipe--)
	{
		close(fd[pipe][0]);
		close(fd[pipe][1]);
	}
	while (wait(status) > 0)
		change_exitstatus(data, *status);
}

void	execute_cmd(t_data *data, t_dlst *cmd_lst, int *remain_pipe, int *fd[2])
{
	int	i;

	i = 0;
	while (cmd_lst)
	{
		if (!fork_builtin(GET_CMD(cmd_lst))
			&& !data->pipe_exist && !GET_IO_LIST(cmd_lst))
			execute_builtin(data, GET_CMD(cmd_lst), GET_ARGS(cmd_lst));
		else
		{
			if (*remain_pipe == data->cmd_size - 1)
			{
				while (data->cmd_size - 1)
				{
					pipe(fd[i]);
					if (data->cmd_size - 2 == i)
						break ;
					i++;
				}
			}
			execute_pipe(data, cmd_lst, &(*remain_pipe), fd);
		}
		cmd_lst = cmd_lst->next;
		(*remain_pipe)--;
	}
}

void	execute(t_data *data)
{
	t_dlst	*cmd_lst;
	int		remain_pipe;
	int		*fd[2];
	int		status;

	cmd_lst = data->cmd_lst;
	remain_pipe = data->cmd_size - 1;
	*fd = ft_calloc(sizeof(int *), data->cmd_size - 1);
	*(fd + 1) = ft_calloc(sizeof(int *), data->cmd_size - 1);
	if (!(*fd) || !(*(fd + 1)))
		return ;
	if (remain_pipe == 0)
		data->pipe_exist = 0;
	else
		data->pipe_exist = 1;
	if (make_heredoc(data) == FAIL)
		return ;
	execute_cmd(data, cmd_lst, &remain_pipe, fd);
	close_pipe(data, remain_pipe + 1, fd, &status);
}
