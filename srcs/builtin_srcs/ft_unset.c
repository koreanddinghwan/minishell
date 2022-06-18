#include "main.h"

void	free_env_lst(t_data *data, char **args)
{
	t_envlst	*rem_node;
	t_envlst	*node;

	rem_node = data->env_lst->next;
	node = data->env_lst;

	while (rem_node)
	{
		if (!ft_strcmp(rem_node->key, *args))
		{
			node->next = rem_node->next;
			free(rem_node);
			return ;
		}
		rem_node = rem_node->next;
		node = node->next;
	}
}

void	ft_unset(t_data *data, char **args)
{
	while(*args)
	{
		free_env_lst(data, args);
		args++;
	}
}