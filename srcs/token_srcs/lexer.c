/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 19:23:19 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer(t_data *data)
{
	t_token			*tok_buf;
	t_lexer_token	*l_tok;
	int				i;

	tok_buf = data->tok_buf;
	while (tok_buf->type != END_C)
	{
		if (tok_buf->type == SPC)
		{
			tok_buf++;
			continue;
		}
		i = 0;
		l_tok = lexer_token_init(tok_buf);
		ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
		while (i < l_tok->buf_len && tok_buf->type != END_C)
		{
			tok_buf++;
			i++;
		}
	}
	while (data->lexer_token_lst)
	{
		printf("%s\n", ((t_lexer_token *)data->lexer_token_lst->content)->buffer);
		data->lexer_token_lst = data->lexer_token_lst->next;
	}
}
