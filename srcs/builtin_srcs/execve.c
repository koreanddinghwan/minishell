#include "main.h"

void    execve_pull(char **envp)
{
    execve("/bin/echo", 0, envp);
}