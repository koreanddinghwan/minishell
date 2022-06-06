/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 00:56:28 by myukang          ###   ########.fr       */
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
}	t_data;

/*
 * signal handler
 * */
void	sigquit_handler(int sig);
void	sigint_handler(int sig);
void	set_handler(void);

/*
 * display
 * */
void	display_bash(t_data *data);

#endif
