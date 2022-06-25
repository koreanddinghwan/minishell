/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmddata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:22:50 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 19:57:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <stdio.h>

void	print_args(t_dlst *cmdlst)
{
	char	**args;
	int		i;

	args = GET_ARGS(cmdlst);
	if (!args)
		return ;
	i = 0;
	while (*args)
	{
		printf("%d 번째 args %s\n",i ,*args);
		args++;
		i++;
	}
}


void	print_heredoclst(t_dlst *cmdlst)
{
	t_dlst	*lst;

	lst = GET_HEREDOC_LIST(cmdlst);
	while (lst)
	{
		ft_printf("heredoc lst : %s\n", GET_HEREDOC_LIST(lst));
		lst = lst->next;
	}

}

void	print_iolst(t_dlst *cmdlst)
{
	t_dlst	*iolst;

	iolst = GET_IOLIST(cmdlst);
	while (iolst)
	{
		ft_printf("type : %d, path : %s\n",  GET_FILEPATH(iolst));
		iolst = iolst->next;
	}
}

void	print_cmddata(t_data *data)
{
	t_dlst	*cmdlst;
	int		i;

	cmdlst = data->cmd_lst;
	i = 1;
	while (cmdlst)
	{
		ft_printf("#######\n");
		ft_printf("#######\n");
		ft_printf("%d번째 데이터\n", i);
		ft_printf("cmd : %s\n", GET_CMD(cmdlst));

		print_args(cmdlst);
		print_iolst(cmdlst);
		print_heredoclst(cmdlst);
		cmdlst = cmdlst->next;
		i++;
	}
}
