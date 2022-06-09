/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:41:46 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 20:40:21 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	tokenizer(t_data *data, char *line)
{
	char	*trimed;

	trimed = ft_strtrim(line, " ");
	data->token_buf = malloc(sizeof(t_token) * ft_strlen(trimed) + 1);
	if(!data->token_buf)
		return ;
	token_buf_build(data->token_buf, trimed);
	//print_token_lst(data);
	free(trimed);
}
