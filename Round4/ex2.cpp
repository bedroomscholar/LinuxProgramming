#include <iostream>
#include <cerrno>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd = open("/tmp/this_file_does_not_exist_12345.txt", O_RDONLY);

	if (fd == -1){
		// print errno directly
		std::cout << "open() failed!" << std::endl;
		std::cout << "errno value = " << errno << std::endl;

		// use perror
		perror("perror says");
	}
	else{
		std::cout << "File opened successfully" << std::endl;
		close(fd);
	}
	
	std::cout << "\nSecond test: trying to write to a directory" << std::endl;
	fd = open("/tmp", O_WRONLY);
	if (fd == -1) {
		std::cout << "errno value = " << errno << std::endl;
		perror("Writing to directory");
	} else {
		close(fd);
	}

	return 0;
}

