/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:10:34 by myukang           #+#    #+#             */
/*   Updated: 2022/06/21 02:04:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyzer.h"

int	syntax_error_printer(char *str)
{
	ft_printf("bash : syntax error near unexpected token %s\n", str);
	return (FAIL);
}
