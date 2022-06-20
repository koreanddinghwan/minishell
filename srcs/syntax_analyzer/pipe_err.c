/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:27:43 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 02:11:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * case1 : start with | command
 * case2 : multiline pipe 'cmd |'
 * case3 : double pipe list cmd || cmd and cmd | | cmd
 * */

#include "syntax_analyzer.h"

/*
int	ismultiline(t_dlst *lst)
{
	t_dlst	*pipe_lst;

	pipe_lst = 0;
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) == W_PIPE)
		{

		}
	}
}
*/

int	double_pipe(t_dlst *lst)
{
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) == W_PIPE)
		{
			while (lst && GET_TOKEN_TYPE(lst) == W_SPACE)
				lst = lst->next;
			if (lst && GET_TOKEN_TYPE(lst) == W_PIPE)
				return (syntax_error_printer(ERR_PIPE));
		}
		lst = lst->next;
	}
	return (FALSE);
}

int	startwith_pipe(t_dlst *lst)
{
	if (GET_TOKEN_TYPE(lst) == W_SPACE || GET_TOKEN_TYPE(lst) == W_PIPE)
	{
		while (lst && GET_TOKEN_TYPE(lst) == W_SPACE)
			lst = lst->next;
		if (lst && GET_TOKEN_TYPE(lst) == W_PIPE)
			return (TRUE);
	}
	return (FALSE);
}

int	pipe_err(t_dlst *lst)
{
	if (startwith_pipe(lst) == TRUE)
		return (syntax_error_printer(ERR_PIPE));
	if (double_pipe(lst) == TRUE)
		return (syntax_error_printer(ERR_PIPE));
	return (SUCESS);
}
