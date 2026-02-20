#include <iostream>
#include <cerrno>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

int main(){
	// open the file for reading
	int fd = open("output.bin", O_RDONLY);
		// O_RDONLY doesn't need permission
	if (fd == -1){
		perror("open failed");
		_exit(1);
	}

	//read exactly 1 byte from the file
	char buffer[1];
	ssize_t bytes_read = read(fd, buffer, 1);
		// buffer = where to store the data we read
	if (bytes_read == -1) {
		perror("Read failed");
		close(fd);
		_exit(1);
	}

	if (bytes_read == 0) {
		std::cout << "File is empty — nothing to read!" << std::endl;
    	} else {
		std::cout << "Read character: '" << buffer[0] << "'" << std::endl;
		std::cout << "ASCII value: " << (int)buffer[0] << std::endl;
    	}

	// close the file
	if (close(fd) == -1){
		perror("close failed");
		_exit(1);
	}

	std::cout << "File closed successfully." << std::endl;
	return 0;
}


