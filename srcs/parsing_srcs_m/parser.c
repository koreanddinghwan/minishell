/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 13:34:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

/*
 * cmd(builtin)  args | cmd(builtin) args
 * */

int	there_is_pipe(t_dlst *lst)
{
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) == W_PIPE)
			return (1);
		else
			lst = lst->next;
	}
	return (0);
}

t_tree	*make_ast(t_dlst *lst)
{
	if (!lst)
		return (0);
	if (there_is_pipe(lst))
		return (make_simple_cmd(lst));
	else
		return (make_ast_tree(lst));
}

void	parser(t_data *data)
{
	if (!data)
		return ;
	data->ast = make_ast(data->lexer_token_lst);
}
