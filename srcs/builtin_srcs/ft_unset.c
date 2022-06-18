#include "main.h"

char	**remove_env_arr(t_data *data, char **args)
{
	char	**copy;
	char	**split;
	int i = 0;
	int j = 0;

	copy = (char **)malloc(sizeof(char *) * data->env_size * 10);
	while (data->env[i])
	{
		split = ft_split(data->env[i], '=');
		printf("arr: %s\nspl: %s\n", data->env[i], *args);
		if (!ft_strcmp(split[0], *args))
		{
			data->env++;
			args++;
			continue;
		}
		copy[j] = ft_strdup(data->env[i]);
		j++;
		i++;
	}
	copy[j] = 0;
	return	(copy);
}

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
	char		**copy;

	copy = args;
	while(*args)
	{
		free_env_lst(data, args);
		args++;
	}
	data->env = remove_env_arr(data, copy);
}