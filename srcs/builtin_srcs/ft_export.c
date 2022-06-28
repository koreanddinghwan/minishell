#include "main.h"

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	only_export(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (data->env[i])
	{
		j = i + 1;
		while (data->env[j])
		{
			if (ft_strcmp(data->env[i], data->env[j]) > 0)
				ft_swap(&data->env[i], &data->env[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (data->env[i])
	{
		printf("declare -x %s\n", data->env[i]);
		i++;
	}
}

int	ft_isunder(int c)
{
	if (c == '_')
		return (1);
	return (0);
}

void	free_env(t_data *data, char **args)
{
	t_envlst	*rem_node;
	t_envlst	*node;
	int			size;

	rem_node = data->env_lst->next;
	node = data->env_lst;

	while (rem_node)
	{
		size = ft_strlen(rem_node->key);
		if (!ft_strncmp(rem_node->key, *args, size))
		{
			node->next = rem_node->next;
			free(rem_node);
			return ;
		}
		rem_node = rem_node->next;
		node = node->next;
	}
}

void	ft_export(t_data *data, char **args)
{
	t_envlst	*node;
	char		**copy;

	args++;
	copy = args;
	if (!*args)
	{
		only_export(data);
		return;
	}
	while (*args)
	{
		if ((!ft_isalpha(**args) && !ft_isunder(**args)))
		{
			printf("mgyush: export: `%s': not a valid identifier\n", *args);
			return ;
		}
		else if (!strchr(*args, '='))
			return ;
		else
		{
			node = ft_envlst_new(*args);
			ft_envlst_pushback(&data->env_lst, node);
		}
		args++;
	}
	data->env = add_env_arr(data, copy);
}
