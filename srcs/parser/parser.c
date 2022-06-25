/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 15:15:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

/*
 * cmd(builtin)  args | cmd(builtin) args
 * */
void	get_lst_size(t_cmd_cont *cur)
{
	cur->input_n = ft_dlst_size(cur->input_lst);
	cur->output_n = ft_dlst_size(cur->output_lst);
	cur->append_n = ft_dlst_size(cur->append_lst);
	cur->heredoc_n = ft_dlst_size(cur->heredoc_lst);
}

void	make_cmdcont(t_data *data)
{
	t_cmd_cont	*cur_cmd_cont;
	int			n;

	n = 0;
	while (data->lexer_token_lst)
	{
		cur_cmd_cont = init_cmd_cont();
		cur_cmd_cont->input_lst = make_input_lst(data);
		cur_cmd_cont->output_lst = make_output_lst(data);
		cur_cmd_cont->heredoc_lst = make_heredoc_lst(data);
		cur_cmd_cont->append_lst = make_append_lst(data);
		cur_cmd_cont->cmd = make_cmd(data);
		cur_cmd_cont->cmdtype = get_cmdtype(cur_cmd_cont->cmd);
		if (cur_cmd_cont->cmdtype != E_BUILTIN)
			cur_cmd_cont->cmd = path_finder(data->env_lst, cur_cmd_cont->cmd);
		cur_cmd_cont->args = make_args(data, cur_cmd_cont->cmd);
		cur_cmd_cont->nth = n;
		get_lst_size(cur_cmd_cont);
		ft_dlst_pushback(&data->cmd_lst, ft_dlst_new(cur_cmd_cont));
		n++;
	}
}

void	parser(t_data *data)
{
	t_dlst	*tok_lst;

	if (!data)
		return ;
	tok_lst = data->lexer_token_lst;
	make_cmdcont(data);
}
