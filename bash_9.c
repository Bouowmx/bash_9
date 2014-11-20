#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char * computer_name = (char *) malloc(HOST_NAME_MAX * sizeof(char) + 1);
	gethostname(computer_name, sizeof(computer_name));
	chdir("~");
	char * current_directory = getcwd(current_directory, NULL);
	printf("%s@%s:%s$", getlogin(), computer_name, current_directory);
	free(current_directory);
	
	return 0;
}
