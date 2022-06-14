/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/14 13:57:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "main.h"

enum	e_node_type
{
	N_PIPE = 0,
	N_ARG,
	N_REDIRECTION_INPUT,
	N_REDIRECTION_OUTPUT,
	N_DELIMETER,
	N_FILEPATH
};

typedef struct	s_ast_cont
{
	enum e_node_type	type;
	char				*args;
}	t_ast_cont;

#endif
