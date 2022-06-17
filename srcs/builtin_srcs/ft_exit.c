#include "builtin.h"
#include <string.h>
#include <stdlib.h>

void	ft_exit(int ac, char *av[])
{
	if (ac == 1)
	{
		printf("exit\n");
		exit(0);
	}
	else if (ac == 2)
	{
		int num;
		num = atoi(av[1]);
		printf("exit\n");
		exit(num);
	}
	else
		printf("miniminisherl: exit: too many arguments\n");
}
