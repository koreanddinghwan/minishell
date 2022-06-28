#include "main.h"

char	**remove_env_arr(t_data *data, char **args)
{
	char	**copy;
	int		j;
	int		size;

	copy = (char **)malloc(sizeof(char *) * data->env_size * 10);
	j = 0;
	size = ft_strlen(*args);
	if (!copy)
		return (0);
	while (*data->env && *args)
	{
		if (!ft_strncmp(*data->env, *args, size))
		{
			data->env++;
			args++;
			if (*args)
				size = ft_strlen(*args);
			continue;
		}
			copy[j] = ft_strdup(*data->env);
			j++;
			free(*data->env);
			data->env++;
	}
	while (*data->env)
	{
		copy[j] = ft_strdup(*data->env);
		j++;
		free(*data->env);
		data->env++;
	}
	copy[j] = 0;
	return (copy);
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

	args++;
	copy = args;
	if (!*args)
		return ;
	while(*args)
	{
		if ((!ft_isalpha(**args) && !ft_isunder(**args)) || ft_strchr(*args, '='))
		{
			printf("mgyush> unset: `%s': not a valid identifier\n", *args);
			return ;
		}
		free_env_lst(data, args);
		args++;
	}
	data->env = remove_env_arr(data, copy);
}
