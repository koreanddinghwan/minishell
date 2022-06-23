/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:59:02 by myukang           #+#    #+#             */
/*   Updated: 2022/06/23 20:48:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	join_args_next(t_dlst **tok_lst, t_dlst *next,
			char **rtn, char **buffer)
{
	*tok_lst = next;
	*rtn = *buffer;
	*buffer = ft_strdup("");
}

void	join_args_set(t_data *data, t_dlst **tok_lst,
			t_dlst *next, char **buffer)
{
	char	*exbuffer;
	t_dlst	*cur;

	cur = *tok_lst;
	exbuffer = *buffer;
	*buffer = ft_strjoin(*buffer, GET_TOKEN_BUFFER(cur));
	free(exbuffer);
	ft_dlst_delete(*tok_lst, &data->lexer_token_lst, lexer_tok_free);
	*tok_lst = next;
}

void	join_args(char **rtn, t_data *data)
{
	int					i;
	t_dlst				*next;
	t_dlst				*tok_lst;
	enum e_word_type	type;
	char				*buffer;

	i = 1;
	buffer = ft_strdup("");
	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		type = GET_TOKEN_TYPE(tok_lst);
		next = tok_lst->next;
		if (type == W_PIPE || type == W_SPACE)
			ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		if (type == W_PIPE)
			break ;
		else if (type == W_SPACE)
			join_args_next(&tok_lst, next, &(rtn[i++]), &buffer);
		else
			join_args_set(data, &tok_lst, next, &buffer);
	}
	rtn[i++] = buffer;
	rtn[i] = NULL;
}

int	get_args_count(t_dlst *tok_lst)
{
	int	i;

	i = 0;
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (i);
		else if (GET_TOKEN_TYPE(tok_lst) == W_ARG)
		{
			i++;
			while (tok_lst && GET_TOKEN_TYPE(tok_lst) == W_ARG)
				tok_lst = tok_lst->next;
		}
		else
			tok_lst = tok_lst->next;
	}
	return (i);
}

char	**make_args(t_data *data)
{
	char	**rtn;
	int		count;
	t_dlst	*tok_lst;

	if (!data->lexer_token_lst)
		return (NULL);
	count = get_args_count(data->lexer_token_lst);
	ft_printf("args : %d\n", count);
	rtn = malloc(sizeof(char *) * (count + 2));
	rtn[0] = NULL;
	tok_lst = data->lexer_token_lst;
	if (tok_lst && GET_TOKEN_TYPE(tok_lst) == W_SPACE)
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
	join_args(rtn, data);
	print_args_cmd(rtn);
	return (rtn);
}
