#include "../../includes/main.h"

void	ft_pwd()
{
	char	*loc; // ulimit -n

	loc = (char *)malloc(sizeof(char) * 256);
	if (!getcwd(loc, 256))
		return ;
	else
		printf("%s\n", loc);
	free(loc);
}

int main()
{
	ft_pwd();
}
