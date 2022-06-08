/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:06 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 18:26:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_dlst	token_lst_pipe(char *line)
{
	char	**splited;
	t_dlst	*token_lst;

	splited = ft_split(line, '|');
	while (*splited)
	{
		ft_dlst_pushback(&token_lst, ft_dlst_new(make_token(*splited)));
		splited++;
		if (*splited)
			ft_dlst_pushback(&token_lst, ft_dlst_new(make_token("|")));
	}
	return (token_lst);
}

static t_token	*make_token(char *str)
{
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (NULL);
	token->type = get_token_type(str);
	token->value = str;
	return (token);
}

t_dlst	*make_token_lst(char *line)
{
	t_dlst	*token_lst;

	token_lst = token_lst_pipe(line);
	//

	return (token_lst);
}
