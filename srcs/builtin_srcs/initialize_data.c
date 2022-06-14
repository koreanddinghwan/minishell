/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 10:44:03 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	initialize_data(t_data *data, char *line)
{
	add_history(line);
	data->trimmed = ft_strtrim(line, " ");
	data->command = line;
	//tokenizer(data);
	//lexer(data);
	//parser(data);
}