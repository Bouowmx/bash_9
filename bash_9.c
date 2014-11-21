#include <ctype.h>
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
	char input[1024];
	char * input_2;
	int i = 0;
	while (1) {
		user = getpwuid(getuid())->pw_name;
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", user, computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		input_2 = strdup(input);
		
		printf("Input: %s\n", input);
		if ((input[0] == 'c') && (input[1] == 'd')) {
			input_2 = strdup(input);
			strsep(&input_2, " ");
			chdir(strsep(&input_2, " \n"));
		}
		if (strcmp(input, "exit") == 0) {return 0;}
	}
	return 0;
}

