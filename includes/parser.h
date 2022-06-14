/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/14 22:05:22 by myukang          ###   ########.fr       */
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
	N_HEREDOC,
};

union	u_node_data
{
	char	**args;
	char	*filepath;
	char	*delimeter;
};

typedef struct	s_ast_cont
{
	enum e_node_type	type;
	union u_node_data	data;
	int					infile;
	int					outfile;
}	t_ast_cont;

#endif
