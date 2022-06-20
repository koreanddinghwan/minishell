/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:41:46 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 15:44:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	print_toks(t_token *tok_buf)
{
	while (tok_buf->c != 0)
	{
		printf("type : %d\n", tok_buf->type);
		printf("\'%c\'\n", tok_buf->c);
		tok_buf++;
	}
}

void	token_init(t_data *data)
{
	data->tok_buf = ft_calloc(sizeof(t_token), ft_strlen(data->command) + 1);
}

int	tokenizer(t_data *data)
{
	if (!data->command)
		return (FAIL);
	token_init(data);
	if (token_buf_build(data) == FAIL)
		return (FAIL);
	else
		return (SUCESS);
	print_toks(data->tok_buf);
}
