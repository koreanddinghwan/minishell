/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 16:12:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	can_slice(t_tmp_head *head)
{
	int		i;
	t_dlst	*start_node;

	i = head->left_index;
	start_node = head->start_node;
	while (i <= head->right_index)
	{
		if (GET_TOKEN_TYPE(start_node) >= 6 && GET_TOKEN_TYPE(start_node) <= 10)
			return (1);
		start_node = start_node->next;
		i++;
	}
	return (0);
}
