/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:52 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 15:26:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**remove_env_arr(t_data *data, char **args)
{
	char	**copy;
	int		j;
	int		size;
	int		i;
	char	**data_envarr;

	copy = (char **)malloc(sizeof(char *) * (data->env_size + 1));
	j = 0;
	size = ft_strlen(*args);
	if (!copy)
		return (0);
	data_envarr = data->env;
	i = 0;
	while (data_envarr[i] && *args)
	{
		if (!ft_strncmp(data_envarr[i], *args, size))
		{
			args++;
			if (*args)
				size = ft_strlen(*args);
			free(data_envarr[i++]);
			continue;
		}
			copy[j] = ft_strdup(data_envarr[i]);
			j++;
			free(data_envarr[i]);
			i++;
	}
	while (data_envarr[i])
	{
		copy[j] = ft_strdup(data_envarr[i]);
		j++;
		free(data_envarr[i]);
		i++;
	}
	copy[j] = 0;
	free(data_envarr);
	return (copy);
}

void	free_env_lst(t_data *data, char *args)
{
	t_envlst	*next;
	t_envlst	*back;
	t_envlst	*cur;

	cur = data->env_lst;
	while (cur)
	{
		next = cur->next;
		back = cur->back;
		if (ft_strcmp(cur->key, args) == 0)
		{
			if (next)
				next->back = back;
			if (back)
				back->next = next;
			else
				data->env_lst = next;
			free(cur->key);
			free(cur->value);
			free(cur->env_line);
			free(cur);
		}
		cur = next;
	}
}

void	ft_unset(t_data *data, char **args)
{
	char		**copy;

	args++;
	copy = args;
	if (!*args)
		return ;
	ft_printf("before unset%d\n", data->env_size);
	while(*args)
	{
		if ((!ft_isalpha(**args) && !ft_isunder(**args)) || ft_strchr(*args, '='))
		{
			printf("mgyush> unset: `%s': not a valid identifier\n", *args);
			return ;
		}
		free_env_lst(data, *args);
		args++;
	}
	data->env_size = ft_envlst_size(data->env_lst);
	ft_printf("after unset%d\n", data->env_size);
	data->env = remove_env_arr(data, copy);
}
