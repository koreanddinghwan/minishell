/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 15:23:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		{
			ft_envlst_pushback(&data->env_lst, node);
			data->env_size++;
		}
		printf("%s %d\n", *envp, data->env_size);
		envp++;
	}
}

void	set_env_arr(t_data *data)
{
	t_envlst *node;
	char	*buffer;
	char	*ex;
	int		i;

	node = data->env_lst;
	data->env = (char **)malloc(sizeof(char *) * (data->env_size +1));
	i = 0;
	if (!data->env)
		return ;
	while (node)
	{
		buffer = ft_strjoin(node->key, "=");
		ex = buffer;
		buffer = ft_strjoin(buffer, node->value)
		free(ex);
		data->env[i] = buffer;
		node = node->next;
	}
	data->env[i] = 0;
}