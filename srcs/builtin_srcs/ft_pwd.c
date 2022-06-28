#include "main.h"

void	ft_pwd(void)
{
	char	*loc;

	loc = (char *)malloc(sizeof(char) * 256);
	if (!getcwd(loc, 256))
		return ;
	else
		printf("%s\n", loc);
	free(loc);
}
