/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:04:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 21:08:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlst_delete(t_dlst *cur, void (*del)(void *))
{
	t_dlst	*next;
	t_dlst	*back;

	next = cur->next;
	back = cur->back;
	if (next)
		next->back = back;
	if (back)
		back->next = next;
	del(cur);
}
