#include "main.h"

void	ft_pwd()
{
	char	*loc; // ulimit -n

	loc = (char *)malloc(sizeof(char) * 256);
	if (!getcwd(loc, 256))
		return ;
	else
		printf("current loc: %s\n", loc);
	free(loc);
}