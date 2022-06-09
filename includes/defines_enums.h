/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_enums.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 20:49:20 by myukang          ###   ########.fr       */
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
	NORM = 0,
	PIPE = '|',
	LESSER = '<',
	GREATER = '>', 
	DQUO = '\"',
	SQUO = '\'',
	SPC = ' ',
};

/*
 * word_type used in lexer
 * */
enum	e_word_type
{
	COMMAND,
	BUILTIN,
	ARG,
	OPTION,
	FIL,
	HERE_DOC,
	APPENDING_TO,
	REDIRECTION_INPUT,
	REDIRECTION_OUTPUT,
}

enum	e_state
{
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_NORMAL
};

#endif
