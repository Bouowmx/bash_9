#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	while (1) {
		printf("before executing\n");
		pid_t f = fork();
		int status;
		if (!f)
			execl( "/bin/ls", "ls", "-a", "-l", NULL);
		else{
			wait(&status);
			printf("after execution\n");
			sleep(1);
		}
	}
}