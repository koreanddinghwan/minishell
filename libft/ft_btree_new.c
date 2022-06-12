/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:07:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/12 13:24:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_btree_new(void	*content)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
