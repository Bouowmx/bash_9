#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** split(char * string, char delimiter) { //Just like Python's split. Returns a null-terimated array.
	//Find the number of delimiters in string. The size of the array needed to hold the split string is the number of delimiters plus two (including the terminating null).
	int i;
	char * string_2;
	for (string_2 = string, i = 0; strchr(string_2, delimiter) != NULL; string_2++, i++) {printf("%i: %s\n", i, string_2);}
	printf("%i\n", i);
	return NULL;
}

char * trim(char * string) { //Modifies in-place.
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
	
	split(input, ';');
	
	return EXIT_SUCCESS;
}

