/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 15:51:57 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	print_args_cmd(char **args)
{
	int		i;

	if (!args)
		return ;
	i = 0;
	ft_printf("========args======\n");
	while (*args)
	{
		ft_printf("%d 번째 args %s\n",i ,*args);
		args++;
		i++;
	}
	ft_printf("==========\n");
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

