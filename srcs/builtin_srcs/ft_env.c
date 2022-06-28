#include "main.h"

void	ft_env(t_data *data)
{
	t_envlst	*lst;

	lst = data->env_lst;
	while (lst)
	{
		printf("%s=%s\n", (char *)lst->key, (char *)lst->value);
		lst = lst->next;
	}
}
