/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:08:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 16:58:55 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmp.h"

void	print_token_lst(t_data *data)
{
	if (data)
		return ;
	/*
	while (data->token_lst)
	{
		printf("type : %d, value : %c\n", ((t_token *)(data->token_lst->content))->type, ((t_token *)(data->token_lst->content))->value);
		data->token_lst = data->token_lst->next;
	}*/
}

void	print_toks(t_token *tok_buf)
{
	while (tok_buf->c != 0)
	{
		printf("type : %d\n", tok_buf->type);
		printf("\'%c\'\n", tok_buf->c);
		tok_buf++;
	}
}
