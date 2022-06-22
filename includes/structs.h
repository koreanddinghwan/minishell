/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/19 18:28:40 by myukang          ###   ########.fr       */
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
	t_token		*tok_buf;
	t_dlst		*lexer_token_lst;
	t_envlst	*env_lst;
	char		**env;
	size_t		env_size;
	t_dlst		*cmd_lst;
	int			exit_status;
}	t_data;

enum e_cmdtype
{
	E_CMD,
	E_BUILTIN,
};

typedef struct	s_io_cont
{
	int		fd[2];
	char	*filepath;
}	t_io_cont;

typedef struct	s_heredoc_cont
{
	char	*delimeter;
}	t_heredoc_cont;

typedef struct	s_cmd_cont
{
	enum e_cmdtype	cmdtype;
	char			*cmd;
	char			**args;
	t_dlst			*input_lst;
	t_dlst			*output_lst;
	t_dlst			*append_lst;
	t_dlst			*heredoc_lst;
}	t_cmd_cont;

#endif
