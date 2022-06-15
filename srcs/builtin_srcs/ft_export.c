#include "main.h"

void	ft_export(t_data *data, char *str)
{
	t_envlst	*node;
	
	if (!strchr(str, '='))
	{
		printf("bash: export: '%s': not ad valid indentifier\n", str);
		return ;
	}
	else
	{
		node = ft_envlst_new(str);
		ft_envlst_pushback(&data->env_lst, node);
	}
}
