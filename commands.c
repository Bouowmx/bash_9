#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** split(char *, char *);
char * trim(char *);

char ** split(char * string, char * delimiters) { //Just like Python's split. Returns a null-terimated array.
	//Find the number of delimiters in string. The size of the array needed to hold the split string is the number of delimiters plus two (including the terminating null).
	//About the increments: prefix will increment first and use that value, and suffix will use the current value and then increment.
	int i;
	char * string_2;
	for (string_2 = string, i = 0; string_2 != NULL; string_2 = strpbrk(++string_2, delimiters), i++) {}
	printf("Result: %i\n", i);
	char ** tokens = (char **) malloc(++i * sizeof(char *));
	char * token;
	int j;
	for (string_2 = strdup(string), token = strsep(&string_2, delimiters), j = 0; j < i; token = strsep(&string_2, delimiters), j++) {tokens[j] = trim(token);}
	for (j = 0; j < i; j++) {printf("%i: %s\n", j, tokens[j]);}
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
	char input[1024];
	char * input_2;
	char * command;
	char * commands[1024];
	int i;
	
	printf("Enter input: ");
	fgets(input, sizeof(input) / sizeof(char), stdin);
	printf("Input: %s\n", input);
	/*input_2 = strdup(input);
	for (command = strsep(&input_2, ";"), i = 0; command != NULL; command = strsep(&input_2, ";"), i++) {commands[i] = trim(command);}
	for (; i >= 0; i--) {printf("%i: %s\n", i, commands[i]);}*/
	
	split(input, ";");
	
	return EXIT_SUCCESS;
}

