/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cont_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 19:00:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	fnc_free_deli(void *cont)
{
	t_heredoc_cont	*content;

	content = cont;
	if (content->delimeter)
		free(content->delimeter);
}

void	free_deli(t_cmd_cont *content)
{
	ft_dlst_clear(&(content->heredoc_lst), fnc_free_deli);
}

void	fnc_free_filepath(void *cont)
{
	t_io_cont	*content;

	content = cont;
	if (content->filepath)
		free(content->filepath);
}

void	free_path(t_cmd_cont *content)
{
	ft_dlst_clear(&(content->input_lst), fnc_free_filepath);
	ft_dlst_clear(&(content->output_lst), fnc_free_filepath);
	ft_dlst_clear(&(content->append_lst), fnc_free_filepath);
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
	free_deli(content);
}
