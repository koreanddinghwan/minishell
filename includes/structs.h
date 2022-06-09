/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/09 16:52:29 by myukang          ###   ########.fr       */
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

typedef	struct s_data
{
	char		*command;
	char		*trimmed;
	t_token		*tok_buf;
	t_dlst		*token_lst;
	t_dlst		*env_lst;
	t_dlst		*cmd_order_lst;
}	t_data;

typedef	struct s_cmd_order
{
	int		nth;
	t_dlst	*cmd;
}	t_cmd_order;

#endif
