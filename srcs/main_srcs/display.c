/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 01:11:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_bash(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("bash >");
		if (!line)
		{
			printf(" exit\n");
			return ;
		}
		initialize_data(data, line);
	}
}
