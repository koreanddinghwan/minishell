/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 19:38:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	lexer_tok_free(void *cur)
{
	t_dlst	*node;

	node = (t_dlst *)cur;
	free(GET_TOKEN_BUFFER(node));
	free(node);
}

void	print_input_lst(t_dlst *lst)
{
	while (lst)
	{
		ft_printf("%s\n", ((t_io_cont *)lst->content)->filepath);
		lst = lst->next;
	}
}

void	print_heredoc_lst(t_dlst *lst)
{
	while (lst)
	{
		ft_printf("%s\n", ((t_heredoc_cont *)lst->content)->delimeter);
		lst = lst->next;
	}
}

t_cmd_cont	*init_cmd_cont(void)
{
	t_cmd_cont	*rtn;

	rtn = malloc(sizeof(t_cmd_cont) * 1);
	if (!rtn)
		return (NULL);
	rtn->args = NULL;
	rtn->input_lst = NULL;
	rtn->output_lst = NULL;
	rtn->append_lst = NULL;
	rtn->heredoc_lst = NULL;
	return (rtn);
}

