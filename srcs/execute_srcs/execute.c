/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 03:48:12 by myukang          ###   ########.fr       */
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
/* 1.set_fork_builtin	pwd, echo, env
   2.execute_builtin	cd, exit, export, unset
						*/

int		redirc(t_dlst *cmd_lst)
{
	// t_dlst *red;

	// red = GET_IO_LIST(cmd_lst);
	if (GET_IO_LIST(cmd_lst))
		return (1);
	return (0);
}

int		builtin(char *cmd)
{
	if (check_builtin(cmd))
		return (1);
	return (0);
}

int output_redirection(t_data *data, char *command, char *target, char **args, char **envp)
{
	// (void) data;
	(void) envp;
	(void) args;
	(void) command;
	int fd;
	pid_t pid;

	// char *ag[]={"/usr/bin", NULL};
	fd = open(target, O_CREAT | O_RDWR | O_TRUNC , 0644);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (fd < 0)
		return (-1);
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		ft_env(data);
		// printf("%d\n", execve("usr/bin/env", ag, envp));
		printf("%s\n", strerror(errno));
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd);
	}
	return (1);
}

void	execute_builtin(t_data *data, char *cmd, char **args)
{
	if (ft_strcmp(PWD, cmd) == 0)
		ft_pwd();
	if (ft_strcmp(EXPORT, cmd) == 0)
		ft_export(data, args);
	if (ft_strcmp(UNSET, cmd) == 0)
		ft_unset(data, args);
	if (ft_strcmp(ECHO, cmd) == 0)
	 	ft_echo(data, args);
	if (ft_strcmp(CD, cmd) == 0)
		ft_cd(data, args);
	// if (ft_strcmp(EXIT, str) == 0)
	// 	ft_exit();
	if (ft_strcmp(ENV, cmd) == 0)
		ft_env(data);
}

void	execute_child(t_data *data, t_dlst *cmd, int fd[][2], int *pipe_num, int pipe_exist)
{
	char **ag = GET_ARGS(cmd);
	int status = 0;
	int pipes = data->cmd_size - 1;	// 파이프 개수
	int i;
	if (*pipe_num == pipes)
	{
		i = pipes;
		while (i--)
		{
			if (i != 0 && pipes >= 2)
				close(fd[i][1]);
			close(fd[i][0]);
		}
		if(pipe_exist)
			dup2(fd[0][1], STDOUT_FILENO);
	}
	else if (*pipe_num == 0)
	{
		i = pipes;
		while (i--)
		{
			if (i != (pipes-1) && pipes >= 2)
				close(fd[i][0]);
			close(fd[i][1]);
		}
		dup2(fd[pipes-1][0], STDIN_FILENO);
	}
	else
	{
		i = pipes;
		while (i--)
		{
			if (i != pipes-(*pipe_num))
				close(fd[i][1]);
			if (i != pipes-(*pipe_num)-1)
				close(fd[i][0]);
		}
		dup2(fd[pipes-(*pipe_num)-1][0], STDIN_FILENO);
		dup2(fd[pipes-(*pipe_num)][1], STDOUT_FILENO);
	}
	set_redir(cmd->content, data);
	if (builtin(GET_CMD(cmd)))
	{
		execute_builtin(data, GET_CMD(cmd), GET_ARGS(cmd));
	}
	else
	{
		// 커맨드 에러처리
		status = execve(GET_CMD(cmd), ag, data->env);
	}
	if (status == -1)
		printf("command not found\n");
	exit(status);
}

void execute_pipe(t_data *data, t_dlst *cmd, int *pipe_num, int fd[][2], int pipe_exist)
{
	pid_t pid;

	printf("입력한 커맨드가 이거? %s\n", GET_CMD(cmd));
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		execute_child(data, cmd, fd, &(*pipe_num), pipe_exist);
	}
}

void	execute(t_data *data)
{
	t_dlst *cmd_lst;

	cmd_lst = data->cmd_lst;

	char *cmd = GET_CMD(cmd_lst);
	char **args = GET_ARGS(cmd_lst);

	int pipe_exist; // 파이프 존재
	int remain_pipe;	// 남은 파이프 갯수
	remain_pipe = data->cmd_size - 1;
	int s = remain_pipe;
	if (remain_pipe == 0)
		pipe_exist = 0;
	else
		pipe_exist = 1;
	int fd[remain_pipe][2];
	
	int i = 0;
	while (cmd_lst)
	{
		if (builtin(cmd) && !pipe_exist)			// 빌트인함수이고 파이프가 없으면
		{
			if (strcmp(cmd, EXIT) || strcmp(cmd, UNSET) || strcmp(cmd, EXPORT) || strcmp(cmd, CD))
				execute_builtin(data, cmd, args);		// 단일커맨드
		}
		else
		{
			if (remain_pipe == s)
			{
				while(s)
				{
					pipe(fd[i]);
					printf("###[%d:파이프] 개방###\n", i);
					if (s-1 == i)
					{
						break;
					}
					i++;
				}
			}
			execute_pipe(data, cmd_lst, &remain_pipe, fd, pipe_exist);
		}
		cmd_lst = cmd_lst->next;
		remain_pipe--;
	}
		while(s--)
		{
			close(fd[s][0]);
			close(fd[s][1]);
		}
		int status;
		while(wait(&status) > 0);
}