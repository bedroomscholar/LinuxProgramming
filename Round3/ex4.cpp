#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	
	/* check if it's a valid command */
	if (argc < 2) {
		std::cerr << "plz use <command> + [args...]" << std::endl;
		return 1;
	}

	pid_t pid = fork();

	if (pid < 0){
		std::cerr << "Fork failed" << std::endl;
		return 1;
	}
	else if (pid == 0){
		execvp(argv[1], argv + 1);
		/* argv + 1 = go to the next pointer */
		
		std::cerr << "Command not found." << std::endl;
		return 1;
	}
	else {
		int status;
		waitpid(pid, &status, 0);
	}

	return 0;

}
