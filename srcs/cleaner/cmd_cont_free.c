/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cont_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 20:58:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"


void	fnc_free_filepath(void *cont)
{
	t_io_cont	*content;

	content = cont;
	if (content->filepath)
		free(content->filepath);
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
