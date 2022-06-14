#include "../../includes/main.h"
#include <errno.h>

void	del(void *data)
{
	free(data);
}

void	change_env(t_data *data, char *pwd, char *oldpwd)
{
	t_envlst	*node_c;
	t_envlst	*node_o;

	node_c = ft_envlst_new(pwd);
	node_o = ft_envlst_new(oldpwd);
	while (data->env_lst)
	{
		if (!ft_strncmp(data->env_lst->key, "PWD", 3))
		{
			ft_lstclear(data->env_lst->value, del);
			printf("ONE\n");
		}
		if (!ft_strncmp(data->env_lst->key, "OLDPWD", 6))
		{
			ft_lstclear(data->env_lst->value, del);
			printf("TWO\n");
		}
		data->env_lst = data->env_lst->next;
	}
	ft_envlst_pushback(&data->env_lst, node_c);
	ft_envlst_pushback(&data->env_lst, node_o);
}

void	ft_cd(t_data *data, char *path)
{
	char	*buf;
	char	*loc;
	char	*home;
	char	*old;
	int		change;

	loc = (char *)malloc(sizeof(char) * 256);
	home = (char *)malloc(sizeof(char) * 256);
	old = (char *)malloc(sizeof(char) * 256);
	while(data->env_lst)
	{
		if(!strcmp(data->env_lst->key, "HOME"))
			home = data->env_lst->value;
		data->env_lst = data->env_lst->next;
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
		change_env(data, loc, old);
	}
}
