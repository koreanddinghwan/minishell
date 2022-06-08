/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 17:43:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_data
{
	char		*command;
	t_dlst		*token_lst;
	t_dlst		*env_lst;
	t_dlst		*cmd_order_lst;
}	t_data;

typedef	struct s_token
{
	enum e_type	type;
	char		*value;
	int			nth;
}	t_token;

typedef	struct s_cmd_order
{
	int		nth;
	t_dlst	*cmd;
}	t_cmd_order;

#endif
