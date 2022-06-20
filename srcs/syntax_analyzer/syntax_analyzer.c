/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:01:22 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 15:45:19 by myukang          ###   ########.fr       */
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
	if (!lexer_token_lst)
		return (FAIL);
	//1. '>|' -> '>' not '> |'
	//-> noclobber 옵션을 무시하는 리다이렉션임
	//무슨 의미냐면, set -o noclobber를 하면 일반적인 > 리다이렉션으로는 존재하는 파일을 덮어씌우지 못함. 하지만 >|를 사용하면 덮어씌우기가 가능해짐
	//2. '> |' -> syntax error in |
	//3. echo t <| test ->syntax error in |
	//4. echo t < | test -> ''
	//
	return (SUCESS);
}
