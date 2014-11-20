#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char computer_name[HOST_NAME_MAX + 1];
	gethostname(computer_name, sizeof(computer_name) / sizeof(char));
	printf("%s\n", getenv("HOME"));
	chdir(getenv("HOME")); //Change current directory to home, or if it cannot, the current directory remains the directory of the executable.
	//printf("Error %i: %s\n", errno, strerror(errno));
	char current_directory[PATH_MAX + 1];
	current_directory = getcwd(current_directory, PATH_MAX);
	printf("%s@%s:%s$", getlogin(), computer_name, current_directory);
	printf("\n");
	free(current_directory);
	/*
	while (1) {
		char input[1024 + 1];
		fgets(input, sizeof(input) / sizeof(char), stdin);
		char
	*/
	return 0;
}
