/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:49 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 17:54:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_redirection_output(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_REDIRECTION_OUTPUT || GET_TOKEN_TYPE(tok_lst) == W_APPENDING_TO)
			return (1);
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (0);
		tok_lst = tok_lst->next;
	}
	return (0);
}

t_io_cont	*make_output_cont(t_data *data, t_dlst *tok_lst, enum e_word_type type)
{
	t_io_cont	*rtn;
	t_dlst		*cur;
	t_dlst		*next;
	int			offset;

	cur = tok_lst;
	rtn = NULL;
	offset = get_offset(cur, W_FILE);
	cur = wget_startpoint(cur, W_FILE);
	if (cur)
	{
		rtn = malloc(sizeof(t_io_cont) * 1);
		if (!rtn)
			return (NULL);
		rtn->filepath = wget_join(cur, W_FILE);
		rtn->type = type;
	}
	while (tok_lst && offset)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
		offset--;
	}
	return (rtn);
}

t_dlst	*make_output_lst(t_data *data)
{
	t_dlst		*rtn;
	t_dlst		*tok_lst;
	t_io_cont	*new;

	rtn = NULL;
	tok_lst = data->lexer_token_lst;
	while (check_redirection_output(tok_lst))
	{
		while (tok_lst && (GET_TOKEN_TYPE(tok_lst) != W_REDIRECTION_OUTPUT && GET_TOKEN_TYPE(tok_lst) != W_APPENDING_TO))
			tok_lst = tok_lst->next;
		if (tok_lst)
		{
			new = make_output_cont(data, tok_lst, GET_TOKEN_TYPE(tok_lst));
			if (new)
				ft_dlst_pushback(&rtn, ft_dlst_new(new));
			tok_lst = data->lexer_token_lst;
		}
	}
	return (rtn);
}
