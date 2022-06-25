/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:06:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 17:56:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_heredoc(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_HERE_DOC)
			return (1);
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (0);
		tok_lst = tok_lst->next;
	}
	return (0);
}

t_heredoc_cont	*make_heredoc_cont(t_data *data, t_dlst *tok_lst)
{
	t_heredoc_cont	*rtn;
	t_dlst			*cur;
	t_dlst			*next;
	int				offset;

	cur = tok_lst;
	rtn = NULL;
	offset = get_offset(cur, W_DELIMETER);
	cur = wget_startpoint(cur, W_DELIMETER);
	if (cur)
	{
		rtn = malloc(sizeof(t_heredoc_cont) * 1);
		if (!rtn)
			return (NULL);
		rtn->delimeter = wget_join(cur, W_DELIMETER);
	}
	while (tok_lst && offset + 1)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &(data->lexer_token_lst), lexer_tok_free);
		tok_lst = next;
		offset--;
	}
	return (rtn);
}

t_dlst	*make_heredoc_lst(t_data *data)
{
	t_dlst			*rtn;
	t_dlst			*tok_lst;
	t_heredoc_cont	*new;

	rtn = NULL;
	tok_lst = data->lexer_token_lst;
	while (check_heredoc(tok_lst))
	{
		while (GET_TOKEN_TYPE(tok_lst) != W_HERE_DOC)
			tok_lst = tok_lst->next;
		if (tok_lst)
		{
			new = make_heredoc_cont(data, tok_lst);
			if (new)
				ft_dlst_pushback(&rtn, ft_dlst_new(new));
			tok_lst = data->lexer_token_lst;
		}
	}
	return (rtn);
}
