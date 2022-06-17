/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/18 01:00:03 by myukang          ###   ########.fr       */
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
	int					nth;
}	t_lexer_token;

typedef	struct s_data
{
	char		*command;
	char		*trimmed;
	t_token		*tok_buf;
	t_dlst		*lexer_token_lst;
	t_envlst	*env_lst;
	char		**env;
	t_dlst		*cmd_lst;
	int			exit_status;
}	t_data;

#endif
