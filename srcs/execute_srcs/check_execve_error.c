/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:17:23 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 02:08:02 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <sys/stat.h>

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

void	check_execve_error(t_dlst *lst)
{
	struct stat	finfo;
	char		*cmd;
	int			rtn;

	cmd = (get_cmd_cont(lst))->cmd;
	rtn = stat(cmd, &finfo);
	if (exist_slash(cmd))
	{
		if (rtn == -1)
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd(": No such file or directory", 2);
			exit(127);
		}
		else if (isdir(finfo.st_mode))
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd(": is a directory", 2);
			exit(126);
		}
		else
		{
			ft_putstr_fd("mgyush: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd(": Permission denied", 2);
			exit(126);
		}
	}
	else
	{
		ft_putstr_fd("mgyush: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}
