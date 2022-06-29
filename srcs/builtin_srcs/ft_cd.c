/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:16 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 21:17:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <errno.h>

void	change_env(t_data *data, char *oldpwd)
{
	t_envlst	*node;
	t_envlst	*last;
	char		*pwd;
	
	node = data->env_lst;
	last = ft_envlst_last(node);
	pwd = (char *)malloc(sizeof(char) * 256);
	pwd = getcwd(pwd, 256);
	while (node)
	{
		if (!ft_strncmp(node->key, "PWD", 3))
		{
			free(node->value);
			node->value = pwd;
			if (ft_strcmp(last->key, "OLDPWD"))
			{
				node = ft_envlst_new("OLDPWD=OLDPWD");
				ft_envlst_pushback(&data->env_lst, node);
			}
		}
		if (!ft_strncmp(node->key, "OLDPWD", 6))
		{
			free(node->value);
			node->value = oldpwd;
		}
		node = node->next;
	}
}
void	ft_cd(t_data *data, char **path)
{
	t_envlst	*node;
	char	*buf;
	char	*home;
	char	*old_save;
	char	*cur;

	path++;
	node = data->env_lst;
	cur = (char *)malloc(sizeof(char) * 256);
	cur = getcwd(cur, 256);
	while(node)
	{
		if(!ft_strcmp(node->key, "HOME"))
			home = node->value;
		if (!ft_strcmp(node->key, "OLDPWD"))
 			old_save = node->value;
 		node = node->next;
 	}
 	if (!*path)
 		buf = ft_strdup(home);
 	else if (!strcmp(*path, "~"))
 		buf = ft_strdup(home);
 	else if (!strcmp(*path, "-"))
 		buf = ft_strdup(old_save);
	else
		buf = ft_strdup(*path);
	if (chdir(buf) == -1)
		printf("mgyush: cd: %s\n", strerror(errno));
	else
	{
		change_env(data, cur);
	}
	free(buf);
}