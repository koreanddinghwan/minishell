/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 14:02:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include "libft.h"

typedef	struct s_data
{
	HIST_ENTRY	**history_list;
	char		*command;
	t_dlst		*lst;
	t_dlst		*env_key;
}	t_data;

void	initialize_main(t_data *data, char **envp);
void	set_env_key(t_data *data, char **envp);
/*
 * signal handler
 * */
void	set_handler(void);
void	sigquit_handler(int sig);
void	sigint_handler(int sig);

/*
 * display
 * */
void	display_bash(t_data *data);

#endif
