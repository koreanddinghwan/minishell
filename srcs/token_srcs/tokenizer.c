/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:41:46 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 11:57:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	token_init(t_data *data)
{
	data->tok_buf = ft_calloc(sizeof(t_token), ft_strlen(data->trimmed) + 1);
}

void	tokenizer(t_data *data)
{
	if (!data->trimmed)
		return ;
	token_init(data);
	token_buf_build(data);
	print_toks(data->tok_buf);
	//print_token_lst(data);
}
