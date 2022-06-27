/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:28:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 00:30:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getter.h"

t_lexer_token *get_ltok_cont(t_dlst *lst)
{
	return ((t_lexer_token *)lst->content);
}

t_cmd_cont	*get_cmd_cont(t_dlst *lst)
{
	return ((t_cmd_cont *)lst->content);
}
