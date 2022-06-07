/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 14:07:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


char	*make_key(char *envstr)
{
	char	*str;
	int		i;
	
	i = 0;
	while (envstr[i] != '=')
		i++;
	str = ft_strndup(envstr, i);
	return (str);
}

void	set_env_key(t_data *data, char **envp)
{
	t_dlst	*node;

	while (*envp)
	{
		node = ft_dlst_new(make_key(*envp));
		ft_dlst_pushback(&data->env_key, node);
		envp++;
	}
}
