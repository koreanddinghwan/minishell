#include "../../includes/main.h"

void	ft_unset(t_data *data, char **envp)
{
	char	**split;
	t_dlst	*env;
	t_dlst	*link;

	while(data->env)
	{
		split = ft_split(*envp, "=");
		if (!strcmp(av[1] 토큰value, split[0]))
		{
			link = 
			data->env = data->env->next;
			free(data->env);
		}
		envp++;
		data->env = data->env->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_unset(&data, envp);
	return (0);
}
