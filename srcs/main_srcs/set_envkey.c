/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 17:15:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rest_dup(char **args, char **copy, int *j)
{
	while (*args)
	{
		copy[*j] = ft_strdup(*args);
		(*j)++;
		args++;
	}	
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
	copy = (char **)malloc(sizeof(char *) * (data->env_size + 1));
	if (!copy)
		return (0);
	if (!strchr(*args, '='))
		return (0);
	while (data->env[i])
	{
		copy[j] = ft_strdup(data->env[i]);
		free(data->env[i]);
		j++;
		i++;
	}
	rest_dup(args, copy, &j);
	copy[j] = 0;
	free(data->env);
	return (copy);
}

void	set_env_arr(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->env_size = size_envp(envp);
	data->env = (char **)malloc(sizeof(char *) * (data->env_size + 1));
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
		node = ft_envlst_new(*envp);
		if (!node)
			return ;
		if (!strcmp(node->key, "OLDPWD"))
		{
			envp++;
			free(node->key);
			free(node->value);
			free(node->env_line);
			free(node);
		}
		else
			ft_envlst_pushback(&data->env_lst, node);
		envp++;
	}
}
