#include "../../includes/main.h"

char	*make_key(char	*envstr)
{
	char	*str;

	str = ft_strdup(envstr);
	return (str);
}

void	set_env_key(t_data	*data, char	**envp)
{
	t_dlst	*node;

	while (*envp)
	{
		node = ft_dlst_new(make_key(*envp));
		ft_dlst_pushback(&data->env_lst, node);
		printf("%s\n", (char *)data->env_lst->content);
		envp++;
		data->env_lst = data->env_lst->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	set_env_key(&data, envp);
	return (0);
}
