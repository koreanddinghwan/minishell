/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:41:04 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 01:41:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exist_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	check_execve_error(t_dlst *cmd)
{
	int			rtn;
	struct stat	finfo;
	char		*cmd;
	int			rtn;

	cmd = (get_cmd_cont(cmd))->cmd;
	rtn = stat(cmd, &finfo);
	if (exist_slash(cmd))
	{
		if (isdir(finfo.st_mode))
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(GET_CMD(cmd), 2);
			ft_putendl_fd(": No such file or directory", 2);
			exit(127);
		}
		else
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(GET_CMD(cmd), 2);
			ft_putendl_fd(": is a directory", 2);
			exit(126);
		}
	}
	else
	{
		if (!isexec(finfo.st_mode))
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(GET_CMD(cmd), 2);
			ft_putendl_fd(": Permission denied", 2);
			exit(126);
		}
		else
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(GET_CMD(cmd), 2);
			ft_putendl_fd(": command not found", 2);
			exit(127);
		}
	}
}
