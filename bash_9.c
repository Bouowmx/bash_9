#include <errno.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char * user;
	char computer_name[HOST_NAME_MAX];
	char current_directory[PATH_MAX];
	//chdir(getenv("HOME"));
	char input[1024];
	char buffer[1024];
	while (1) {
		user = getpwuid(getuid())->pw_name;
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", user, computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		//if (strchr(input, '\n') != NULL) {*strchr(input, '\n') = NULL;}
		printf("Input: %s\n", input);
		if ((input[0] == 'c') && (input[1] == 'd')) {
			printf("Changing directory.\n");
			FILE * pipe = popen(strcat(input, "; pwd"), "r");
			while (fgets(buffer, sizeof(buffer) / sizeof(char), pipe) != NULL) {printf("%s", buffer);}
			pclose(pipe);
			pipe = popen("pwd", "r");
			fgets(current_directory, sizeof(current_directory) / sizeof(char), pipe);
			printf("%s", current_directory);
			chdir(current_directory); //Error
			printf("4Error %i: %s\n", errno, strerror(errno));
		}
		if (strcmp(input, "exit") == 0) {return 0;}
	}
	return 0;
}
