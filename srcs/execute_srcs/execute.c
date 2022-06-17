/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 23:32:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute(t_data *data)
{
	t_dlst	*cmd_lst;

	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		cmd_lst = cmd_lst->next;
	}
}
