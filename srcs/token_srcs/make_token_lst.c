/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:06 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 20:20:57 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_token	*make_token(char c)
{
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (NULL);
	token->type = get_token_type(c);
	token->value = c;
	return (token);
}

void	make_token_lst(char *token_buf)
{
	t_dlst	*token_lst;
	int		state;
	t_token	*new;

	token_lst = NULL;
	state = STATE_NORMAL;
	while (*line)
	{
		new = make_token(*line, , &state);
		ft_dlst_pushback(&token_lst, ft_dlst_new(new));
		line++;
	}
	return (token_lst);
}


