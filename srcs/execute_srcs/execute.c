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
#include <sys/wait.h>
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

	if (ft_strcmp(ENV, cmd) == 0)
		ft_env(data);
}

// void	execute_redirect(t_data *data)
// {
// 	while (com_redic--)	// 한 프로세스 안에 기호 갯수
// 	{
// 		if (input_re)
// 			input_redirection();
// 		else if (output_re)
// 			output_redirection();
// 		else if (append_re)
// 			append_redirection();
// 		else
// 			here_document();
// 	}
// }

void	execute_child(t_data *data, t_dlst *cmd, t_dlst *next_cmd, int fd[2], int *pipe_num, int pipe_exist)
{
	int status = 0;
	char *ag[] = {GET_CMD(cmd), NULL};

	(void) pipe_exist;
	if (*pipe_num > 0 || *pipe_num == 0)
	{
		printf("dup2(OUT)\n");
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
	}
	if (builtin(GET_CMD(cmd)))
		execute_builtin(data, GET_CMD(cmd), GET_ARGS(cmd));
	else
	{
		if (!strcmp(GET_CMD(cmd), "ls"))
			status = execve("/bin/ls", ag, data->env);
		else
			status = execve("/usr/bin/wc", ag, data->env);
	}
	if (status == -1)
		printf("command not found\n");
	(void) next_cmd;
	exit(status);
}

void execute_pipe(t_data *data, t_dlst *cmd, t_dlst *next_cmd, int *pipe_num, int fd[2], int pipe_exist)
{
	pid_t pid;
	int	status;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		execute_child(data, cmd, next_cmd, fd, &(*pipe_num), pipe_exist);
	}
	printf("pipe_num = %d\n", *pipe_num);
	if (*pipe_num > 0)
	{
		printf("입력한 커맨드가 이거? %s\n", GET_CMD(cmd));
		printf("dup2(IN)\n");
		// close(fd[1]);
		dup2(fd[0], STDIN_FILENO);			// 현재 프로세스의 STDIN을 fd[0]으로 설정
	}
	// waitpid(pid, &status, 0);
	printf("%d %d\n", fd[0], fd[1]);
	while (wait(&status) > 0);
}

void	execute(t_data *data)
{
	t_dlst *cmd_lst;
	t_dlst	*next_cmd_lst;
	int fd[2];
	// t_dlst *out_re;
	// t_dlst *input_re;

	cmd_lst = data->cmd_lst;
	next_cmd_lst = data->cmd_lst->next;

	char *cmd = GET_CMD(cmd_lst);
	char **args = GET_ARGS(cmd_lst);
	// out_re = GET_OUTPUT_LIST(cmd_lst);

	int pipe_exist = 1; // 파이프 존재
	int next_pipe = 1;	// 파이프 갯수
	// int redirc = 0;
	while (cmd_lst)
	{
		// if (redirc)			// 리다이렉션이 있으면
		// {
		// 	execute_redirect(data);			// 리다이렉션 처리
		// 	break;
		// }
		if (builtin(cmd) && next_pipe == 0)		// 빌트인함수이고 파이프가 없으면
		{
			printf("단일커맨드\n");
			execute_builtin(data, cmd, args);	// 단일커맨드
		}
		else
		{
			if (next_pipe > 0)
			{
				pipe(fd);
				printf("파이프 뚫음\n");
			}
			printf("[-------START--------]\n");
			execute_pipe(data, cmd_lst, next_cmd_lst, &next_pipe, fd, pipe_exist);		// 파이프처리
			printf("[--------END---------]\n");
		}
		// if (next_pipe > 0)
		// {
		// 	printf("close: fd[1]\n");
		// 	close(fd[1]);
		// }
		// else
		// {
		// 	printf("close: fd[0]\n");
		// 	close(fd[0]);
		// }
		cmd_lst = cmd_lst->next;
		if (next_cmd_lst)
		{
			if (next_cmd_lst->next && next_cmd_lst)
			{
				next_cmd_lst = next_cmd_lst->next;
			}
		}
		next_pipe--;
	}
}