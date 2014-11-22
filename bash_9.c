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
	int i;
	printf("foo\n");
	while (1) {
		user = getpwuid(getuid())->pw_name;
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", user, computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		//Remove leading and trailing whitespace
		input_2 = strdup(input);
		for (i = 0; i < strlen(input_2); i++) {
			if (!(isspace(input_2[i]))) {
				strcpy(input, &input_2[i]);
				break;
			}
		}
		free(input_2);
		input_2 = strdup(input);
		for (i = strlen(input_2) - 1; i >= 0; i--) {
			if (!(isspace(input_2[i]))) {
				strncpy(input, input_2, i + 1);
				break;
			}
		}
		free(input_2);		
		printf("Input: %s\n", input);
		if ((input[0] == 'c') && (input[1] == 'd')) {
			input_2 = strdup(input);
			strsep(&input_2, " ");
			chdir(strsep(&input_2, " \n"));
			if (errno != 0) {printf("%s\n", strerror(errno));} //Strangely, building and running with Cygwin will cause this to print "Invalid or incomplete multibyte or wide character". Changing directories is not affected.
		}
		else if (strcmp(input, "exit") == 0) {return 0;}
		else {
			printf("Forking.\n");
			pid_t pid = fork();
			if (pid >= 0) {
				execlp("ls", "ls", "-l", (char *) NULL);
				printf("%s\n", strerror(errno));
			}
			else {wait(NULL); printf("Execution complete.\n");}
		}
		printf("Looping.\n");
	}
	
	return EXIT_SUCCESS;
}

