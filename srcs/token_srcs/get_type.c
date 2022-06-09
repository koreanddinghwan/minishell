/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:27:16 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 19:35:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_token_type(char c)
{
	if (c == '|')
		return (PIPE);
	if (c == '<')
		return (LESSER);
	if (c == '>')
		return (GREATER);
	if (c == '\"')
		return (DQUO);
	if (c == '\'')
		return (SQUO);
	return (NORM);
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
