/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:32:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/26 17:25:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "execute.h"

int	get_child_num(t_dlst *cmd_lst)
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

	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		set_redir(cmd_lst->content, data);
		cmd_lst = cmd_lst->next;
	}
}
