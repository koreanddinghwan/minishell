/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 00:57:29 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_data(t_data *data, char *line)
{
	add_history(line);
	data->command = line;
	
}

void	display_bash(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("bash >");
		if (!line)
			return ;
		set_data(data, line);
	}
}
