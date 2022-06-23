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

	// if (ft_strcmp(ENV, cmd) == 0)
	// 	ft_env(data);
}

void	execute_redirect(t_data *data)
{
	while (com_redic--)	// 한 프로세스 안에 기호 갯수
	{
		if (input_re)
			input_redirection();
		else if (output_re)
			output_redirection();
		else if (append_re)
			append_redirection();
		else
			here_document();
	}
}

void	execute_child()
{
	int status;

	if (pipe_num == 1)							// 다음 파이프가 있으면		
	{
		dup2(next_cmd->fd[1], STDOUT_FILENO);	// 다음 프로세스의 STDOUT을 fd[1]로 설정
		close(next_cmd->fd[1]));
	}
	if (cmd->fd[0])								// 첫번째 프로세스가 아니라면 (cmd->fd[0] != 0)
	{
		dup2(cmd->fd[0], STDIN_FILENO);			// 현재 프로세스의 STDIN을 fd[0]으로 설정
		close(cmd->fd[0]);
	}
	if (builtin(cmd))
		execute_builtin(data, cmd, args);
	else
		(status = execve());
	if (status == -1)
		printf("command not found\n");
	exit(status);
}

int execute_pipe(t_data *data)
{
	// pid_t pid;
	// int status;
	t_dlst	*cmd;
	t_io_cont *node;
	char	*next_cmd;
	int	status;

	cmd = data->cmd_lst;
	node = data->cmd_lst->content;
	next_cmd = GET_CMD(cmd);
	if (pipe_num == 1)						// 다음 파이프가 있으면
	{
		cmd = data->cmd_lst->next;
		next_cmd = GET_CMD(cmd);
		pipe(node->fd);						// 다음 프로세스와 연결
	}
	pid = fork();
	if (pid == 0)
		execute_child();
	waitpid(pid, &status, 0);
	if (cmd->fd[0])							// 첫번째 프로세스가 아니면
		close(cmd->fd[0]);					// STDIN 닫음
	if (pipe_num == 1)						// 다음 파이프가 있으면
		close(node->fd[1]);					// STDOUT 닫음
	return (0);
}

void	execute(t_data *data)
{
	t_dlst *cmd_lst;
	// t_dlst *out_re;
	// t_dlst *input_re;

	cmd_lst = data->cmd_lst;

	char *cmd = GET_CMD(cmd_lst);
	char **args = GET_ARGS(cmd_lst);
	// out_re = GET_OUTPUT_LIST(cmd_lst);

	int pipe_num = 1;
	int redirc = 0;
	while (cmd_lst)
	{
		if (redirc)			// 리다이렉션이 있으면
		{
			// execute_redirect(data);			// 리다이렉션 처리
			break;
		}
		if (builtin(cmd) && pipe_num == 0)		// 빌트인함수이고 파이프가 없으면
			execute_builtin(data, cmd, args);	// 단일커맨드
		else
			execute_pipe(data);					// 파이프처리
		cmd_lst = cmd_lst->next;
		data->cmd_lst = data->cmd_lst->next;
		cmd = GET_CMD(cmd_lst);
	}
}