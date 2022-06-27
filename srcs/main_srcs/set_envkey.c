/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 16:00:30 by myukang          ###   ########.fr       */
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

char	**add_env_arr(t_data *data, char **args)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = (char **)malloc(sizeof(char *) * data->env_size * 10);
	if (!strchr(*args, '='))
		return (0);
	while (data->env[i])
	{
		copy[j] = ft_strdup(data->env[i]);
		j++;
		i++;
	}
	while (*args)
	{
		copy[j] = ft_strdup(*args);
		j++;
		args++;
	}
	copy[j] = 0;
	return (copy);
}

void	set_env_arr(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->env_size = size_envp(envp);
	data->env = (char **)malloc(sizeof(char *) * data->env_size);
	while (*envp)
	{
		if (!ft_strncmp(*envp, "OLDPWD=", 7))
		{
			envp++;
			continue ;
		}
		data->env[i] = ft_strdup(*envp);
		envp++;
		i++;
	}
	data->env[i] = 0;
}

void	set_env_lst(t_data *data, char **envp)
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
