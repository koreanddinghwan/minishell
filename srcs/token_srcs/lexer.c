/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 20:21:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * lexer defines the tokens type, nth
 * */
void	change_type_arg(t_dlst *lst)
{
	while (lst && !is_special_token(((t_token *)lst->content)->type))
	{
		((t_token *)lst->content)->type = ARG;
		lst = lst->next;
	}
}

/*
 * builtin 함수나 command명령어를 인식한 경우, 다음 토큰이 옵션이 아니면 해당 그 토큰을 arg로 변경
 * */
void	convert_arg(t_dlst *cur)
{
	if ((((t_token *)cur->content)->type == BUILTIN || (((t_token *)cur->content)->type == COMMAND)))
	{
		if (cur->next)
		{
			if (((t_token *)cur->next->content)->type == OPTION)
				change_type_arg(cur->next->next);
			else
				change_type_arg(cur->next);
		}
	}
}

/*
 * 따옴표와 홑따옴표를 가진 경우, 원본 line 보고 체크해야함....
 * */
void	stick_quotes(t_dlst *cur)
{
	if (cur)
		return ;
}

/*
 * 리다이렉션과 >> 를 인식한 경우. 다음 토큰은 파일이어야함
 * */
void	convert_file(t_dlst *cur)
{
	if (((t_token *)cur->content)->type == REDIRECTION_INPUT ||  ((t_token *)cur->content)->type == REDIRECTION_OUTPUT || ((t_token *)cur->content)->type == APPENDING_TO)
	{
		if (cur->next)
		{
			((t_token *)cur->next->content)->type = FIL;
		}
	}
}
