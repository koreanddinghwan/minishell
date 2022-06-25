/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 21:41:13 by myukang          ###   ########.fr       */
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

void	printleft(t_data *data)
{
	t_dlst	*lst;

	lst = data->lexer_token_lst;
	printf("=====================left tokens===================\n");
	while (lst)
	{
		printf("type : %d, buffer : %s\n", GET_TOKEN_TYPE(lst), GET_TOKEN_BUFFER(lst));
		lst = lst->next;
	}
	printf("===================================================\n");
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
		cur_cmd_cont->cmd = make_cmd(data);
		cur_cmd_cont->cmdtype = get_cmdtype(cur_cmd_cont->cmd);
		if (cur_cmd_cont->cmdtype != E_BUILTIN)
			cur_cmd_cont->cmd = path_finder(data->env_lst, cur_cmd_cont->cmd);
		cur_cmd_cont->args = make_args(data, cur_cmd_cont->cmd);
		cur_cmd_cont->nth = n;
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
	print_cmddata(data);
}
