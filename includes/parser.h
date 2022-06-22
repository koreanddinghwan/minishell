/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 17:15:00 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "defines_enums.h"
# include "cleaner.h"

void			simple_cmd(t_data *data);
void			pipe_cmd(t_data *data);
t_dlst			*make_input_lst(t_data *data);
t_dlst			*make_output_lst(t_data *data);
t_dlst			*make_heredoc_lst(t_data *data);
t_dlst			*make_append_lst(t_data *data);
char			*make_cmd(t_data *data);
enum e_cmdtype	get_cmdtype(char *cmd);
char			**make_args(t_data *data);
/*
 * tools
 * */
t_cmd_cont		*init_cmd_cont(void);
void			print_input_lst(t_dlst *lst);
void			print_heredoc_lst(t_dlst *lst);
void			print_args_cmd(char **args);


#endif
