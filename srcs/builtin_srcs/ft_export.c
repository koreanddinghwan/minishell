#include "main.h"

void	ft_export(t_data *data, char **args)
{
	t_envlst	*node;
	int			i;
	
	i = 0;
	while (*args)
	{
		if (!strchr(*args, '='))
			return ;
		else
		{
			node = ft_envlst_new(*args);
			ft_envlst_pushback(&data->env_lst, node);
			while (data->env[i])
			{
				i++;
			}
			data->env = (char **)realloc(data->env, data->env_size + 1);
			data->env[i] = ft_strdup(*args);
		}
		args++;
	}
}
