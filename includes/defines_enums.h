/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_enums.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 14:00:51 by myukang          ###   ########.fr       */
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

#endif
