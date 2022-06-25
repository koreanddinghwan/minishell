//#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

// int	input_redirection(char *command, char *target, char **envp) // ex) cat < test.txt
// {
// 	int	fd;
// 	char **ag;
// 	pid_t	pid;
// 	int		status;

// 	ag = (char **)malloc(sizeof(char *) * 2);
// 	ag[0] = "-e";
// 	fd = open(target, O_RDONLY);
// 	pid = fork();
// 	if (pid < 0)
// 		exit(1);
// 	if (fd < 0)
// 		return (-1);
// 	if (pid == 0)
// 	{
// 		printf("child 시작 pid : %ld\n", (long)getpid());
// 		dup2(fd, STDIN_FILENO);
// 		// 빌트인인지 아닌지 확인
// 		execve(command, ag, envp);
// 	}
// 	else
// 	{
// 		printf("부모 pid : %ld, pid : %d\n",(long)getpid(), pid);
// 		close(fd);
// 		waitpid(pid, &status, 0);
// 		printf("child 종료\n");
// 		printf("부모 종료 %d %d %d\n", pid, WIFEXITED(status), WEXITSTATUS(status)); // 1, 0(자식)
// 	}
// 	return (1);
// }

int output_redirection(char *command, char *target, char **envp)
{
	int fd;
	pid_t pid;

	char *ag[]={"/usr/bin", NULL};
	fd = open(target, O_CREAT | O_RDWR | O_TRUNC , 0644);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (fd < 0)
		return (-1);
	if (pid == 0)
	{
		printf("[cat > text.txt] start!\nStop: ctrl+c\n");
		dup2(fd, STDOUT_FILENO);
		// printf("%d\n", execve(command, ag, envp));
		// printf("%s\n", strerror(errno));
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd);
	}
	return (1);
}

// int double_output_redirection(char *command, char *target, char **envp)
// {
// 	int fd;
// 	pid_t pid;

// 	char *ag[]={"/usr/bin", NULL};
// 	fd = open(target, O_CREAT | O_WRONLY | O_APPEND , 0644);
// 	pid = fork();
// 	if (pid < 0)
// 		exit(1);
// 	if (fd < 0)
// 		return (-1);
// 	if (pid == 0)
// 	{
// 		printf("[cat >> test.txt] start!\nStop: ctrl+c\n");
// 		dup2(fd, STDOUT_FILENO);
// 		printf("%d\n", execve(command, ag, envp));
// 		printf("%s\n", strerror(errno));
// 	}
// 	else
// 	{
// 		waitpid(pid, NULL, 0);
// 		close(fd);
// 	}
// 	return (1);
// }

int	here_document()
{
	int fd;
	pid_t pid;
	char *line;
	char *ag[]={"/bin/cat", NULL};

	fd = open("hi", O_CREAT | O_RDWR | O_TRUNC, 0644);
	pid = fork();
	if (pid == 0)
	{
		printf("[cat << hi]: start!\n");
		dup2(fd, STDIN_FILENO);
		execve("bin/cat", ag, 0);
		while (1)
		{
			line = readline("heredoc> ");
			if (!strcmp(line, "hi"))
			{
				printf(" exit\n");
				return (0);
			}
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd);
	}
	return (1);
}

int main(int ac, char **av, char **envp)
{
	// input_redirection: '<' ex) cat < test.txt == < test.txt cat
	char cat[9] = "/bin/cat";
	char echo[10] = "/bin/echo";
	char env[12] = "/usr/bin/env"; // not a directory: ?????????
	char tar[9] = "test.txt";
	// input_redirection(env, tar, envp);
	// output_redirection(cat, tar, envp);
	// double_output_redirection(cat, tar, envp);
	here_document();
	// here document: '<<'

	// output_redirection: '>' ex) echo abc > test.txt == > test.txt echo abc
	// double_output_redirection: '>>' O_TRUNC --> O_APPEND 수정하면 됌

}