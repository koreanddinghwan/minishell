#include "main.h"

int	check_option(char *option)
{
	int	status;

	status = TRUE;
	if (*option != '-')
		status =  FALSE;
	else
		option++;
	while (*option)
	{
		if (status = FALSE)
			return (FALSE);
		option++;
		if (*option != 'n')
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

void	print_echo(char **argv, int i)
{
	int	newline;

	if (i == 1)
		newline = TRUE;
	else
		newline = FALSE;
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (newline == TRUE)
		write(1, "\n", 1);
}

void	ft_echo(t_data *data, char **argv)
{
	int	option;
	int	argv_count;

	argv_count = get_argv_count(argv);
	if (argv_count == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	option = check_option(argv[1]);
	if (option == TRUE)
		print_echo(argv, 2);
	else
		print_echo(argv, 1);
}
