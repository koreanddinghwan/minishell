/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:46:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 16:32:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * io_error -> special token after io redirection token
 * */

#include "syntax_analyzer.h"

char	*get_err_message(enum e_word_type type)
{
	if (type == W_REDIRECTION_INPUT)
		return (ERR_REDIR_IN);
	if (type == W_REDIRECTION_OUTPUT)
		return (ERR_REDIR_OUT);
	if (type == W_APPENDING_TO)
		return (ERR_APPEND);
	if (type == W_HERE_DOC)
		return (ERR_HEREDOC);
	return (NULL);
}

static int	is_io(t_dlst *lst)
{
	enum e_word_type	type;

	type = GET_TOKEN_TYPE(lst);
	if (type >= 7 && type <= 10)
		return (TRUE);
	else
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
