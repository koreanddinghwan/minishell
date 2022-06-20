/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:08:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 15:37:45 by myukang          ###   ########.fr       */
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
