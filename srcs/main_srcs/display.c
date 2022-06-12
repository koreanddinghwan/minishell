/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 20:54:30 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_bash(t_data *data, char **envp)
{
	char	*line;
	int		cmd;

	cmd = 0;
	while (1)
	{
		line = readline("bash >");
		if (!line)
		{
			printf(" exit\n");
			return ;
		}
		initialize_data(data, line);
		if (!strcmp(data->command, ENV))
		{
			cmd = 1;
			set_env_key(data, envp, cmd);
		}
		if (!strcmp(data->command, CD))
		{
			ft_cd(data, envp);
		}
	}
}
