/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:32:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 03:41:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	get_process_num(t_dlst *cmd_lst)
{
	int	i;

	i = 0;
	while (cmd_lst)
	{	
		i++;
		cmd_lst = cmd_lst->next;
	}
	return (i);
}

void	exec(t_data *data)
{
	t_dlst	*cmd_lst;
	int		process_num;

	cmd_lst = data->cmd_lst;
	process_num = get_process_num(cmd_lst);
	ft_printf("process num :%d\n", process_num);
}
