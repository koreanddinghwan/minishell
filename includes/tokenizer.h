/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:10 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 18:24:28 by myukang          ###   ########.fr       */
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
void	tokenizer(t_data *data, char *line);
t_dlst	*make_token_lst(char *line);
int		get_token_type(char *str);
int		check_builtin(char *str);

#endif
