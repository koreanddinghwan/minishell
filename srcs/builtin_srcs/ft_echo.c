#include "builtin.h"
#include <string.h>

char	*last_null(char *str)
{
	char *copy;

	copy = strdup(str);
	while (*copy)
	{
		if (*copy == ' ')
		{
			copy = str;
			break;
		}
		printf("|%c|\n", *copy);
		copy++;
	}
	copy = 0;
	return (copy);
}

void	ft_echo(t_data *data, int flag, char *str)
{
	(void) data;
	if (flag == 1)
		last_null(str);
	while (str)
	{
		printf("%c", *str);
		if (*str == 0)
			write(1, " ", 1);
		str++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	free(str);
}
