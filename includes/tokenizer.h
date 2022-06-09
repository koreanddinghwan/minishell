/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:10 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 16:56:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "structs.h"
# include "defines_enums.h"
# include "libft.h"
//tmp
# include "tmp.h"

void	initialize_data(t_data *data, char *line);
void	tokenizer(t_data *data);
void	token_buf_build(t_data *data);


void	make_token_lst(char *line);
int		get_token_type(char c);
int		check_builtin(char *str);
int		is_special_token(int type);
#endif