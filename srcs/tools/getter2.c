/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:48:50 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 20:49:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getter.h"

t_io_cont	*get_io_cont(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((t_io_cont *)lst->content);
}

t_dlst	*get_io_list(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return (get_cmd_cont(lst)->iolst);
}
