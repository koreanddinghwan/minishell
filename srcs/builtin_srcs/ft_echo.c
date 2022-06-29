/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:43:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 12:31:21 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_option(char *option)
{
	int	status;

	status = TRUE;
	if (*option != '-')
		status = FALSE;
	else
		option++;
	while (*option)
	{
		if (status == FALSE)
			break ;
		option++;
		if (*option && *option != 'n')
			status = FALSE;
	}
	return (status);
}

int	get_argv_count(char **argv)
{
	int	c;

	c = 0;
	while (*argv)
	{
		c++;
		argv++;
	}
	return (c);
}

void	print_echo(char **argv, int option)
{
	int	i;

	if (option == TRUE)
		i = 2;
	else
		i = 1;
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		if (argv[i])
			write(1, " ", 1);
	}
	if (option == FALSE)
		write(1, "\n", 1);
}

void	ft_echo(t_data *data, char **argv)
{
	int	option;
	int	argv_count;

	if (!data)
		return ;
	argv_count = get_argv_count(argv);
	if (argv_count == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	option = check_option(argv[1]);
	print_echo(argv, option);
}
