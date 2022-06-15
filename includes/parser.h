/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 22:00:32 by myukang          ###   ########.fr       */
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

typedef struct	s_parse_cont
{
	enum e_node_type	type;
	char				*cmd;
	union u_node_data	data;
	int					infile;
	int					outfile;
	t_parse_cont		*next_pipe_cmd;
}	t_parse_cont;


typedef struct	s_cmd
{
	typedef struct	*next;
	char			**argv;
	t_input_lst		*input_lst;
	t_output_lst	*output_lst;
}	t_cmd;

typedef struct	s_parse_head
{
	t_cmd	*cmd;
}

#endif
