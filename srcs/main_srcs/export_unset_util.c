/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:38:24 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 17:38:25 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rest_dup(char **args, char **copy, int *j)
{
	while (*args)
	{
		copy[*j] = ft_strdup(*args);
		(*j)++;
		args++;
	}	
}

int	size_envp(char **envp)
{
	int	size;

	size = 0;
	while (*envp)
	{
		size++;
		envp++;
	}
	return (size);
}

char	**add_env_arr(t_data *data, char **args)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = (char **)malloc(sizeof(char *) * (data->env_size + 1));
	if (!copy)
		return (0);
	if (!strchr(*args, '='))
		return (0);
	while (data->env[i])
	{
		copy[j] = ft_strdup(data->env[i]);
		free(data->env[i]);
		j++;
		i++;
	}
	rest_dup(args, copy, &j);
	copy[j] = 0;
	free(data->env);
	return (copy);
}

void	free_env_arr(t_data *data)
{
	while (*data->env)
	{
		free(*data->env);
		data->env++;
	}
	free(data->env);
}

void	update_env_arr(t_data *data, t_envlst *envp)
{
	char **copy;


	dup_env_arr();
	diff size_envp(envp); data->env_size
	free_env_arr()
}
