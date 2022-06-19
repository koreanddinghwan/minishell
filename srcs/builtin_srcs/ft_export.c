#include "main.h"

void	ft_export(t_data *data, char **args)
{
	t_envlst	*node;
	char		**copy;

	args++;
	copy = args;
	while (*args)
	{
		if (!strchr(*args, '='))
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
