/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buf_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:22:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 15:52:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	case_squote(t_token *tok_buf, char c, int *state)
{
		/*
	 * ' 가 들어와있는 상태라면 ' 를 만나기 전까지 모두 일반문자.
	 * */
	if (c == SQUO)
	{
		tok_buf->type = SQUO;
		*state = STATE_NORMAL;
	}
	else
		tok_buf->type = NORM;
}

void	case_dquote(t_token *tok_buf, char c, int *state)
{
	if (c == DQUO)
	{
		tok_buf->type = DQUO;
		*state = STATE_NORMAL;
	}
	else
		tok_buf->type = NORM;
}

void	fill_buf(t_token *tok_buf, char c, int *state)
{
	if (c == DQUO)
	{
		tok_buf->type = DQUO;
		*state = STATE_DQUOTE;
	}
	else if (c == SQUO)
	{
		tok_buf->type = SQUO;
		*state = STATE_SQUOTE;
	}
	else if (c == PIPE)
		tok_buf->type = PIPE;
	else if (c == LESSER)
		tok_buf->type = LESSER;
	else if (c == GREATER)
		tok_buf->type = GREATER;
	else if (c == SPC)
		tok_buf->type = SPC;
	else
		tok_buf->type = NORM;
}

int	token_buf_build(t_data *data)
{
	int		state;
	t_token	*tok_buf;
	char	*str;

	state = STATE_NORMAL;
	tok_buf = data->tok_buf;
	str = data->command;
	while (*str == '\n')
		str++;
	if (!str || !tok_buf)
		return (FAIL);
	while (*str)
	{
		tok_buf->c = *str;
		if (state == STATE_NORMAL)
			fill_buf(tok_buf, *str, &state);
		else if (state == STATE_SQUOTE)
			case_squote(tok_buf, *str, &state);
		else if (state == STATE_DQUOTE)
			case_dquote(tok_buf, *str, &state);
		str++;
		tok_buf++;
	}
	tok_buf->type = END_C;
	tok_buf->c = '\0';
	if (state == STATE_DQUOTE || state == STATE_SQUOTE)
	{
		printf("this shell does not support solo quotes\n");
		data->exit_status = EX_USAGE;
		return (FAIL);
	}
	return (SUCESS);
}
