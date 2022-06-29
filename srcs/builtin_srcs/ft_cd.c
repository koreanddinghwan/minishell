/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:16 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 12:32:31 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <errno.h>

void	change_env(t_data *data, char *pwd, char *oldpwd)
{
	t_envlst	*node;
	t_envlst	*last;
	node = data->env_lst;
	last = ft_envlst_last(node);
	while (node)
	{
		if (!ft_strncmp(node->key, "PWD", 3))
		{
			node->value = pwd;
			if (strcmp(last->key, "OLDPWD"))
			{
				node = ft_envlst_new("OLDPWD=OLDPWD");
				ft_envlst_pushback(&data->env_lst, node);
				free(node->key);
				free(node->value);
				free(node);
			}
		}
		if (!ft_strncmp(node->key, "OLDPWD", 6))
		{
			node->value = oldpwd;
		}
		node = node->next;
	}
}

void	ft_cd(t_data *data, char **path)
{
	char	*buf;
	char	*aft;
	char	*home;
	char	*old_save;
	char	*cur;
	int		change;
	t_envlst	*node;

	path++;
	node = data->env_lst;
	buf = (char *)malloc(sizeof(char) * 256);
	aft = (char *)malloc(sizeof(char) * 256);
	cur = (char *)malloc(sizeof(char) * 256);
	getcwd(cur, 256);
	old_save = 0;
	while(node)
	{
		if(!strcmp(node->key, "HOME"))
			home = node->value;
		if (!strcmp(node->key, "OLDPWD"))
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
	change = chdir(buf);
	if (change == -1)
		printf("bash: cd: %s\n", strerror(errno));
	else
	{
		getcwd(aft, 256);
		change_env(data, aft, cur);
	}
	free(buf);
	free(aft);
	free(home);
	free(old_save);
	free(cur);
}