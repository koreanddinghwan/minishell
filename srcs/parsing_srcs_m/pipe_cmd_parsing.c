/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:27 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 20:59:44 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		find_next(t_dlst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (GET_TOKEN_TYPE(lst) >= W_HERE_DOC && GET_TOKEN_TYPE(lst) <= 10)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

void	simple_cmd(t_data *data, t_dlst *lst)
{
	int	limit;
	int	cur_nth;

	cur_nth = 0;
	while (lst)
	{
		limit = find_next(lst);

	}
}
