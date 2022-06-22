/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 20:42:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

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
	printf("========args======\n");
	while (*args)
	{
		printf("%d 번째 args %s\n",i ,*args);
		args++;
		i++;
	}
	printf("==========\n");
}

char	*wfile_join(t_dlst *cur)
{
	char	*rtn;
	char	*ex;
	char	*buffer;

	rtn = ft_strdup("");
	while (cur && GET_TOKEN_TYPE(cur) == W_FILE)
	{
		ex = rtn;
		buffer = GET_TOKEN_BUFFER(cur);
		rtn = ft_strjoin(rtn, buffer);
		free(ex);
		cur = cur->next;
	}
	return (rtn);
}

t_dlst	*wfile_startpoint(t_dlst *cur)
{
	while (cur && GET_TOKEN_TYPE(cur) != W_FILE)
		cur = cur->next;
	return (cur);
}

int	get_offset(t_dlst *tok_lst)
{
	int		offset;
	t_dlst	*cur;

	offset = 0;
	cur = tok_lst;
	while (cur && GET_TOKEN_TYPE(cur) != W_FILE)
	{
		cur = cur->next;
		offset++;
	}
	while (cur && GET_TOKEN_TYPE(cur) == W_FILE)
	{
		cur = cur->next;
		offset++;
	}
	return (offset);
}

t_cmd_cont	*init_cmd_cont(void)
{
	t_cmd_cont	*rtn;

	rtn = malloc(sizeof(t_cmd_cont) * 1);
	if (!rtn)
		return (NULL);
	rtn->cmd = NULL;
	rtn->args = NULL;
	rtn->input_lst = NULL;
	rtn->output_lst = NULL;
	rtn->append_lst = NULL;
	rtn->heredoc_lst = NULL;
	return (rtn);
}

