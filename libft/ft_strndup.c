/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:53:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 14:00:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int size)
{
	char	*rtn;
	int		i;

	rtn = malloc(sizeof(char) * size);
	i = 0;
	while (src[i] && i < size)
	{
		rtn[i] = src[i];
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
