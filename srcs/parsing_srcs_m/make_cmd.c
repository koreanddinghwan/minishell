/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:49 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 21:19:22 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*make_cmd(t_data *data)
{
	t_dlst	*tok_lst;
	t_dlst	*next;
	char	*rtn;

	tok_lst = data->lexer_token_lst;
	while (tok_lst && GET_TOKEN_TYPE(tok_lst) == W_SPACE)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
	}
	if (tok_lst)
		rtn = ft_strdup(GET_TOKEN_BUFFER(tok_lst));
	else
		rtn = NULL;
	ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
	ft_printf("cmd : %s\n", rtn);
	return (rtn);
}
