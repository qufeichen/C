// A simple shell program that takes a command from the user and executes it in a new process

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {

	while(1) {
	
		char command[100];	
		char *new_line_char;	
		pid_t pid;
		char *file_name;
		//char *const arguments*;		

	
		printf(">");
		// read input from user
		fgets(command, 100, stdin);
	
		// replace \n with \0
		if ((new_line_char = strchr(command, '\n')) != NULL) {
			*new_line_char = '\0';	
		} else {
			// input is too long
			// TODO: throw error here
		}
		
		// create a new process
		pid = fork();
		
		if (pid != 0) {
			// this will only be accessed by the parent process
			// the pid of the child will be returned to the parent process
			// print the child pid
			printf("Loading new process with id %d\n", pid);
			wait(NULL);


		}
		
		if (pid == 0) {
			// this will only be access by the child process
			// print parent pid
			printf(">Parent pid: %d\n", getppid());
			
			// split command into file name and arguments
			file_name = strtok(command, " ");

			// format arguments for execv()
			char *arguments[] = {file_name, strtok(NULL, ""), (char *)0};		

			// execute command
			int ret;
			ret = execvp(file_name,arguments); 

			if (ret) {
				// an error occured running execv
				printf("Shell error: No such file or directory\n");
				// terminate child process
				_exit(0);	
			}

		}

		printf("\n");
	}




}
