/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:12:35 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 15:13:04 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	lexer_tok_free(void *cur)
{
	t_dlst	*node;

	node = (t_dlst *)cur;
	free(GET_TOKEN_BUFFER(node));
	free(node);
}
