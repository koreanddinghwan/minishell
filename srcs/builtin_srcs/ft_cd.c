#include "builtin.h"
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
			}
		}
		if (!ft_strncmp(node->key, "OLDPWD", 6))
		{
			node->value = oldpwd;
		}
		node = node->next;
	}
}

void	ft_cd(t_data *data, char *path)
{
	char	*buf;
	char	*loc;
	char	*home;
	char	*old;
	int		change;
	t_envlst	*node;

	node = data->env_lst;
	buf = (char *)malloc(sizeof(char) * 256);
	loc = (char *)malloc(sizeof(char) * 256);
	home = (char *)malloc(sizeof(char) * 256);
	old = (char *)malloc(sizeof(char) * 256);
	getcwd(old, 256);
	while(node)
	{
		if(!strcmp(node->key, "HOME"))
			home = node->value;
		node = node->next;
	}
	if (!strcmp(path, "~"))
		buf = ft_strdup(home);
	else if (!strcmp(path, "-"))
		buf = ft_strdup(old);
	else
		buf = ft_strdup(path);
	change = chdir(buf);
	if (change == -1)
		printf("bash: cd: %s\n", strerror(errno));
	else
	{
		getcwd(loc, 256);
		printf("loc: %s\n", loc);
		change_env(data, loc, old); // loc: pwd, old: oldpwd
	}
	free(buf);
}
