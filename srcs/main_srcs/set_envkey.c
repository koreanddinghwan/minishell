/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/13 10:07:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*make_key(char *envstr)
{
	char	*str;

	str = ft_strdup(envstr);
	if (ft_strncmp("OLDPWD=", str, 7) == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	set_env_key(t_data *data, char **envp)
{
	t_dlst	*node;
	char	*str;

	while (*envp)
	{
		str = make_key(*envp);
		if (!str)
		{
			envp++;
			continue ;
		}
		node = ft_dlst_new(str);
		ft_dlst_pushback(&data->env_lst, node);
		envp++;
	}
}
