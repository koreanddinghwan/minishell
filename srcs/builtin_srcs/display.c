/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:52 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 00:09:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_bash(t_data *data, int ac, char **av)
{
	char	*line;
	t_envlst	*lst;

	while (1)
	{
		lst = data->env_lst;
		line = readline("bash >");
		if (!line)
		{
			printf(" exit\n");
			return ;
		}
		initialize_data(data, line);
		if (!strcmp(data->command, ENV))
		{
			while (lst)
			{
				printf("%s=", (char *)lst->key);
				printf("%s\n", (char *)lst->value);
				lst = lst->next;
			}
		}
		if (!strcmp(data->command, CD))
		{
			ft_cd(data, "~");
		}
		if (!strcmp(data->command, PWD))
		{
			ft_pwd();
		}
		if (!strcmp(data->command, EXIT))
		{
			ft_exit(ac, av); // 수정: ac는 exit 이후의 av개수(파싱이후), 지금은 exit만 됌
		}
		if (!strcmp(data->command, EXPORT))
		{
			ft_export(data, "key=value");
		}
		if (!strcmp(data->command, UNSET))
		{
			ft_unset(data, "key");
		}
		if (!strcmp(data->command, ECHO))
		{
			int flag = 0; // no option
			//flag = 1; // (-n) option
			if (flag == 0)
				ft_echo(data, flag, "HI");
			else
				ft_echo(data, flag, "-nnn HI");
		}
	}
}
