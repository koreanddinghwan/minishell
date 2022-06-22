/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 01:13:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
/* 1.set_fork_builtin	pwd, echo, env
   2.execute_builtin	cd, exit, export, unset
						*/

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
	int status;

	// char *ag[]={"/usr/bin", NULL};
	fd = open(target, O_CREAT | O_RDWR | O_TRUNC , 0644);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (fd < 0)
		{
			printf("%s\n", strerror(errno));
			return (-1);
		}
		printf("[cat > text.txt] start!\nStop: ctrl+c\n");
		dup2(fd, STDOUT_FILENO);
		ft_env(data);
		// printf("%d\n", execve("usr/bin/env", ag, envp));
		printf("%s\n", strerror(errno));
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		printf("status: %d\n", status);
		close(fd);
	}
	return (1);
}

// int	input_redirection(char *command, char *target, char **envp) // ex) cat < test.txt
// {
// 	int	fd;
// 	// char **ag;
// 	pid_t	pid;
// 	int		status;

// 	// ag = (char **)malloc(sizeof(char *) * 2);
// 	// ag[0] = "-e";
// 	fd = open(target, O_RDONLY);
// 	pid = fork();
// 	if (pid < 0)
// 		exit(1);
// 	if (fd < 0)
// 		return (-1);
// 	if (pid == 0)
// 	{
// 		dup2(fd, STDIN_FILENO);

// 		// execve(command, ag, envp);
// 	}
// 	else
// 	{
// 		close(fd);
// 		waitpid(pid, &status, 0);
// 		printf("부모 종료 %d %d %d\n", pid, WIFEXITED(status), WEXITSTATUS(status)); // 1, 0(자식)
// 	}
// 	return (1);
// }

void	execute_builtin(t_data *data, char *cmd, char **args)
{
	if (ft_strcmp(PWD, cmd) == 0)
		ft_pwd();
	if (ft_strcmp(EXPORT, cmd) == 0)
		ft_export(data, args);
	if (ft_strcmp(UNSET, cmd) == 0)
		ft_unset(data, args);
	// if (ft_strcmp(ECHO, str) == 0)
	// 	ft_echo();
	if (ft_strcmp(CD, cmd) == 0)
		ft_cd(data, args);
	// if (ft_strcmp(EXIT, str) == 0)
	// 	ft_exit();
	t_dlst *cmd_list;
	t_dlst *out_re;
	// t_dlst *input_re;
	
	cmd_list = data->cmd_lst;

	out_re = GET_OUTPUT_LIST(cmd_list);
	// input_re = GET_INPUT_LIST(cmd_list);
	if (out_re)
	{
		output_redirection(data, cmd, GET_FILEPATH(out_re), args, data->env);
	}
	// if (input_re)
	// {
	// 	input_redirection();
	// }

	if (ft_strcmp(ENV, cmd) == 0)
		ft_env(data);
}

void	set_pipe(int pipefd[2], t_data *data, char **args)
{
	pid_t pid;

	pid = fork();
	if (pipe(pipefd) == -1)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	// if (no_builtin)
	// {
		if (pid == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			ft_cd(data, args);
			close(pipefd[0]);
		}
		else
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			ft_env(data);
			close(pipefd[1]);
		}
	// }
	// dup2(pipefd[1], STDOUT_FILENO);
}

void	execute(t_data *data)
{
	t_dlst *cmd_lst;
	cmd_lst = data->cmd_lst;
	int pipefd[2];

	// char *cmd = GET_CMD(cmd_lst);
	char **args = GET_ARGS(cmd_lst);
	// if (파이프X)
	// {
	// 	단일커맨드 처리
	// }
	// else (파이프O)
	// {
		set_pipe(pipefd, data, args);
		printf("pipefd: %d, %d\n", pipefd[0], pipefd[1]);
		// if (builtin(cmd))
		// 	execute_builtin(data, cmd, args);
	// }

	// else if (!builtin(commd))
	// 	execute_execve();
	cmd_lst = cmd_lst->next;
	data->cmd_lst = data->cmd_lst->next;
}
// no_builtin()
// {
// 	pid_t pid;
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (pipe_exist)
// 			execute_pipe();
// 		else
// 			execve();
// 		exit($?);
// 	}
// 	else
// 	{
// 		waitpid();
// 		close(fd);
// 	}
// }

<<<<<<< HEAD
// example()
// {
// 	if (builtin)
// 		builtin_redirect_function();
// 	else
// 		no_builtin();
// }

=======
// no_builtin()
// {
// 	pid_t pid;
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (pipe_exist)
// 			execute_pipe();
// 		else
// 			execve();
// 		exit($?);
// 	}
// 	else
// 	{
// 		waitpid();
// 		close(fd);
// 	}
// }

// example()
// {
// 		if (builtin)
// 			builtin_redirect_function();
// 		else
// 			no_builtin();
// }

>>>>>>> 3a8b1e7 ("FEAT: X")
// echo 123 > test.txt | cat test.txt
// builtin_redirect_function()
// pipe_exist()
// no_builtin()
// fork()
