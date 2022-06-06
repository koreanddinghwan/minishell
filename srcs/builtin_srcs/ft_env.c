#include "../../includes/main.h"

typedef struct	s_env
{
	char			*key;
	char			*value;
	int				exist;
	struct s_env	*next;
}	t_env;

void	env()
{
	//env 구조체 초기화 해야함
	t_env	*e;

	while(e)
	{
		if (e->exist)
		{
			if (e->value)
				printf("%s=%s\n", e->key, e->value);
			else
				printf("%s=\n", e->key);
		}
		e = e->next;
	}
}
