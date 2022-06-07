/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:33:14 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 21:56:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_main(t_data *data, char **envp)
{
	set_handler();
	data->token_lst = 0;
	data->env = 0;
	set_env_key(data, envp);
}
