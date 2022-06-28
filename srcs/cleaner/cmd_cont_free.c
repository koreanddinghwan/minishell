/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cont_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 15:12:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	fnc_free_filepath(void *cont)
{
	t_io_cont	*content;

	content = cont;
	if (content->filepath)
		free(content->filepath);
	if (content->tmpname)
	{
		unlink(content->tmpname);
		free(content->tmpname);
	}
	if (content->fd != -1)
	{
		close(content->fd);
		content->fd = -1;
	}
}

void	free_path(t_cmd_cont *content)
{
	ft_dlst_clear(&(content->iolst), fnc_free_filepath);
}

void	cmd_cont_free(void *cont)
{
	char		**args;
	t_cmd_cont	*content;

	if (!cont)
		return ;
	content = cont;
	if (content->cmd)
		free(content->cmd);
	args = content->args;
	if (args)
	{
		while (*args)
		{
			free(*args);
			args++;
		}
	}
	free_path(content);
}
