/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:42 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 18:16:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	lexer_tok_free(void *cur)
{
	t_dlst	*node;

	node = (t_dlst *)cur;
	free(GET_TOKEN_BUFFER(node));
	free(node);
}

void	token_free(t_data *data)
{
	if (data->tok_buf)
	{
		if (data->exit_status == EX_USAGE)
		{	
			free(data->tok_buf);
			data->tok_buf = NULL;
		}
	}
	if (data->command)
	{
		free(data->command);
		data->command = NULL;
	}
}

void	lexer_free(t_data *data)
{
	token_free(data);
	if (data->lexer_token_lst)
	{
		ft_dlst_clear(&data->lexer_token_lst, lexer_tok_free);
		data->lexer_token_lst = NULL;
	}
}

void	cmd_free(t_data *data)
{
	if (!data->cmd_lst)
		return ;
	ft_dlst_clear(&data->cmd_lst, cmd_cont_free);
}

void	cleaner(t_data *data)
{
	lexer_free(data);
	cmd_free(data);
	data->cmd_lst = NULL;
}
