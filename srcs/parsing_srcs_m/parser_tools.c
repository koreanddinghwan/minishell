/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 17:10:16 by myukang          ###   ########.fr       */
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
