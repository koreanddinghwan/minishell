//#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	input_redirection(char *command, char *target, char **envp) // ex) cat, test.txt
{
	int	fd;
	char **ag;

	ag = (char **)malloc(sizeof(char *) * 2);
	ag[0] = "-e";
	fd = open(target, O_RDONLY);
	if (fd < 0)
		return (-1);
	dup2(fd, STDIN_FILENO);
	// 빌트인인지 아닌지 확인
	execve(command, ag, envp);
	close(fd);
	return (1);
}

int output_redirection()
{
	int fd;
	
	fd = open(target, O_CREAT | O_WRONLY | O_TRUNC ,0644);
	if (fd < 0)
		return (-1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int main(int ac, char **av, char **envp)
{
	// input_redirection: '<' ex) cat < test.txt == < test.txt cat
	// char cat[9] = "/bin/cat";
	// char tar[9] = "test.txt";
	// input_redirection(cat, tar, envp);

	// here document: '<<'

	// output_redirection: '>' ex) echo abc > test.txt == > test.txt echo abc
	// double_output_redirection: '>>' O_TRUNC --> O_APPEND 수정하면 됌

}
