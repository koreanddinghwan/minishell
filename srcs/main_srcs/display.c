/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 10:31:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_bash(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("mgyush >");
		if (!line)
		{
			printf("\x1b[1A\033[9Cexit\n");
			return ;
		}
		initialize_data(data, line);
	}
}
