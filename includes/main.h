/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 17:13:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "structs.h"
# include "defines_enums.h"
# include "tokenizer.h"
# include "lexer.h"

void	initialize_main(t_data *data, char **envp);
void	set_handler(void);
void	set_env_key(t_data *data, char **envp, int cmd);
/*
 * display
 * */
void	display_bash(t_data *data, char **envp);
void    execve_pull(char **envp);
void	ft_cd(t_data *data, char *path);
#endif
