/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:08:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 17:39:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	simple_cmd(t_data *data, t_dlst *tok_lst)
{
	t_cmd_cont	*cur_cmd_cont;

	cur_cmd_cont = init_cmd_cont();
	cur_cmd_cont->input_lst = make_input_lst(data, tok_lst);
	cur_cmd_cont->output_lst = make_output_lst(data);
	cur_cmd_cont->heredoc_lst = make_heredoc_lst(data);
	cur_cmd_cont->append_lst = make_append_lst(data);
//	cur_cmd_cont->cmd =  
	ft_dlst_pushback(&data->cmd_lst, ft_dlst_new(cur_cmd_cont));
	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		ft_printf("%d\n", GET_TOKEN_TYPE(tok_lst));
		ft_printf("%s\n", GET_TOKEN_BUFFER(tok_lst));
		tok_lst = tok_lst->next;
	}
}
