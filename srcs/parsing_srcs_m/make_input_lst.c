/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_input_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:34:10 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 19:39:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_redirection_input(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_REDIRECTION_INPUT)
			return (1);
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (0);
		tok_lst = tok_lst->next;
	}
	return (0);
}

t_io_cont	*make_input_cont(t_data *data, t_dlst *tok_lst)
{
	t_io_cont	*rtn;
	t_dlst		*cur;
	t_dlst	*next;
	int			cur_n;
	int			delete_n;

	cur = tok_lst;
	if (!cur->next)
		return (NULL);
	rtn = malloc(sizeof(t_io_cont) * 1);
	if (!rtn)
		return (NULL);
	cur_n = GET_TOKEN_NTH(cur);
	while (cur && GET_TOKEN_TYPE(cur) != W_FILE)
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

t_dlst	*make_input_lst(t_data *data)
{
	t_dlst	*rtn;
	t_dlst	*tok_lst;

	rtn = NULL;
	tok_lst = data->lexer_token_lst;
	while (check_redirection_input(tok_lst))
	{
		while (GET_TOKEN_TYPE(tok_lst) != W_REDIRECTION_INPUT)
			tok_lst = tok_lst->next;
		ft_dlst_pushback(&rtn, ft_dlst_new(make_input_cont(data, tok_lst)));
		tok_lst = data->lexer_token_lst;
	}
	ft_printf("input lst\n");
	print_input_lst(rtn);
	return (rtn);
}
