#include "main.h"

void    ft_env(t_data   *data)
{
    t_envlst    *lst;

    lst = data->env_lst;
    while (lst)	//lst
		{
			printf("list: %s\n", (char*)lst->env_line);
			lst = lst->next;
		}
    // int         i;
    // i = 0;
	// while (data->env[i])	//arr
	// 	{
	// 		printf("arr: %s\n", data->env[i]);
	// 		i++;
	// 	}
}