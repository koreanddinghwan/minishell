/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 16:07:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "defines_enums.h"

enum	e_node_type
{
	N_CMD = 0,
	N_PIPE,
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
	char				*cmd;
	union u_node_data	data;
	int					infile;
	int					outfile;
}	t_ast_cont;

typedef struct	s_tmp_head
{
	int		left_index;
	int		right_index;
	t_dlst	*start_node;
}	t_tmp_head;

t_tree	*make_simple_cmd(t_dlst *lst);

#endif
