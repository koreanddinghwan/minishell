/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_enums.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 02:02:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_ENUMS_H
# define DEFINES_ENUMS_H

/*
 * PIPE -> '|', REDIRECTION_OUTPUT -> '>', REDIRECTION_INPUT -> '<'
 * HERE_DOC -> <<, APPENDING_TO -> >>
*/

/*
 * builtin string literals
 * */
# define	ECHO	"echo"
# define	CD		"cd"
# define	PWD		"pwd"
# define	EXPORT	"export"
# define	UNSET	"unset"
# define	ENV		"env"
# define	EXIT	"exit"
# define	SUCESS	1
# define	FAIL	0
/*
 * char_type used in tokenizer
 * */
enum	e_char_type
{
	NORM = 1,
	PIPE = '|',
	LESSER = '<',
	GREATER = '>', 
	DQUO = '\"',
	SQUO = '\'',
	SPC = ' ',
	END_C = '\0'
};

/*
 * word_type used in lexer
 * */
enum	e_word_type
{
	W_COMMAND = 0,
	W_BUILTIN = 1,
	W_ARG = 2,
	W_SPACE = 3,
	W_OPTION = 4,
	W_FILE = 5,
	W_PIPE = 6,
	W_HERE_DOC = 7,
	W_APPENDING_TO = 8,
	W_REDIRECTION_INPUT = 9,
	W_REDIRECTION_OUTPUT = 10,
	W_DELIMETER = 11
};

enum	e_state
{
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_NORMAL
};

# define GET_TOKEN_TYPE(lst) (((t_lexer_token *)lst->content)->w_type)
# define GET_TOKEN_BUFFER(lst) (((t_lexer_token *)lst->content)->buffer)
# define GET_TOKEN_NTH(lst) (((t_lexer_token *)lst->content)->nth)
# define GET_CMD(lst) (((t_cmd_cont *)lst->content)->cmd)
# define GET_ARGS(lst) (((t_cmd_cont *)lst->content)->args)
# define GET_INPUT_LIST(lst) (((t_cmd_cont *)lst->content)->input_lst)
# define GET_OUTPUT_LIST(lst) (((t_cmd_cont *)lst->content)->output_lst)
# define GET_APP_LIST(lst) (((t_cmd_cont *)lst->content)->append_lst)
# define GET_HEREDOC_LIST(lst) (((t_cmd_cont *)lst->content)->heredoc_lst)
# define GET_FILEPATH(lst) (((t_io_cont *)lst->content)->filepath)
# define GET_DELIMETER(lst) (((t_heredoc_cont *)lst->content)->delimeter)

#define TRUE 1
#define FALSE 0

/* Values that can be returned by execute_command (). */
#define EXECUTION_FAILURE 1
#define EXECUTION_SUCCESS 0

/* Usage messages by builtins result in a return status of 2. */
#define EX_BADUSAGE	2

#define EX_MISCERROR	2

/* Special exit statuses used by the shell, internally and externally. */
#define EX_RETRYFAIL	124
#define EX_WEXPCOMSUB	125
#define EX_BINARY_FILE	126
#define EX_NOEXEC	126
#define EX_NOINPUT	126
#define EX_NOTFOUND	127

#define EX_SHERRBASE	256	/* all special error values are > this. */

#define EX_BADSYNTAX	257	/* shell syntax error */
#define EX_USAGE	258	/* syntax error in usage */
#define EX_REDIRFAIL	259	/* redirection failed */
#define EX_BADASSIGN	260	/* variable assignment error */
#define EX_EXPFAIL	261	/* word expansion failed */
#define EX_DISKFALLBACK	262	/* fall back to disk command from builtin */
#endif
