/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 20:08:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include "structs.h"
# include "defines_enums.h"

void	initialize_main(t_data *data, char **envp);
void	set_handler(void);
void	set_env_key(t_data *data, char **envp);
/*
 * display
 * */
void	display_bash(t_data *data);
void	initialize_data(t_data *data, char *line);
void	tokenizer(t_data *data);
void	lexer(t_data *data);
void	parser(t_data *data);
void	execute(t_data *data);
#endif
