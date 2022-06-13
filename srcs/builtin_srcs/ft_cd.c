#include "../../includes/main.h"
#include <errno.h>

void	del(void *data)
{
	free(data);
}

void	swap_env(t_data *data, char *pwd, char *oldpwd)
{
	t_dlst	*node_c;
	t_dlst	*node_o;

	node_c = ft_dlst_new(pwd);
	node_o = ft_dlst_new(oldpwd);
	while (data->env_lst)
	{
		if (!ft_strncmp(data->env_lst->content, "PWD", 3))
			ft_lstclear(data->env_lst->content, del);
		if (!ft_strncmp(data->env_lst->content, "OLDPWD", 6))
			ft_lstclear(data->env_lst->content, del);
		data->env_lst = data->env_lst->next;
	}
	ft_dlst_pushback(&data->env_lst, node_c);
	ft_dlst_pushback(&data->env_lst, node_o);
}

void	ft_cd(t_data *data, char *path)
{
	char	*buf;
	char	*loc;
	char	*home;
	char	*bef;
	int		change;

	loc = (char *)malloc(sizeof(char) * 256);
	home = (char *)malloc(sizeof(char) * 256);
	bef = (char *)malloc(sizeof(char) * 256);
	while(data->env_lst)
	{
		if(!strncmp(data->env_lst->content, "HOME", 4))
			home = data->env_lst->content;
		if(!strncmp(data->env_lst->content, "OLDPWD", 6))
			bef = data->env_lst->content;
		data->env_lst = data->env_lst->next;
	}
	if (!strcmp(path, "~"))
		buf = ft_strdup(home);
	else if (!strcmp(path, "-"))
		buf = ft_strdup(bef);
	else
		buf = ft_strdup(path);
	change = chdir(buf);
	if (change == -1)
		printf("bash: cd: %s\n", strerror(errno));
	else
	{
		getcwd(loc, 256);
		swap_env(data, "PWD", "OLDPWD");
	}
}
