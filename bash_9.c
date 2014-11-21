#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char computer_name[HOST_NAME_MAX];
	char current_directory[PATH_MAX];
	chdir(getenv("HOME"));
	char input[1024];
	char buffer[1024];
	while (1) {
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", getlogin(), computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		if (strchr(input, '\n') != NULL) {*strchr(input, '\n') = NULL;}
		printf("Input: %s\n", input);
		if ((input[0] == 'c') && (input[1] == 'd')) {
			printf("Changing directory.\n");
			FILE * pipe = popen("ls *", "r");
			printf("Error %i: %s\n", errno, strerror(errno));
			while (fgets(buffer, sizeof(buffer) / sizeof(char), pipe) != NULL) {printf("%s", buffer);}
			pclose(pipe);
			printf("Error %i: %s\n", errno, strerror(errno));
			printf("Checkpoint.\n");
			pipe = popen("pwd", "r");
			fgets(current_directory, sizeof(current_directory) / sizeof(char), pipe);
			chdir(current_directory);
			printf("Error %i: %s\n", errno, strerror(errno));
		}
		if (strcmp(input, "exit") == 0) {return 0;}
	}
	return 0;
}
