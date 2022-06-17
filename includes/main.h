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
void	set_env(t_data *data, char **envp);
/*
 * display
 * */
void	display_bash(t_data *data, int ac, char **av);
void    execve_pull(char **envp);

/*
 * cd
 * */
void	ft_cd(t_data *data, char *path);
t_envlst	*ft_envlst_last(t_envlst *envlst);
void	ft_envlst_pushback(t_envlst **envlst, t_envlst *new);
t_envlst	*ft_envlst_new(void *c);

/*
 * pwd
 * */
void	ft_pwd();

/*
 * export
 * */
void	ft_export(t_data *data, char **args);

/*
 * unset
 * */
void	ft_unset(t_data *data, char **args);

/*
 * echo
 * */
void	ft_echo(t_data *data, int flag, char *str);

/*
 * exit
 * */
void	ft_exit(int ac, char *av[]);

#endif
