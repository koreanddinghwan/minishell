/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:01:22 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 13:30:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * syntax_analyzer
 *
 * ++++258 case1
 * bash-3.2$ cat > |
 * bash: syntax error near unexpected token `|'
 * bash-3.2$ $?
 * bash: 258: command not found
 *
 * ++++258 case2
 * bash-3.2$ cat >|
 * bash: syntax error near unexpected token `newline'
 *
 * ++++case3 : closed redirection by pipe  => ignore pipe
 * bash-3.2$ echo >| cat
 * bash-3.2$ ls
 * cat
 * bash-3.2$ cat cat

 * */

#include "syntax_analyzer.h"

int	syntax_analyzer(t_data *data)
{
	t_dlst	*lexer_token_lst;

	if (!data)
		return (FAIL);
	lexer_token_lst = data->lexer_token_lst;

	return (SUCESS);
}
