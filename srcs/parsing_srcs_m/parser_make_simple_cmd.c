/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:31:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/15 16:17:30 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//맨처음 헤드노드 만들기!
t_tmp_head	*tmp_head_init(t_dlst *lst)
{
	t_tmp_head	*rtn;

	rtn = malloc(sizeof(t_tmp_head) * 1);
	if (!rtn)
		return (NULL);
	rtn->left_index = 0;
	rtn->start_node = lst;
	while (lst)
		lst = lst->next;
	rtn->right_index = GET_TOKEN_NTH(lst);
}

/*
 *
 * */

t_tree	*make_simple_tree(t_tmp_head *head)
{
	t_ast_cont	*content;
	t_tree		*rtn;

	content = malloc(sizeof(t_ast_cont) * 1);
	if (!content)
		return (0);
	if (!can_slice(head))
	{
		content = make_content(head->start_node, head->left_index, head->right_index);
		rtn = ft_btree_new(content);
		rtn->left = NULL;
		rtn->right = NULL;
		return (rtn);
	}
	else
	{

	}
	//node->left = make_simple_tree(t_tmp_head *left);
	//node->right = make_simple_tree(t_tmp_head *right);
}

t_tree	*make_simple_cmd(t_dlst *lst)
{
	t_tmp_head	*head;

	head = tmp_head_init(lst);
	return (make_simple_tree(head));
}
