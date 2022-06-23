#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// void	execve_com(char *command, int pipefd[2], int flag)
// {
// 	pid_t	pid;
// 	pid = fork();

//         int i =0;

//         if (pid > 0)
// 	{
//                 close(pipefd[1]);
//                 return ;
//         }
// 	if (pid == 0)
//         {
//                 printf("pipefd[0]_pre: %d %d\n", pipefd[0], i++);
// 	        if (flag & 1)
// 	        	dup2(pipefd[0], STDIN_FILENO);
//                 printf("pipefd[0]_aft: %d %d\n", pipefd[0], i++);
//                 printf("pipefd[1]_pre: %d %d\n", pipefd[1], i++);
//                 if (flag & 2)
// 	        	dup2(pipefd[1], STDOUT_FILENO);
//                 printf("pipefd[1]_aft: %d %d\n", pipefd[1], i++);
// 	        close(pipefd[0]);
//                 char *argv[] = {command, NULL};
// 	        char *envp[] = {NULL};
// 	        execve(command, argv, envp);
//         }
// }

// int main()
// {
// 	int prefd[2], nextfd[2];
// 	pipe(prefd);
// 	pipe(nextfd);

// 	execve_com("/bin/ls", prefd, 2);
// 	close(prefd[1]);

// 	execve_com("/usr/bin/wc", nextfd, 1);
// 	close(nextfd[0]);

//         int fd[2] = {prefd[0], nextfd[1]};
//         execve_com("/usr/bin/wc", fd, 2 | 1);
        
//         close(prefd[0]);
// 	close(nextfd[1]);
        
//         int status;
//         while (wait(&status) > 0);
// 	return 0;
// }

void    execve_com(char *com, int fd[2], int flag, char **envp)
{
        pid_t pid;
        pid = fork();

        char *ag[] = {com, NULL};

        if (pid == 0)
        {
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                execve(com, ag, envp);
        }
        // waitpid(pid, 0, 0);
        if (flag == 0)
        {
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
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
        pid_t pid;
        int fd[2];
        int n_fd[2];
        int status;
        // int pipe_flag = 0;
        int pipe_flag = 1;

        pipe(fd);
        // pipe(n_fd);

        execve_com(cat, fd, pipe_flag, envp);           // STDIN이 들어오는 명령어는 dup2 STDIN_FILENO를 쓰면 안됌
        --pipe_flag;                                    // STDIN이 들어오지않는 명령어는 dup2사용
        close(fd[1]);

        // execve_com(ls, n_fd, pipe_flag, envp);
        // ++pipe_flag;
        // close(n_fd[0]);

        execve_com(env, fd, pipe_flag, envp);
        close(fd[0]);

        // int t_fd[2] = {fd[0], n_fd[1]};
        // execve_com(wc, t_fd, pipe_flag, envp);
        // close(fd[0]);
        // close(n_fd[1]);
        while (wait(&status) > 0);
}