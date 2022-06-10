/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:32:18 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 15:23:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_token	*make_token(char *str)
{
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (NULL);
	token->type = get_token_type(str);
	token->value = str;
	return (token);
}

t_dlst	*make_token_lst(char *line)
{
	char	**splited;
	t_dlst	*token_lst;

	splited = ft_split(line, '|');
	while (*splited)
	{
		ft_dlst_pushback(&token_lst, ft_dlst_new(make_token(*splited)));
		splited++;
		if (*splited)
			ft_dlst_pushback(&token_lst, ft_dlst_new(make_token("|")));
	}
	return (token_lst);
}

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

void	set_token(t_data *data, char *line)
{
	t_dlst	*cur;

	data->token_lst = make_token_lst(line);
	cur = data->token_lst;
	while (cur)
	{
		stick_quotes(cur);
		convert_arg(cur);
		convert_file(cur);
		cur = cur->next;
	}
	//test print
	while (data->token_lst)
	{
		printf("type : %d, value : %s\n", ((t_token *)(data->token_lst->content))->type, ((t_token *)(data->token_lst->content))->value);
		data->token_lst = data->token_lst->next;
	}
}
