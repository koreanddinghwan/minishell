/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:46:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 15:35:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * io_error -> special token after io redirection token
 * */

#include "syntax_analyzer.h"

static int	is_io(t_dlst *lst)
{
	enum e_word_type	type;

	type = GET_TOKEN_TYPE(lst);
	if (type >= 7 && type <= 10)
		return (TRUE);
	else
		return (FALSE);
}

int	ioafter_io(t_dlst *lst)
{
	while (lst)
	{
		if (is_io(lst) == TRUE)
		{
			while (GET_TOKEN_TYPE(lst) == W_SPACE)
				lst = lst->next;
			if (lst && is_io(lst) == TRUE)
				return (TRUE);
		}
	}
	return (FALSE);
}

int	endwith_io(t_dlst *lst)
{
	t_dlst	*last;

	last = ft_dlst_last(lst);
	if (GET_TOKEN_TYPE(last) == W_SPACE)
	{
		while (GET_TOKEN_TYPE(last) == W_SPACE)
			last = last->back;
		if (is_io(last) == TRUE)
			return (TRUE);
	}
	else if (GET_TOKEN_TYPE(last) >= 7 && GET_TOKEN_TYPE(last) <= 10)
		return (TRUE);
	return (FALSE);
}

int	io_err(t_dlst *lst)
{
	if (endwith_io(lst) == TRUE)
		return (syntax_error_printer(ERR_NEWLINE));
	return (SUCESS);
}
