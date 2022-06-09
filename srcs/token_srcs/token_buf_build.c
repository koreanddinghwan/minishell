/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buf_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:22:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 16:56:57 by myukang          ###   ########.fr       */
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

void	token_buf_build(t_data *data)
{
	int		state;
	t_token	*tok_buf;
	char	*str;

	state = STATE_NORMAL;
	tok_buf = data->tok_buf;
	str = data->trimmed;
	if (!str || !tok_buf)
		return ;
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
	//마지막에 널문자 넣어주도록
	tok_buf->type = END_C;
	tok_buf->c = '\0';
	/*
	 * 닫히지 않은 상태에서 끝나면 에러처리.
	 * */
	if (state == STATE_DQUOTE || state == STATE_SQUOTE)
	{
		printf("error\n");
	}
}
