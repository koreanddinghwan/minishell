/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 13:06:19 by myukang          ###   ########.fr       */
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

t_lexer_token	*lexer_space_token()
{
	t_lexer_token	*rtn;

	rtn = ft_calloc(sizeof(t_lexer_token), 1);
	rtn->buf_len = 1;
	rtn->buffer = ft_calloc(sizeof(char), 2);
	rtn->buffer[0] = ' ';
	rtn->buffer[1] = '\0';
	rtn->w_type = W_ARG;
	return (rtn);
}

void	lexer_token_lst_init(t_data *data)
{
	t_token			*tok_buf;
	t_lexer_token	*l_tok;
	int				i;
	int				space_add;

	tok_buf = data->tok_buf;
	space_add = 0;
	while (tok_buf->type != END_C)
	{
		if (tok_buf->type == SPC && space_add == 1)
		{
			tok_buf++;
			continue ;
		}
		else if (tok_buf->type == SPC && space_add == 0)
		{
			l_tok = lexer_space_token();
			ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
			tok_buf++;
			space_add = 1;
			continue ;
		}
		space_add = 0;
		i = 0;
		l_tok = lexer_token_init(tok_buf);
		ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
		if (l_tok->buf_len == 0)
			return ;
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
