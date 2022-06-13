/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:11:40 by myukang           #+#    #+#             */
/*   Updated: 2022/06/13 10:08:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "defines_enums.h"
#include "structs.h"
#include <stdio.h>
void			lexer(t_data *data);
t_lexer_token	*lexer_token_init(t_token *tok_buf);
void			lexer_decide_w_type(t_lexer_token *l_tok);
void			lexer_w_converter(t_data *data);
int				check_builtin(char *str);
#endif
