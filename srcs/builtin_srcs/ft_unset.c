#include "main.h"

void	ft_unset(t_data *data, char *key)
{
	t_envlst	*rem_node;
	t_envlst	*node;

	rem_node = data->env_lst->next;
	node = data->env_lst;
	while(rem_node)
	{
		if (!strcmp(rem_node->key, key))
		{
			node->next = rem_node->next;
			free(rem_node);
			return ;
		}
		rem_node = rem_node->next;
		node = node->next;
	}
}