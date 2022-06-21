/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/19 18:48:37 by myukang          ###   ########.fr       */
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
	lexer(data);
	if (syntax_analyzer(data) == FAIL)
		return ;
	parser(data);
	execute(data);
	//exec(data);
	//clear(data);
}
