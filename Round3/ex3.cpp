#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork(); 
	/* using pid_t to fix with different system,
	 * using fork() to create a new process */

	if (pid < 0){
		std::cerr << "Fork failed" << std::endl;
		return 1;
	}

	else if (pid == 0){
		/* child process can use getppid(),
		 * return 0 = i am child process */
		char* args[] = { (char*)"/bin/ls", nullptr };
		extern char** environ;
		execve("/bin/ls", args, environ);

		std::cerr << "execve failed" << std::endl;
		return 1;
	}
	else {
		int status;
		waitpid(pid, &status, 0);
		/* & = get the addess of status (for changing the value of status) 
		 * status is filled with exit info from the cild process 
		 * use waitpid() to store it */
	}


	return 0;
}

