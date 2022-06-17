/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 00:51:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
