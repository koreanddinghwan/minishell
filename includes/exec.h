#ifndef EXEC_H
# define EXEC_H

#include "structs.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int	**set_pipe(int num);
int	get_child_num(t_dlst *cmd_lst);
int	set_redir(t_cmd_cont *cmd);

#endif
