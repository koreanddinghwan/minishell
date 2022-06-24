#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void    execve_com(char *com, int fd[2], int flag, char **envp)
{
        pid_t pid;
        pid = fork();

        char *ag[] = {com, NULL};

        if (pid == 0)
        {
                close(fd[0]);
                printf("dup2(OUT)\n");
                dup2(fd[1], STDOUT_FILENO);
                execve(com, ag, envp);
        }
        // waitpid(pid, 0, 0);
        if (flag == 0)
        {
                close(fd[1]);
                printf("dup2(IN)\n");
                dup2(fd[0], STDIN_FILENO);
                
        }
        else if (flag == 1)
        {
                close(fd[1]);
                close(fd[0]);
        }
}

int main(int ac, char *av[], char **envp)
{
        char ls[] = "/bin/ls";
        char cat[] = "/bin/cat";
        char wc[] = "/usr/bin/wc";
        char sort[] = "/usr/bin/sort";
        char env[] = "/usr/bin/env";
        char head[] = "/usr/bin/head";
        char pwd[] = "/bin/pwd";
        int fd[2];
        int n_fd[2];
        int status;
        // int pipe_flag = 1;
        int pipe_flag = 0;

        pipe(fd);
        // pipe(n_fd);

        execve_com(ls, fd, pipe_flag, envp);           // STDIN이 들어오는 명령어는 dup2 STDIN_FILENO를 쓰면 안됌
        // --pipe_flag;                                    // STDIN이 들어오지않는 명령어는 dup2사용
        close(fd[1]);

        // execve_com(ls, n_fd, pipe_flag, envp);
        // ++pipe_flag;
        // close(n_fd[0]);
        
        execve_com(wc, fd, pipe_flag, envp);
        close(fd[0]);
        printf("%d %d\n", fd[0], fd[1]);

        // int t_fd[2] = {fd[0], n_fd[1]};
        // execve_com(wc, t_fd, pipe_flag, envp);
        // close(fd[0]);
        // close(n_fd[1]);
        while (wait(&status) > 0)
        {
                printf("-------------------\n");
        }
}