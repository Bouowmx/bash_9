#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** split(char *, char *);
char * trim(char *);

char ** split(char * string, char * delimiters) { //Similar to Python's split. Returns a null-terimated array with each element trimmed of whitespace.
	//Find the number of delimiters in string. The size of the array needed to hold the split string is the number of delimiters plus two (including the terminating null).
	//About the increments: prefix will increment first and use that value, and suffix will use the current value and then increment.
	int i;
	char * string_2, * string_3;
	for (string_2 = string, i = 0; string_2 != NULL; string_2 = strpbrk(++string_2, delimiters), i++) {}
	char ** tokens = (char **) malloc(++i * sizeof(char *));
	char * token;
	int j;
	for (string_3 = string_2 = strdup(string), token = strsep(&string_2, delimiters), j = 0; j < i; token = strsep(&string_2, delimiters), j++) {tokens[j] = (token != NULL) ? trim(token) : token;}
	free(string_3);
	return tokens;
}
	
char * trim(char * string) { //Modifies in-place.
	if (string == NULL) {return NULL;}
	char * string_2;
	int i;
	string_2 = strdup(string);
		for (i = 0; i < strlen(string_2); i++) {
			if (!(isspace(string_2[i]))) {
				strcpy(string, &string_2[i]);
				break;
			}
		}
		free(string_2);
		string_2 = strdup(string);
		for (i = strlen(string_2) - 1; i >= 0; i--) {
			if (!(isspace(string_2[i]))) {
				strncpy(string, string_2, i);
				break;
			}
		}
		free(string_2);
		string[i + 1] = '\0';
		return string;
}

int main() {
	printf("Welcome to Bash ⑨. Authored by Cirno. Expect the strongest and the best.\n");
	char computer_name[HOST_NAME_MAX];
	char current_directory[PATH_MAX];
	char input[1024];
	char * input_2, * input_3;
	char * user;
	while (1) {
		user = getpwuid(getuid())->pw_name; //This is automatically freed.
		gethostname(computer_name, sizeof(computer_name) / sizeof(char));
		getcwd(current_directory, PATH_MAX);
		printf("%s@%s:%s⑨ ", user, computer_name, current_directory);
		fgets(input, sizeof(input) / sizeof(char), stdin);
		//Remove leading and trailing whitespace
		trim(input);
		printf("Input: \"%s\"\n", input);
		if (strcmp(input, "") == 0) {continue;}
		if ((input[0] == 'c') && (input[1] == 'd')) {
			input_2 = strdup(input);
			strsep(&input_2, " ");
			chdir(strsep(&input_2, " \n"));
			free(input_2);
			if (errno != 0) {printf("%s\n", strerror(errno));} //Strangely, building and running with Cygwin will cause this to print "Invalid or incomplete multibyte or wide character". Changing directories is not affected.
		}
		else if (strcmp(input, "exit") == 0) {return 0;}
		else {
			input_3 = input_2 = strdup(input);
			char * command = strsep(&input_2, " ");
			char ** arguments = split(input, " ");
			//free(input_3);
			printf("%s\n", strerror(errno));
			pid_t pid = fork();
			if (!pid) { //Strangely, using the condition "pid != 0" will cause incorrect forking. Additionally, a new line in input will result in "No such file or directory".
				int status = execvp(command, arguments);
				printf("%s\n", strerror(errno));
				_exit(status);
			}
			else {wait(NULL);}
		}
		//printf("%s\n", strerror(errno));
	}
	
	return EXIT_SUCCESS;
}

//cat `echo "hi\n" * 500` - | ./bash_9.elf


