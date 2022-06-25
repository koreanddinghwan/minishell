/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 19:49:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"
#include "tmp.h"

/*
 * cmd(builtin)  args | cmd(builtin) args
 * */
void	get_lst_size(t_cmd_cont *cur)
{
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
		cur_cmd_cont->iolst = make_iolst(data);
		cur_cmd_cont->heredoc_lst = make_heredoc_lst(data);
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
	if (!data)
		return ;
	make_cmdcont(data);
	data->cmd_size = ft_dlst_size(data->cmd_lst);
	ft_printf("cmd size%d\n", data->cmd_size);
	print_cmddata(data);
}
