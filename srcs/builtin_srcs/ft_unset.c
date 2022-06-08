#include "../../includes/main.h"

void	ft_unset(t_data *data, t_token *token)
{
	char	**split;
	t_dlst	*env;
	t_dlst	*link;

	env = data->env_lst;
	while(data->env)
	{
		split = ft_split(*envp, "=");
		if (!strcmp(token->value, split[0]))
		{
			link->next = env->next
			free(data->env_lst);
			free(split);
			return ;
		}
		envp++;
		data->env_lst = data->env_lst->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_token	*token;

	ft_unset(&data, token);
	return (0);
}
