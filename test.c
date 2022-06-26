#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void    execve_com(char *com, int fd[2][2], int flag, char **envp, int i)
{
        pid_t pid;
        pid = fork();

        char *ag[] = {com, NULL};

        if (pid == 0)
        {
                if (i == 0)
                {
                        close(fd[0][0]);
                        close(fd[1][0]);
                        close(fd[1][1]);
                        dup2(fd[0][1], STDOUT_FILENO);
                }
                if (i == 1)
                {
                        close(fd[1][0]);
                        close(fd[0][1]);
                        dup2(fd[0][0], STDIN_FILENO);
                        dup2(fd[1][1], STDOUT_FILENO);
                }
                if (i == 2)
                {
                        close(fd[1][1]);
                        close(fd[0][0]);
                        close(fd[0][1]);
                        dup2(fd[1][0], STDIN_FILENO);
                }       
                execve(com, ag, envp);
        }
        // waitpid(pid, 0, 0);
        // if (flag == 0)
        // {
        //         close(fd[1]);
        //         printf("dup2(IN)\n");
        //         dup2(fd[0], STDIN_FILENO);
        //         close(fd[0]);
                
        // }
        // else if (flag == 1)
        // {
        //         close(fd[1]);
        //         close(fd[0]);
        // }
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
        int     fd_pipes[2][2];
        int status;
        // int pipe_flag = 1;
        int pipe_flag = 0;
        int     i;

        pipe(fd_pipes[0]);
        pipe(fd_pipes[1]);

        i = 0;
        execve_com(head, fd_pipes, pipe_flag, envp, i);           // STDIN이 들어오는 명령어는 dup2 STDIN_FILENO를 쓰면 안됌
        ++pipe_flag;                                    // STDIN이 들어오지않는 명령어는 dup2사용
        printf("close: fd[1]\n");
        // close(fd[1]);

        // execve_com(ls, n_fd, pipe_flag, envp);
        // ++pipe_flag;
        // close(n_fd[0]);
        i =1;
        execve_com(cat, fd_pipes, pipe_flag, envp, i);
        printf("close: fd[0]\n");
        // close(fd[0]);
        i = 2;
        execve_com(ls, fd_pipes, pipe_flag, envp, i);

        close(fd_pipes[0][0]);
        close(fd_pipes[0][1]);
        close(fd_pipes[1][0]);
        close(fd_pipes[1][1]);
        wait(&status);
        printf("%d\n", status);
        wait(&status);
        printf("%d\n", status);
        wait(&status);
        printf("%d\n", status);
}
