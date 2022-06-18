/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_replacer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:00:01 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 21:10:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		isthere_dollar_sign(char *buffer)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(buffer);
	while (buffer[i])
	{
		if (buffer[i] == '$' && i != size)
			return (0);
		else
			return (1);
		i++;
	}
}

void	lexer_replacer(t_data *data)
{
	t_dlst	*ltok_lst;

	ltok_lst = data->lexer_token_lst;
	while (ltok_lst)
	{
		if (isthere_dollar_sign(GET_TOKEN_BUFFER(ltok_lst)));
			replace_dollarsign(ltok_lst);
		ltok_lst = ltok_lst->next;
	}
}
