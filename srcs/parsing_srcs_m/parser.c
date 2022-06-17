/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 23:25:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

/*
 * cmd(builtin)  args | cmd(builtin) args
 * */

int		there_is_pipe(t_dlst *lst)
{
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) == W_PIPE)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	parser(t_data *data)
{
	t_dlst	*tok_lst;

	if (!data)
		return ;
	tok_lst = data->lexer_token_lst;
	if (!there_is_pipe(tok_lst))
		simple_cmd(data);
	else
		pipe_cmd(data);
}
