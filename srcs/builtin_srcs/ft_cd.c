#include "../../includes/main.h"

char	*match_env(t_data *data, char* str)
{
	char	**split;
	t_dlst	*node;

	node = ft_dlst_new(str);
	while (data->env_lst)
	{
		split = ft_split(data->env_lst->content, "=");
		if (!strcmp(data->env_lst->content, split[0]))
			return (data->env_lst->contet);
		data->env_lst->next;
	}
	return (NULL);
}

void	swap_env(t_data *data, char *pwd, char *oldpwd)
{
	t_dlst	*node;

	node = ft_dlst_new("swap");
	node = pwd노드;
	pwd노드 = oldpwd노드;
	oldpwd노드 = node;
}

void	ft_cd(t_data *data, char *str)
{
	char	*buf;
	char	*loc;
	char	*home;
	char	*bef;
	char	*change;

	loc = (char *)malloc(sizeof(char) * 256)*;
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
	if (!strcmp(str, "~"))
		buf = ft_strdup(home);
	else if (!strcmp(str, "-"))
		buf = ft_strdup(bef);
	else
		buf = ft_strdup(str);
	change = chdir(buf);
	if (change == -1)
		printf("bash: cd: %s\n", strerror(errno);
	else
	{
		getcwd(loc, 256);
		swap_env(data, "PWD", "OLDPWD");
	}
}

int	main()
{ 
	char s[100];
	printf("%s\n", getcwd(s, 100));
	ft_cd();
	printf("%s\n", getcwd(s, 100));
}
