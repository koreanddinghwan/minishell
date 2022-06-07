/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:44:34 by myukang           #+#    #+#             */
/*   Updated: 2022/06/07 12:02:16 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

void	print_error(int errnum)
{
	strerror(errnum);
	exit(EXIT_FAILURE);
}

int main()
{
	print_error(1);
}
