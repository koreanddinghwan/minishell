/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:33:14 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 21:06:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_main(t_data *data, char **envp)
{
	set_handler();
	data->lexer_token_lst = NULL;
	data->env_lst = NULL;
	data->cmd_lst = NULL;
	data->exit_status = 0;
	set_env_key(data, envp);
}
