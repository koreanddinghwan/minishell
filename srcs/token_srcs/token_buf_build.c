/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buf_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:22:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 20:54:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"


void	fill_buf(t_token *buf, char c, int *state)
{
	if (c == DQUO)
		
}

void	token_buf_build(t_token *buf, char *str)
{
	int	state;

	state = STATE_NORMAL;
	while (*str)
	{
		if (state == STATE_NORMAL)
			fill_buf(buf, *str, &state);
		else if (state == STATE_SQUOTE)
		{
		}
		else if (state == STATE_DQUOTE)
		{
		}
		str++;
	}
	*buf = ;
}
