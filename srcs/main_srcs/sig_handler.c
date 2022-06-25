/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:43:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 15:30:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sigquit_handler(int sig)
{
	(void)sig;
	return ;
}

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\033[%dC  \n", rl_end + 8); 
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	set_handler(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
