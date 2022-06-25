/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:08:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 17:51:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmp.h"

void	print_token_lst(t_data *data)
{
	t_dlst	*tok_lst;

	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		printf("tok type : %d, buffer : %s\n", GET_TOKEN_TYPE(tok_lst), GET_TOKEN_BUFFER(tok_lst));
		tok_lst = tok_lst->next;
	}
}
