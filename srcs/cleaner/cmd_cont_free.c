/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cont_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 17:23:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	fnc_free_deli(void *param)
{
	t_dlst	*lst;

	lst = (t_dlst *)param;
	if (GET_DELIMETER(lst))
		free(GET_DELIMETER(lst));
}

void	free_deli(t_dlst *cmdlst)
{
	ft_dlst_clear(&(GET_HEREDOC_LIST(cmdlst)), fnc_free_deli);
}

void	fnc_free_filepath(void *param)
{
	t_dlst	*lst;

	lst = (t_dlst *)param;
	if (GET_FILEPATH(lst))
		free(GET_FILEPATH(lst));
}

void	free_path(t_dlst *cmdlst)
{
	ft_dlst_clear(&(GET_INPUT_LIST(cmdlst)), fnc_free_filepath);
	ft_dlst_clear(&(GET_OUTPUT_LIST(cmdlst)), fnc_free_filepath);
	ft_dlst_clear(&(GET_APP_LIST(cmdlst)), fnc_free_filepath);
}

void	cmd_cont_free(void *param)
{
	t_dlst	*cmd_lst;
	char	**args;

	cmd_lst = (t_dlst *)param;
	if (!cmd_lst)
		return ;
	if (GET_CMD(cmd_lst))
		free(GET_CMD(cmd_lst));
	args = GET_ARGS(cmd_lst);
	if (args)
	{
		while (*args)
		{
			free(*args);
			args++;
		}
		free(args);
	}
	free_path(cmd_lst);
	free_deli(cmd_lst);
}
