/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:46:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 14:58:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * io_error -> special token after io redirection token
 * */

#include "syntax_analyzer.h"

int	endwith_io(t_dlst *lst)
{
	t_dlst	*last;

	last = ft_dlst_last(lst);
	if (GET_TOKEN_TYPE(last) == W_SPACE)
	{
		while (GET_TOKEN_TYPE(last) == W_SPACE)
			last = last->back;
		if (GET_TOKEN_TYPE(last) >= 7 && GET_TOKEN_TYPE(last) <= 10)
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
