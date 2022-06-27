/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:19:33 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 02:50:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_builtin(char *str)
{
	if (ft_strcmp(ECHO, str) == 0)
		return (1);
	if (ft_strcmp(CD, str) == 0)
		return (1);
	if (ft_strcmp(PWD, str) == 0)
		return (1);
	if (ft_strcmp(EXPORT, str) == 0)
		return (1);
	if (ft_strcmp(UNSET, str) == 0)
		return (1);
	if (ft_strcmp(ENV, str) == 0)
		return (1);
	if (ft_strcmp(EXIT, str) == 0)
		return (1);
	return (0);
}

enum e_cmdtype	get_cmdtype(char *cmd)
{
	if (check_builtin(cmd))
		return (E_BUILTIN);
	else
		return (E_CMD);
}
