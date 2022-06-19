#include "main.h"

void    ft_env(t_data   *data)
{
    t_envlst    *lst;
    int         i;

    lst = data->env_lst;
    i = 0;
    while (lst)	//lst
		{
			printf("list: %s\n", (char*)lst->env_line);
			lst = lst->next;
		}
	while (data->env[i])	//arr
		{
			printf("arr: %s\n", data->env[i]);
			i++;
		}
}