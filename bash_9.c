#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char computer_name[HOST_NAME_MAX + 1];
	char current_directory[PATH_MAX + 1];
	chdir(getenv("HOME"));
	char input[1024 + 1];
	while (1) {
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", getlogin(), computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		if (strchr(input, '\n') != NULL) {*strchr(input, '\n') = NULL;}
		printf("%s\n", input);
		if (strcmp(input, "exit")) {return 0;}
	}
	return 0;
}
