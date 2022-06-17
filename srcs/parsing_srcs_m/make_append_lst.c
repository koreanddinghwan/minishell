/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_append_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:40:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 17:47:14 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_append(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_APPENDING_TO)
			return (1);
		tok_lst = tok_lst->next;
	}
	return (0);
}

t_io_cont	*make_append_cont(t_data *data, t_dlst *tok_lst)
{
	t_io_cont	*rtn;
	t_dlst		*cur;
	t_dlst		*next;
	int			cur_n;
	int			delete_n;

	cur = tok_lst;
	if (!cur->next)
		return (NULL);
	rtn = malloc(sizeof(t_io_cont) * 1);
	if (!rtn)
		return (NULL);
	cur_n = GET_TOKEN_NTH(cur);
	while (GET_TOKEN_TYPE(cur) != W_FILE)
		cur = cur->next;
	rtn->filepath = ft_strdup(GET_TOKEN_BUFFER(cur));
	delete_n = GET_TOKEN_NTH(cur);
	while (cur_n <= delete_n)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		cur_n++;
		tok_lst = next;
	}
	return (rtn);
}

t_dlst	*make_append_lst(t_data *data)
{
	t_dlst	*rtn;
	t_dlst	*tok_lst;

	rtn = NULL;
	tok_lst = data->lexer_token_lst;
	while (check_append(tok_lst))
	{
		while (GET_TOKEN_TYPE(tok_lst) != W_APPENDING_TO)
			tok_lst = tok_lst->next;
		ft_dlst_pushback(&rtn, ft_dlst_new(make_append_cont(data, tok_lst)));
		tok_lst = data->lexer_token_lst;
	}
	ft_printf("appending lst\n");
	print_input_lst(rtn);
	return (rtn);
}
