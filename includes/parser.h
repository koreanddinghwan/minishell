/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 19:38:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "defines_enums.h"

typedef struct	s_io_cont
{
	int		fd;
	char	*filepath;
}	t_io_cont;

typedef struct	s_heredoc_cont
{
	char	*delimeter;
}	t_heredoc_cont;

typedef struct	s_cmd_cont
{
	char	*cmd;
	char	**args;
	t_dlst	*input_lst;
	t_dlst	*output_lst;
	t_dlst	*append_lst;
	t_dlst	*heredoc_lst;
}	t_cmd_cont;

void	simple_cmd(t_data *data);
void	pipe_cmd(t_data *data);
t_dlst	*make_input_lst(t_data *data);
t_dlst	*make_output_lst(t_data *data);
t_dlst	*make_heredoc_lst(t_data *data);
t_dlst	*make_append_lst(t_data *data);
char	*make_cmd(t_data *data);
char	**make_args(t_data *data);
/*
 * tools
 * */
void	lexer_tok_free(void *cur);
t_cmd_cont	*init_cmd_cont(void);
void	print_input_lst(t_dlst *lst);
void	print_heredoc_lst(t_dlst *lst);


#endif