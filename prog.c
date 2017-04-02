// A simple program that prints all environmental variables

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv, char** envp) {

	// printing all env variables
	printf("Printing all environmental variables:\n");	

	while(*envp != NULL) {
		printf("%s\n", *envp);
		envp++;
	}

	printf("\n");

	// search for value of SHELL_PATH - if not found, set value to UNKNOWN
	char *shell_path_value = getenv("SHELL_PATH");
	if (!shell_path_value) {
		shell_path_value = "UNKNOWN";
	}

	// print result
	printf("SHELL_PATH value is %s\n", shell_path_value);
	printf("\n");

}