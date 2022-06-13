/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/13 10:19:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

void	parser(t_data *data)
{
	t_dlst	*lexer_t_lst;
	t_lexer_token	*lexer_token;

	lexer_t_lst = data->lexer_token_lst;
	while (lexer_t_lst)
	{
		lexer_token = lexer_t_lst->content;
		ft_printf("type : %d, string %s\n", lexer_token->w_type, lexer_token->buffer);
		lexer_t_lst = lexer_t_lst->next;
	}
	t_dlst	*word_lst;

	word_lst = NULL;
	get_word_lst(&word_lst, data->lexer_token_lst);
}
