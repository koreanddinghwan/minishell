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

/* 1.set_fork_builtin	pwd, echo, env
   2.execute_builtin	cd, exit, export, unset
						*/

int		builtin(char *cmd)
{
	if (check_builtin(cmd))
		return (1);
	return (0);
}

void	execute_builtin(t_data *data, char *cmd)
{
	printf("123\n");
	if (ft_strcmp(ENV, cmd) == 0)
		ft_env(data);
	// if (ft_strcmp(ECHO, str) == 0)
	// 	ft_echo();
	// if (ft_strcmp(CD, str) == 0)
	// 	ft_cd();
	// if (ft_strcmp(PWD, str) == 0)
	// 	ft_pwd();
	// if (ft_strcmp(EXPORT, str) == 0)
	// 	ft_export();
	// if (ft_strcmp(UNSET, str) == 0)
	// 	ft_unset();
	// if (ft_strcmp(EXIT, str) == 0)
	// 	ft_exit();
}

void	execute(t_data *data)
{
	t_dlst *cmdlst;
	cmdlst = data->cmd_lst;


	// // t_envlst	*lst;
	// char		*cmd;
	// t_dlst		*cmd_lst;

	// // lst = data->env_lst;
	// cmd = (char *)data->cmd_lst->content;
	// cmd_lst = data->cmd_lst;
	while(cmdlst)
	{
		printf("cmd: %s\n", (char *)cmdlst->content);
		cmdlst = cmdlst->next;
	}
	// if (builtin(cmd))
	// 	execute_builtin(data, cmd);

	// else if (!builtin(cmd))
	// 	execute_execve();





	// if (!strcmp(data->command, ENV))
	// {
	// 	while (lst)	//lst
	// 	{
	// 		printf("list: %s\n", (char*)lst->env_line);
	// 		lst = lst->next;
	// 	}
	// 	while (data->env[i])	//arr
	// 	{
	// 		printf("arr: %s\n", data->env[i]);
	// 		i++;
	// 	}
	// }
	// if (!strcmp(data->command, CD))
	// {
	// 	ft_cd(data, "~");
	// }
	// if (!strcmp(data->command, PWD))
	// {
	// 	ft_pwd();
	// }
	// /*
	// if (!strcmp(data->command, EXIT))
	// {
	// 	ft_exit(ac, av); // 수정: ac는 exit 이후의 av개수(파싱이후), 지금은 exit만 됌
	// }
	// */
	// if (!strcmp(data->command, EXPORT))
	// {
	// 	char **args = (char **)malloc(sizeof(char *) * 3);
	// 	args[0] = (char *)malloc(sizeof(char) * 10);
	// 	args[1] = (char *)malloc(sizeof(char) * 10);
	// 	args[2] = (char *)malloc(sizeof(char) * 10);
	// 	// args[0] = "key=value";
	// 	// args[1] = "value=key";
	// 	// args[0] = "key";
	// 	// args[1] = "value";
	// 	args[0] = "key=";
	// 	args[1] = "value=";
	// 	args[2] = 0;
	// 	ft_export(data, args);
	// }
	// if (!strcmp(data->command, UNSET))
	// {
	// 	char **args = (char **)malloc(sizeof(char *) * 3);
	// 	args[0] = (char *)malloc(sizeof(char) * 10);
	// 	args[1] = (char *)malloc(sizeof(char) * 10);
	// 	args[2] = (char *)malloc(sizeof(char) * 10);
	// 	args[0] = "key";
	// 	args[1] = "value";
	// 	args[2] = 0;
	// 	ft_unset(data, args);
	// }
	// if (!strcmp(data->command, ECHO))
	// {
	// 	int flag = 0; // no option
	// 	//flag = 1; // (-n) option
	// 	if (flag == 0)
	// 		ft_echo(data, flag, "HI");
	// 	else
	// 		ft_echo(data, flag, "-nnn HI");
	// }
}