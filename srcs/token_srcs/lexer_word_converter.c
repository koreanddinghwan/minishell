/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:04:44 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 15:48:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
/*
void	lexer_convert(t_dlst *lexer_t_lst)
{
	//1. command로 시작해, 파이프, 리다이렉션, 히어독, 등등 전까지는 모두 argument여야한다.
	//2. 리다이렉션, appending to 다음은 <, >, >> 모두 파일
	//3. here doc 다음은 delimeter
	//4. pipe 다음은 command
	//4. 모든 command는 builtin이 될수도 있다.
	enum e_word_type	next_type;
	enum e_word_type	cur_type;
	
	next_type = ((t_lexer_token *)lexer_t_lst->next->content)->w_type;
	cur_type = ((t_lexer_token *)lexer_t_lst->content)->w_type;
	if (cur_type == W_COMMAND || cur_type == W_BUILTIN)
	{
		if (!(next_type > 4))
			((t_lexer_token *)lexer_t_lst->next->content)->w_type = W_ARG;
	}
	else if (cur_type == 5 && next_type != W_BUILTIN)
		((t_lexer_token *)lexer_t_lst->next->content)->w_type = W_COMMAND;
	else if (cur_type == 6)
		((t_lexer_token *)lexer_t_lst->next->content)->w_type = W_DELIMETER;
	else if (cur_type >= 7 && cur_type <= 9)
		((t_lexer_token *)lexer_t_lst->next->content)->w_type = W_FILE;
}*/

void	change_type_arg(t_dlst *lst)
{
	enum e_word_type	type;

	type = ((t_lexer_token *)lst->content)->w_type;
	while (lst && !(type > 5))
	{
		if (((t_lexer_token *)lst->content)->w_type == W_SPACE)
		{
			lst = lst->next;
			continue ;
		}
		((t_lexer_token *)lst->content)->w_type = W_ARG;
		lst = lst->next;
		if (!lst)
			return ;
		type = ((t_lexer_token *)lst->content)->w_type;
	}
}

t_dlst	*get_notspace_next_node(t_dlst *cur)
{
	enum e_word_type	type;

	type = ((t_lexer_token *)cur->content)->w_type;
	while (type != W_SPACE)
	{
		cur = cur->next;
		if (!cur)
			return (NULL);
		type = ((t_lexer_token *)cur->content)->w_type;
	}
	return (cur);
}

enum e_word_type	get_type_cmd_blt(t_dlst *node)
{
	if (check_builtin(((t_lexer_token *)node->content)->buffer))
		return (W_BUILTIN);
	else
		return (W_COMMAND);
}

void	convert(t_dlst *cur)
{
	enum e_word_type		type;
	t_dlst			*next_node;

	next_node = get_notspace_next_node(cur);
	if (!next_node)
		return ;
	type = ((t_lexer_token *)next_node->content)->w_type;
	if (type == W_COMMAND || type == W_BUILTIN)
		change_type_arg(next_node);
	else if (type == W_PIPE)
		((t_lexer_token *)next_node->content)->w_type = get_type_cmd_blt(next_node);
	else if (type >= 8 && type <= 10)
		((t_lexer_token *)next_node->content)->w_type = W_FILE;
	else if (type == 7)
		((t_lexer_token *)next_node->content)->w_type = W_DELIMETER;
}

void	lexer_w_converter(t_data *data)
{
	t_dlst	*lexer_t_lst;

	lexer_t_lst = data->lexer_token_lst;
	while (lexer_t_lst)
	{
		convert(lexer_t_lst);
		lexer_t_lst = lexer_t_lst->next;
	}
}
