/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:32:18 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 20:51:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_token	*make_token(char **str, int	i)
{
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (NULL);
	token->type = get_token_type(str[i]);
	token->value = *(str + i);
	token->nth = i;
	return (token);
}

t_dlst	*make_token_lst(char *line)
{
	char	**splited;
	t_dlst	*token_lst;
	int		i;

	splited = ft_split(line, SPACE);
	i = 0;
	while (splited[i])
	{
		ft_dlst_pushback(&token_lst, ft_dlst_new(make_token(splited, i)));
		i++;
	}
	return (token_lst);
}

void	change_type(t_dlst *lst)
{
	while (lst && !is_special_token(((t_token *)lst->content)->type))
	{
		((t_token *)lst->content)->type = ARG;
		lst = lst->next;
	}
}

void	modify_token_type(t_dlst *token_lst)
{
	t_dlst	*cur;

	cur = token_lst;
	while (cur)
	{
		if ((((t_token *)cur->content)->type == BUILTIN || (((t_token *)cur->content)->type == COMMAND)))
		{
			if (cur->next)
			{
				if (((t_token *)cur->next->content)->type == OPTION)
					change_type(cur->next->next);
				else
					change_type(cur->next);
			}
		}
		cur = cur->next;
	}
}

void	set_token(t_data *data, char *line)
{
	data->token_lst = make_token_lst(line);
	modify_token_type(data->token_lst);
	while (data->token_lst)
	{
		printf("type : %d, value : %s\n", ((t_token *)(data->token_lst->content))->type, ((t_token *)(data->token_lst->content))->value);
		data->token_lst = data->token_lst->next;
	}
}
