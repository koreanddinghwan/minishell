/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/14 21:55:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

/*
 * cmd(builtin)  args | cmd(builtin) args
 * */

t_tree	*make_ast(t_dlst *lst)
{
	if (!lst)
		return (0);
	return (0);
}

void	parser(t_data *data)
{
	if (!data)
		return ;
	data->ast = make_ast(data->lexer_token_lst);
}
