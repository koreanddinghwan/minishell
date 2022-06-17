/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:59:02 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 03:09:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*check_env(t_data *data, char *buffer)
{
	-char	*dollar;

	dollar = ft_strchr(buffer, '$');
	if (!dollar)
		return (buffer);
	else
	{

	}
}

void	join_args(char **rtn, t_data *data)
{
	int					i;
	t_dlst				*next;
	t_dlst				*tok_lst;
	enum e_word_type	type;

	i = 0;
	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		type = GET_TOKEN_TYPE(tok_lst);
		next = tok_lst->next;
		if (type == W_PIPE || type == W_SPACE)
			ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		if (type == W_PIPE)
			break ;
		else if (type == W_SPACE)
			tok_lst = next;
		else
		{
			rtn[i] = ft_strdup(check_env(data, GET_TOKEN_BUFFER(tok_lst)));
			ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
			tok_lst = next;
			i++;
		}
	}
	rtn[i] = NULL;
}

int	get_args_count(t_dlst *tok_lst)
{
	int	i;

	i = 0;
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (i);
		if (GET_TOKEN_TYPE(tok_lst) != W_SPACE)
			i++;
		tok_lst = tok_lst->next;
	}
	return (i);
}

char	**make_args(t_data *data)
{
	char	**rtn;
	int		count;

	count = get_args_count(data->lexer_token_lst);
	rtn = malloc(sizeof(char *) * (count + 1));
	join_args(rtn, data);
	ft_printf("args : \n");
	int	i;

	i = 0;
	while (rtn[i])
	{
		ft_printf("%s\n", rtn[i]);
		i++;
	}
	return (rtn);
}
