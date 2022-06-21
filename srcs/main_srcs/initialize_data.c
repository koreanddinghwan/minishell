/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 16:59:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_data(t_data *data, char *line)
{
	if (ft_strlen(line) == 0)
		return ;
	add_history(line);
	data->command = line;
	if (tokenizer(data) == FAIL)
		return ;
	if (lexer(data) == FAIL)
		return ;
	parser(data);
	execute(data);
	//exec(data);
	//clear(data);
}
