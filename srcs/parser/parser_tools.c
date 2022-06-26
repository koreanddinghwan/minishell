/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/26 21:40:01 by myukang          ###   ########.fr       */
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

void	delete_multiple_tokens(t_data *data, enum e_word_type type)
{
	t_dlst	*tok_lst;
	t_dlst	*next;

	tok_lst = data->lexer_token_lst;
	while (tok_lst && GET_TOKEN_TYPE(tok_lst) == type)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
	}
}

char	*wget_join(t_dlst *cur, enum e_word_type type)
{
	char	*rtn;
	char	*ex;
	char	*buffer;

	rtn = ft_strdup("");
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	while (cur && GET_TOKEN_TYPE(cur) == type)
	{
		ex = rtn;
		buffer = GET_TOKEN_BUFFER(cur);
		rtn = ft_strjoin(rtn, buffer);
		free(ex);
		cur = cur->next;
	}
	return (rtn);
}

t_dlst	*wget_startpoint(t_dlst *cur, enum e_word_type type)
{
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	while (cur && GET_TOKEN_TYPE(cur) != type)
		cur = cur->next;
	return (cur);
}

int	get_offset(t_dlst *tok_lst, enum e_word_type type)
{
	int		offset;
	t_dlst	*cur;

	offset = 0;
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	cur = tok_lst;
	while (cur && GET_TOKEN_TYPE(cur) != type)
	{
		cur = cur->next;
		offset++;
	}
	while (cur && GET_TOKEN_TYPE(cur) == type)
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
	rtn->iolst = NULL;
	rtn->infile = -1;
	rtn->outfile = -1;
	return (rtn);
}

