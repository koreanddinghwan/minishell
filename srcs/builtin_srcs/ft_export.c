#include "main.h"

void	ft_export(t_data *data, char **args)
{
	t_envlst	*node;
	char		**copy;

	copy = args;
	while(*args)
		{
			printf("%s\n", *args);
			while(**args)
			{
				printf("%c ", **args);
				(*args)++;
			}
			printf("\n");
			(args)++;
		}
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
