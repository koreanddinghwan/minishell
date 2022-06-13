/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/13 10:28:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "structs.h"
# include "defines_enums.h"

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

void	parser(t_data *data);
void	get_word_lst(t_dlst **word_lst, t_dlst *lexer_t_lst);

#endif
