#ifndef	TREE_H
# define TREE_H

# include <stdio.h>
#include "../libft/libft.h"

typedef struct s_ast
{
	int		type; // command? 
	char	*data;	// ls
	int		order;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

#endif
