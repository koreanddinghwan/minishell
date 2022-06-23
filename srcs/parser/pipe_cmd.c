/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:27 by myukang           #+#    #+#             */
/*   Updated: 2022/06/23 20:48:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * cmd < io1 a > io2 b
 * --> cmd a b < io1 > io2
 *  1. ceck io list and delete it from
 * --> input_lst io1
 * --> output_lst io2
 *
 * */

void	pipe_cmd(t_data *data)
{
	t_cmd_cont	*cur_cmd_cont;

	while (data->lexer_token_lst)
	{
		cur_cmd_cont = init_cmd_cont();
		cur_cmd_cont->input_lst = make_input_lst(data);
		cur_cmd_cont->output_lst = make_output_lst(data);
		cur_cmd_cont->heredoc_lst = make_heredoc_lst(data);
		cur_cmd_cont->append_lst = make_append_lst(data);
		cur_cmd_cont->cmd = make_cmd(data);
		cur_cmd_cont->args = make_args(data);
		ft_dlst_pushback(&data->cmd_lst, ft_dlst_new(cur_cmd_cont));
	}
	t_dlst *tok_lst = data->lexer_token_lst;
	ft_printf("==left tokens==\n");
	while (tok_lst)
	{
		ft_printf("%d\n", GET_TOKEN_TYPE(tok_lst));
		ft_printf("%s\n", GET_TOKEN_BUFFER(tok_lst));
		tok_lst = tok_lst->next;
	}
	ft_printf("=========\n");
}
