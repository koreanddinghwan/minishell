/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:04:44 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 20:07:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_next_token(t_dlst *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) == W_SPACE)
		{
			lst = lst->next;
			continue;
		}
		else if (GET_TOKEN_TYPE(lst) >= 6)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

void	do_change(int i, t_dlst	**cur)
{
	t_dlst	*lst;

	while (i)
	{
		lst = *cur;
		if (GET_TOKEN_TYPE(lst) == W_SPACE)
		{
			*cur = (*cur)->next;
			continue ;
		}
		else
		{
			GET_TOKEN_TYPE(lst) = W_ARG;
			*cur = (*cur)->next;
			i--;
		}
	}

}

void	convert_to_arg(t_dlst *lst)
{
	enum e_word_type	type;
	int					i;

	while (lst)
	{
		i = 0;
		type = GET_TOKEN_TYPE(lst);
		if (type == W_COMMAND || type == W_BUILTIN)
		{
			lst = lst->next;
			if (lst)
			{
				i = get_next_token(lst);
				do_change(i, &lst);
			}
		}
		if (!lst)
			break ;
		lst = lst->next;
	}
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
		/*
		if (type == 7)
			GET_TOKEN_TYPE(lst) = W_DELIMETER;
		else if (type >= 8 && type <= 10)
			GET_TOKEN_TYPE(lst) = W_FILE;
			*/
		while (lst && GET_TOKEN_TYPE(lst) != W_SPACE)
		{
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
