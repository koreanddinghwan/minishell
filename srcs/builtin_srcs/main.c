/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:34:11 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 10:33:10 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	initialize_main(&data, envp);
	display_bash(&data);
	return (0);
}
