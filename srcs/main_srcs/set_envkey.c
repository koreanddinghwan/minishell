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

char	*make_key(char *envstr)
{
	char	*str;

	str = ft_strdup(envstr);
	return (str);
}

void	set_env_key(t_data *data, char **envp, int cmd)
{
	t_dlst	*node;

	while (*envp)
	{
		node = ft_dlst_new(make_key(*envp));
		ft_dlst_pushback(&data->env_lst, node);
		if (cmd == 1)
		{
			printf("%s\n", (char *)data->env_lst->content);
			data->env_lst = data->env_lst->next;
		}
		envp++;
	}
}
