/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:12:48 by myukang           #+#    #+#             */
/*   Updated: 2022/06/13 11:19:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



/*
 * used -> token lst에서 문장을 만드는데에 사용한 토큰개수
 * */

int	is_special_token(enum e_word_type type)
{
	if (type >= W_PIPE && type <= 10)
		return (1);
	return (0);
}

char	*make_stoken_char(enum e_word_type type)
{
	if (type == W_PIPE)
		return (ft_strdup("|"));
	else if (type == W_HERE_DOC)
		return (ft_strdup("<<"));
	else if (type == W_APPENDING_TO)
		return (ft_strdup(">>"));
	else if (type == W_REDIRECTION_INPUT)
		return (ft_strdup("<"));
	else 
		return (ft_strdup(">"));
}

int	make_word(t_dlst **word_lst, t_dlst *lexer_t_lst)
{
	enum e_word_type	type;

	type = GET_TOKEN_TYPE(lexer_t_lst);
	if (!lexer_t_lst)
		return (0);
	if (is_special_token(type))
	{
		ft_dlst_pushback(word_lst, ft_dlst_new(make_stoken_char(type)));
		return (1);
	}
	return (0);
}

void	get_word_lst(t_dlst **word_lst, t_dlst *lexer_t_lst)
{
	int	used;

	if (!lexer_t_lst)
		return ;
	while (lexer_t_lst)
	{
		if (GET_TOKEN_TYPE(lexer_t_lst) == W_SPACE)
		{
			lexer_t_lst = lexer_t_lst->next;
			continue ;
		}
		used = make_word(word_lst, lexer_t_lst);
		while (used)
		{
			lexer_t_lst = lexer_t_lst->next;
			used--;
		}
	}
}
