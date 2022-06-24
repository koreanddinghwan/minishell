/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:43:02 by myukang           #+#    #+#             */
/*   Updated: 2022/06/24 23:43:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_status.h"

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

int	file_status(t_data *data, char *file)
{
	struct stat	finfo;

	if (stat(file, &finfo) < 0)
		return (0);
	if (S_ISDIR(finfo.st_mode))
		return (FS_EXISTS);
	else
	{
		
	}
}
