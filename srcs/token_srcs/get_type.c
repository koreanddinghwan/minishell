/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:27:16 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 20:30:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_token_type(char *str)
{
	if (ft_strcmp("|", str) == 0)
		return (PIPE);
	if (ft_strcmp("<", str) == 0)
		return (REDIRECTION_INPUT);
	if (ft_strcmp(">", str) == 0)
		return (REDIRECTION_OUTPUT);
	if (ft_strcmp("<<", str) == 0)
		return (HERE_DOC);
	if (ft_strcmp(">>", str) == 0)
		return (APPENDING_TO);
	if (ft_strcmp("-n", str) == 0)
		return (OPTION);
	if (check_builtin(str))
		return (BUILTIN);
	return (COMMAND);
}

int	check_builtin(char *str)
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

int	is_special_token(int type)
{
	if (type == PIPE)
		return (1);
	if (type == REDIRECTION_OUTPUT)
		return (1);
	if (type == REDIRECTION_INPUT)
		return (1);
	if (type == HERE_DOC)
		return (1);
	if (type == APPENDING_TO)
		return (1);
	return (0);
}
