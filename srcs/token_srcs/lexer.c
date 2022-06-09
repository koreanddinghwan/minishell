/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 22:04:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*tmp*/
void	lexer_token_printer(t_data *data)
{
	while (data->lexer_token_lst)
	{
		printf("type : %d\n", ((t_lexer_token *)data->lexer_token_lst->content)->w_type);
		printf("%s\n", ((t_lexer_token *)data->lexer_token_lst->content)->buffer);
		data->lexer_token_lst = data->lexer_token_lst->next;
	}
}

void	lexer_token_lst_init(t_data *data)
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
}

void	lexer(t_data *data)
{
	lexer_token_lst_init(data);
	lexer_w_converter(data);
	lexer_token_printer(data);
}
