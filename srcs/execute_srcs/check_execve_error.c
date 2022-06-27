/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:17:23 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 02:55:15 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <sys/stat.h>

int	exist_slash(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (FALSE);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	print_exec_error(char *str, char *cmd, int exit_status)
{
	ft_putstr_fd("mgyush: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(str, 2);
	exit(exit_status);
}

void	check_execve_error(t_dlst *lst)
{
	struct stat	finfo;
	char		*cmd;
	int			rtn;

	cmd = (get_cmd_cont(lst))->cmd;
	if (!cmd)
		return ;
	rtn = stat(cmd, &finfo);
	if (exist_slash(cmd))
	{
		if (rtn == -1)
			print_exec_error(NOFILE, cmd, 127);
		else if (isdir(finfo.st_mode))
			print_exec_error(ISDIR, cmd, 126);
		else
			print_exec_error(DENY, cmd, 126);
	}
	else
		print_exec_error(CMDNOTFOUND, cmd, 127);
}
