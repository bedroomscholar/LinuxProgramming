#include <iostream>
#include <unistd.h>

int main(){
	char* args[] = {
		(char*)"/bin/ls",
		nullptr
	};
	extern char** environ;
	
	execve("/bin/ls", args, environ);

	std::cerr << "execve failed" << std::endl;
	return 1;
}
