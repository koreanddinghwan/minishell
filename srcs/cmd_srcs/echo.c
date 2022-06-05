#include "../../includes/main.h"
#include <string.h>

int main(int ac, char *av[])
{
	int i = 0;

	if (!strcmp(av[1], "echo"))
	{
		if (!strcmp(av[2], "-n"))
		{
			while (av[3][i] != 0)
			{
				if (av[3][i] == '\n')
					break;
				write(1, &av[3][i], 1);
				i++;
			}
		}
		else
			printf("%s\n", av[2]);
	}
}
