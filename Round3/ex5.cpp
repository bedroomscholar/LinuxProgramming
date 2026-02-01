#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

void type_prompt(){
	std::cout << "Enter a command: ";
	std::cout.flush();
}

bool read_command(std::vector<char*>& args, std::vector<std::string>& storage){
	/* using & in the parameter to store it in the command at original address */
	std::string line;
	std::getline(std::cin, line);
	
	if (line.empty()){
		return false;
	}

	args.clear();
	storage.clear();
	/* clear previous command data */

	std::istringstream iss(line);
	std::string token;

	while (iss >> token){
		storage.push_back(token);
	}
	
	/* convert string to char* */
	for (std::string& s : storage) {
		/* & -> read the array from storage directly */
		args.push_back(&s[0]);
		/* & -> get the address */
	}

	args.push_back(nullptr);
	return true;
}

int main(){
	std::vector<char*> args;
	std::vector<std::string> storage;

	while (true){
		type_prompt();

		if (!read_command(args, storage)){
			std::cout << "Programrun stops running" << std::endl;
			break;
		}

		pid_t pid = fork();

		if (pid < 0){
			std::cerr << "Fork failed" << std::endl;
		}
		else if (pid == 0){
			execvp(args[0], args.data());

			std::cerr << "Command not found. " << args[0] << std::endl;
			return 1;
		}
		else{
			int status;
			waitpid(pid, &status, 0);
		}
	}

	return 0;
}




