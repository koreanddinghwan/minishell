/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:34:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*make_key(char *envstr)
{
	char	*str;

	str = ft_strdup(envstr);
	return (str);
}


void	set_env_key(t_data *data, char **envp, int cmd)
{
	t_envlst	*node;

	while (*envp)
	{
		node = ft_envlst_new(make_key(*envp));
		ft_envlst_pushback(&data->env_lst, node);
		if (cmd == 1)
		{
			printf("%s\n", (char *)data->env_lst->key);
			printf("%s\n", (char *)data->env_lst->value);
			data->env_lst = data->env_lst->next;
		}
		envp++;
	}
}
