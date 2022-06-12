#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[100];
	int chg;

	printf("cur : %s\n", getcwd(buf, 100));
	while (1)
	{
		chg = chdir("/Users/baggyumin/Desktop/42cursus/minishell");
		if (chg == -1)
			printf("no dir");
		printf("aft : %s\n", getcwd(buf, 100));
	}
	return 0;
}
