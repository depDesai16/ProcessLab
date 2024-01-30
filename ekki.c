#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int child_status;
	
	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		/* Child code */
		printf("My PID: %d;\tParent PID: %d\n", getpid(), getppid());
		execl("ni", argv[0], (char *) NULL);
		/* all code below this here in child is unreachable */
		printf("Reached unreachable code (exec failed)\n");
		exit(EXIT_FAILURE);
	} else {
		/* Parent code */

		printf("Parent PID: %d\n", getpid());

		pid_t wpid = wait(&child_status);
		if (WIFEXITED(child_status)) {
			printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
		} else {
			printf("Child %d terminated abnormally\n", wpid);
		}
	}
	return 0;
}
