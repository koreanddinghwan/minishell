/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:27:24 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 00:42:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finder.h"

int	exist_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	*find_env_key(t_envlst *envlst, char *key)
{
	char	*e_value;
	char	*e_key;

	while (envlst)
	{
		e_key = envlst->key;
		e_value = envlst->value;
		if (ft_strcmp(e_key, key) == 0)
			return (e_value);
		envlst = envlst->next;
	}
	return (NULL);
}

char	*path_finder(t_envlst *envlst, char *cmd)
{
	char	*rtn;

	rtn = NULL;
	if (exist_slash(cmd) == TRUE)
		return (cmd);
	else
	{
		rtn = check_envpath(find_env_key(envlst, "PATH"), cmd);
		if (rtn)
			return (rtn);
		else
			return (cmd);
	}
}
