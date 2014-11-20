#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char * computer_name = (char *) malloc(HOST_NAME_MAX * sizeof(char) + 1);
	gethostname(computer_name, sizeof(computer_name));
	chdir("~"); //Change current directory to home, or if it cannot, the current directory remains the directory of the executable.
	char * current_directory = getcwd(current_directory, PATH_MAX);
	printf("%s@%s:%s$", getlogin(), computer_name, current_directory);
	free(current_directory);
	
	return 0;
}
