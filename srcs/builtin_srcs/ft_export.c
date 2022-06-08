#include "../../includes/main.h"



void	ft_export(t_data *data, char *str)
{
	char	**split;
	t_dlst	*node;
	
	split = ft_split(str, "=");
	if (*(split+1) != "=")
	{
		printf("bash: export: '%s': not ad valid indentifier\n", str);
		return ;
	}
	else
	{
		node = ft_dlst_new(str);
		ft_dlst_pushback(&data->env_lst, node);
	}
}
