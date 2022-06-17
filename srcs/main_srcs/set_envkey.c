/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 23:43:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
	char	**split;

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

	return (node);
}

char	*make_key(char *envstr)
{
	char	*str;

	str = ft_strdup(envstr);
	return (str);
}

int	size_envp(char **envp)
{
	int	size;

	size = 0;
	while (*envp)
	{
		size++;
		envp++;
	}
	return (size);
}

void	set_env_arr(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->env = (char **)malloc(sizeof(char *) * size_envp(envp));
	while (*envp)
	{
		if (!ft_strncmp(*envp, "OLDPWD=", 7))
		{
			envp++;
			continue;
		}
		data->env[i] = ft_strdup(*envp);
		envp++;
		i++;
	}
}

void	set_env_list(t_data *data, char **envp)
{
	t_envlst	*node;
	
	while (*envp)
	{
		node = ft_envlst_new(make_key(*envp));
		if (!strcmp(node->key, "OLDPWD"))
		{
			envp++;
			free(node);
		}
		else
			ft_envlst_pushback(&data->env_lst, node);
		envp++;
	}
}
