/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/22 20:44:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*tmp*/
void	lexer_token_printer(t_data *data)
{
	t_dlst	*lst;

	lst = data->lexer_token_lst;
	while (lst)
	{
		printf("nth : %d, type : %d , buffer : %s\n",  GET_TOKEN_NTH(lst), GET_TOKEN_TYPE(lst), GET_TOKEN_BUFFER(lst));
		lst = lst->next;
	}
}

t_lexer_token	*lexer_space_token(void)
{
	t_lexer_token	*rtn;

	rtn = ft_calloc(sizeof(t_lexer_token), 1);
	rtn->buf_len = 1;
	rtn->buffer = ft_calloc(sizeof(char), 2);
	rtn->buffer[0] = ' ';
	rtn->buffer[1] = '\0';
	rtn->w_type = W_SPACE;
	return (rtn);
}

void	lexer_token_lst_init(t_data *data)
{
	t_token			*tok_buf;
	t_lexer_token	*l_tok;
	int				i;
	int				space_add;

	tok_buf = data->tok_buf;
	space_add = 0;
	while (tok_buf->type != END_C)
	{
		if (tok_buf->type == SPC && space_add == 1)
		{
			tok_buf++;
			continue ;
		}
		else if (tok_buf->type == SPC && space_add == 0)
		{
			l_tok = lexer_space_token();
			ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
			tok_buf++;
			space_add = 1;
			continue ;
		}
		space_add = 0;
		i = 0;
		l_tok = lexer_token_init(tok_buf);
		ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
		while (i < l_tok->buf_len && tok_buf->type != END_C)
		{
			tok_buf++;
			i++;
		}
	}
}

void	lexer_add_nth(t_data *data)
{
	t_dlst	*lst;
	int		i;

	lst = data->lexer_token_lst;
	i = 0;
	while (lst)
	{
		GET_TOKEN_NTH(lst) = i;
		lst = lst->next;
		i++;
	}
}

void	set_clobber(t_data *data, t_dlst *lst)
{
	t_dlst	*next;
	char	*buffer;

	while (lst)
	{
		if (lst && GET_TOKEN_TYPE(lst) == W_REDIRECTION_OUTPUT)
		{
			next = lst->next;
			if (next)
			{
				buffer = GET_TOKEN_BUFFER(next);
				if (ft_strcmp("|", buffer) == 0)
				{
					ft_dlst_delete(next, &data->lexer_token_lst, lexer_tok_free);
					lst = data->lexer_token_lst;
					continue ;
				}
			}
		}
		lst = lst->next;
	}
}

int	lexer(t_data *data)
{
	lexer_token_lst_init(data);
	set_clobber(data, data->lexer_token_lst);
	if (syntax_analyzer(data) == FAIL)
		return (FAIL);
	lexer_w_converter(data);
	replacer(data);
	lexer_add_nth(data);
	ft_printf("after convert\n");
	lexer_token_printer(data);
	return (SUCESS);
}
