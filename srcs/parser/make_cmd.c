/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:49 by myukang           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/24 23:08:54 by myukang          ###   ########.fr       */
=======
/*   Updated: 2022/06/24 21:25:27 by myukang          ###   ########.fr       */
>>>>>>> b2855603c19ec475be8a669159ee2ae09a5a5ddf
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*make_cmd(t_data *data)
{
	t_dlst	*tok_lst;
	t_dlst	*next;
	char	*rtn;
	int		offset;

	tok_lst = data->lexer_token_lst;
	rtn = NULL;
	while (tok_lst && GET_TOKEN_TYPE(tok_lst) == W_SPACE)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
	}
	tok_lst = data->lexer_token_lst;
	offset = get_offset(tok_lst, W_COMMAND);
	tok_lst = wget_startpoint(tok_lst, W_COMMAND);
	if (tok_lst)
		rtn = wget_join(tok_lst, W_COMMAND);
	tok_lst = data->lexer_token_lst;
	while (tok_lst && offset + 1)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
		offset--;
	}
	return (rtn);
}
