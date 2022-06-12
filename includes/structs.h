/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:13:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "defines_enums.h"
# include "libft.h"

typedef	struct s_token
{
	enum e_char_type	type;
	char				c;
}	t_token;

typedef	struct s_lexer_token
{
	enum e_word_type	w_type;
	char				*buffer;
	int					buf_len;
}	t_lexer_token;

typedef	struct s_data
{
	char		*command;
	char		*trimmed;
	t_token		*tok_buf;
	t_dlst		*lexer_token_lst;
	t_dlst		*env_lst;
	char		**env;
	t_tree		*myukang_tree;
	t_dlst		*cmd_order_lst;
}	t_data;

typedef struct	s_tree_cont
{
	enum e_word_type	type;
	char				*args;
}	t_tree_cont;

#endif
