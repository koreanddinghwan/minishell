/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:59:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 12:47:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.h"

char	*make_possible_cp(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			break ;
		i++;
	}
	return (ft_strndup(str, i));
}
