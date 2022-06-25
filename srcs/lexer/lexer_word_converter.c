/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:04:44 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 17:46:55 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	convert_to_arg(t_dlst *lst)
{
	while (lst && GET_TOKEN_TYPE(lst) == W_SPACE)
		lst = lst->next;
	while (lst && GET_TOKEN_TYPE(lst) == W_COMMAND)
		lst = lst->next;
	while (lst && (GET_TOKEN_TYPE(lst) != W_PIPE))
	{
		if (GET_TOKEN_TYPE(lst) == W_SPACE || (GET_TOKEN_TYPE(lst) >= 7 && GET_TOKEN_TYPE(lst) <= 10))
		{
			lst = lst->next;
			continue ;
		}
		else
		{
			GET_TOKEN_TYPE(lst) = W_ARG;
			lst = lst->next;
		}
	}
	if (lst && GET_TOKEN_TYPE(lst) == W_PIPE)
		lst = lst->next;
	if (lst)
		convert_to_arg(lst);
}

void	do_change_file_deli(t_dlst *lst)
{
	enum e_word_type	type;

	type = GET_TOKEN_TYPE(lst);
	if (lst->next)
		lst = lst->next;
	else
		return ;
	while (lst && GET_TOKEN_TYPE(lst) == W_SPACE)
		lst = lst->next;
	if (lst)
	{
		while (lst && GET_TOKEN_TYPE(lst) != W_SPACE)
		{
			if (GET_TOKEN_TYPE(lst) >= 6)
				return ;
			if (type == 7)
				GET_TOKEN_TYPE(lst) = W_DELIMETER;
			else if (type >= 8 && type <= 10)
				GET_TOKEN_TYPE(lst) = W_FILE;
			lst = lst->next;
		}
	}
}

void	convert_file_delimeter(t_dlst *lst)
{
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) >= 7 && GET_TOKEN_TYPE(lst) <= 10)
			do_change_file_deli(lst);
		lst = lst->next;
	}
}

void	lexer_w_converter(t_data *data)
{
	t_dlst	*lst;

	lst = data->lexer_token_lst;
	convert_to_arg(lst);
	convert_file_delimeter(lst);
}
