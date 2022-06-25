#include "parser.h"
#include <stdio.h>

int	check_redirection(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (GET_TOKEN_TYPE(tok_lst) >= 7 && GET_TOKEN_TYPE(tok_lst) <= 10)
			return (1);
		if (GET_TOKEN_TYPE(tok_lst) == W_PIPE)
			return (0);
		tok_lst = tok_lst->next;
	}
	return (0);
}

t_io_cont	*make_io_cont(t_data *data, t_dlst *tok_lst, enum e_word_type type)
{
	t_io_cont	*rtn;
	t_dlst		*cur;
	t_dlst		*next;
	int			offset;

	cur = tok_lst;
	rtn = NULL;
	offset = get_offset(cur, type);
	cur = wget_startpoint(cur, type);
	if (cur)
	{
		rtn = malloc(sizeof(t_io_cont) * 1);
		if (!rtn)
			return (NULL);
		rtn->filepath = wget_join(cur, type);
		rtn->type = type;
	}
	while (tok_lst && offset)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
		offset--;
	}
	return (rtn);
}

t_dlst	*make_iolst(t_data *data)
{
	t_dlst		*rtn;
	t_dlst		*tok_lst;
	t_io_cont	*new;

	rtn = NULL;
	delete_multiple_tokens(data, W_SPACE);
	tok_lst = data->lexer_token_lst;
	while (check_redirection(tok_lst))
	{
		while (tok_lst && (GET_TOKEN_TYPE(tok_lst) < 7 || GET_TOKEN_TYPE(tok_lst) > 10))
			tok_lst = tok_lst->next;
		if (tok_lst)
		{
			new = make_io_cont(data, tok_lst, GET_TOKEN_TYPE(tok_lst));
			if (new)
				ft_dlst_pushback(&rtn, ft_dlst_new(new));
			tok_lst = data->lexer_token_lst;
		}
	}
	return (rtn);
}
