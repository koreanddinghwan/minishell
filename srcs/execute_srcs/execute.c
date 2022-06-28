/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 03:50:05 by myukang          ###   ########.fr       */
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
	if (check_builtin(get_cmd(cmd)))
		execute_builtin(data, get_cmd(cmd), get_args(cmd));
	else
	{
		if (execve(get_cmd(cmd), get_args(cmd), data->env) == -1)
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
		execute_child(data, cmd, fd, &(*pipe_num));
}

void	close_pipe(int pipe, int *fd[2], int *status)
{
	while (pipe--)
	{
		close(fd[pipe][0]);
		close(fd[pipe][1]);
	}
	free(fd);
	while (wait(&(*status)) > 0)
		;
}

void	execute_cmd(t_data *data, t_dlst *cmd_lst, int *remain_pipe, int *fd[2])
{
	int	i;

	i = 0;
	while (cmd_lst)
	{
		if (!fork_builtin(get_cmd(cmd_lst))
			&& !data->pipe_exist && !get_io_list(cmd_lst))
			execute_builtin(data, get_cmd(cmd_lst), get_args(cmd_lst));
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
	int		**fd;
	int		status;
	int		i;

	cmd_lst = data->cmd_lst;
	remain_pipe = data->cmd_size - 1;
	fd = (int **)malloc(sizeof(int *) * (data->cmd_size - 1));
	i = 0;
	while (i < data->cmd_size - 1)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	if (!fd)
		return ;
	if (remain_pipe == 0)
		data->pipe_exist = 0;
	else
		data->pipe_exist = 1;
	if (make_heredoc(data) == FAIL)
		return ;
	execute_cmd(data, cmd_lst, &remain_pipe, fd);
	close_pipe(data->cmd_size - 1, fd, &status);
}
