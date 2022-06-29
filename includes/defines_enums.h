/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_enums.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 20:17:35 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_ENUMS_H
# define DEFINES_ENUMS_H

# define ECHO	"echo"
# define CD		"cd"
# define PWD	"pwd"
# define EXPORT	"export"
# define UNSET	"unset"
# define ENV	"env"
# define EXIT	"exit"
# define SUCESS	1
# define FAIL	0
# define NOFILE ": No such file or directory"
# define ISDIR ": is a directory"
# define DENY ": Permission denied"
# define CMDNOTFOUND ": command not found"

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

# define TRUE 1
# define FALSE 0
# define EXECUTION_FAILURE 1
# define EXECUTION_SUCCESS 0
# define EX_BADUSAGE	2
# define EX_MISCERROR	2
# define EX_RETRYFAIL	124
# define EX_WEXPCOMSUB	125
# define EX_BINARY_FILE	126
# define EX_NOEXEC	126
# define EX_NOINPUT	126
# define EX_NOTFOUND	127
# define EX_SHERRBASE	256	/* all special error values are > this. */
# define EX_BADSYNTAX	257	/* shell syntax error */
# define EX_USAGE	258	/* syntax error in usage */
# define EX_REDIRFAIL	259	/* redirection failed */
# define EX_BADASSIGN	260	/* variable assignment error */
# define EX_EXPFAIL	261	/* word expansion failed */
# define EX_DISKFALLBACK	262	/* fall back to disk command from builtin */
# define FS_EXISTS		0x1
# define FS_EXECABLE 	0x2
#endif
