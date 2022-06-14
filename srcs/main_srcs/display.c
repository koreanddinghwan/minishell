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

void	display_bash(t_data *data)
{
	char	*line;
	t_dlst	*lst;

	lst = data->env_lst;
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
			while (lst)
			{
				printf("%s ", (char *)lst->key);
				printf("%s\n", (char *)lst->value);
				lst = lst->next;
			}
			lst = lst->head;
		}
		if (!strcmp(data->command, CD))
		{
			ft_cd(data, "~");
		}
	}
}
