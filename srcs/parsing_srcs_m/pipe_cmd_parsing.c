/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:27 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 13:53:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * cmd < io1 a > io2 b
 * --> cmd a b < io1 > io2
 *  1. ceck io list and delete it from
 * --> input_lst io1
 * --> output_lst io2
 *
 * */

void	simple_cmd(t_data *data, t_dlst *tok_lst)
{
	
}
