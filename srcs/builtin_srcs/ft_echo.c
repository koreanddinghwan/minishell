#include "../../includes/main.h"
#include <string.h>

void	check_option(char *av[], int *flag, int *i)
{
	if (!strcmp(av[*i], "-n"))
	{
		*flag = 1;
		*i = 2;
	}
}

void	ft_echo(int ac, char *av[], int flag)
{
	int	i;

	i = 1;
	check_option(av, &flag, &i);
	while (i < ac)
	{
		write(1, av[i], strlen(av[i]));
		if (i < ac - 1)
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
}

int main(int ac, char *av[])
{
	//ft_echo(ac, av, 0);
	ft_echo(ac, av, 0);
}

