/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:27:43 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 01:43:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * case1 : start with | command
 * case2 : multiline pipe 'cmd |'
 * case3 : double pipe list cmd || cmd and cmd | | cmd
 * */

#include "syntax_analyzer.h"

int	startwith_pipe(t_dlst *lst)
{
	if (lst)
	{
		while (GET_TOKEN_TYPE(lst) == W_SPACE)
			lst = lst->next;
		if (lst && GET_TOKEN_TYPE(lst) == W_PIPE)
			return (1);
	}
	return (0);
}

int	pipe_err(t_dlst *lst)
{
	if (startwith_pipe(lst))
		return (syntax_error_printer(ERR_PIPE));
	return (SUCESS);
}
