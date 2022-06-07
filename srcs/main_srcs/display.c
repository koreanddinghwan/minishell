/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 17:10:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_dlst	*make_token_lst(char *line)
{
	char	**splited;
	t_dlst	*token_lst;

	splited = ft_split(line, SPACE);
	while (*splited)
	{
		ft_dlst_new
	}
}

void	set_data(t_data *data, char *line)
{
	add_history(line);
	data->command = line;
	data->token_lst = make_token_lst(line);
}

void	display_bash(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("bash >");
		printf("%s\n", line);
		if (!line)
			return ;
		set_data(data, line);
	}
}
