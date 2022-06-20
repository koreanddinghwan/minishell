/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:04:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 12:48:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * replacer module is used in lexer,
 * replacer do
 * 1. trim \" and \'
 * 2. if buffer is not start with \'
 *    => replace $? and $ENV with exit_status and env variable
 * */

#include "replacer.h"

char	*get_replaced(t_data *data, char *str)
{
	char	*rtn;
	int		len;

	len = get_replaced_len(str, data);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
	{
		free(str);
		return (ft_strdup(""));
	}
	cpy_replaced(rtn, str, data, len);
	free(str);
	return (rtn);
}

void	replacer_exec(t_data *data, t_dlst *tok_lst)
{
	char	*buffer;

	buffer = GET_TOKEN_BUFFER(tok_lst);
	if (buffer[0] == ' ')
		return ;
	if (buffer[0] == '\'')
	{
		GET_TOKEN_BUFFER(tok_lst) = ft_strtrim(buffer, "\'");
		free(buffer);
	}
	else
	{
		GET_TOKEN_BUFFER(tok_lst) = ft_strtrim(buffer, "\"");
		free(buffer);
		buffer = GET_TOKEN_BUFFER(tok_lst);
		GET_TOKEN_BUFFER(tok_lst) = get_replaced(data, buffer);
	}
}

void	replacer(t_data *data)
{
	t_dlst	*tok_lst;

	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		replacer_exec(data, tok_lst);
		tok_lst = tok_lst->next;
	}
}