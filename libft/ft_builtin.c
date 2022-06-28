/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:09:14 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 16:05:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_envlst	*ft_envlst_last(t_envlst *envlst)
{
	t_envlst	*cur;

	if (!envlst)
		return (0);
	cur = envlst;
	while (cur && cur->next != 0)
		cur = cur->next;
	return (cur);
}

void	ft_envlst_pushback(t_envlst **envlst, t_envlst *new)
{
	t_envlst	*last;

	last = ft_envlst_last(*envlst);
	if (last == 0)
	{
		*envlst = new;
		return ;
	}
	last->next = new;
	new->back = last;
}

t_envlst	*ft_envlst_new(void *c)
{
	t_envlst	*node;
	char		**split;

	node = malloc(1 * sizeof(t_envlst));
	if (!node)
		return (0);
	split = ft_split((char *)c, '=');
	if (split[1] == (void *)0)
	{
		split[1] = ft_strdup("");
	}
	node->key = split[0];
	node->value = split[1];
	node->env_line = (char *)c;
	node->next = 0;
	node->back = 0;
	free(split);
	return (node);
}
