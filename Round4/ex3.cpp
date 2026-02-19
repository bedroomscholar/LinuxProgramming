#include <iostream>
#include <cerrno> // for errno
#include <cstdio>  // for perror()
#include <fcntl.h> // for creat(), O_WRONLY, file permission
#include <unistd.h> // for write(), close(), _exit()
		    
int main(){
	// ask for single character
	char ch;
	std::cout << "Enter a single character: ";
	std::cin >> ch;

	// using creat for create/overwrite a file
	int fd = creat("output.bin", 0644);
	// 6 = owner 4+2 read + write
	// 4 = group 4 read
	// 4 = others 4 read
	
	if (fd == -1){
		perror("create failed");
		_exit(1);
	}

	// write exactly 1 byte to the file
	ssize_t bytes_written = write(fd, &ch, 1);
	// fd = file descriptor returned by creat()
	// &ch = pointer to the data to write(address)
	// 1 = number of bytes to write
	
	if (bytes_written == -1) {
		perror("write failed");
		close(fd);
		_exit(1);
	}

	std::cout << "Wrote '" << ch << "' <" << (int)ch << " in ASCII) to output.bin" << std::endl;

	// close the file, release the file descriptor
	if (close(fd) == -1) {
		perror("close failed");
		_exit(1);
	}

	std::cout << "File closed successfully." << std::endl;
	return 0;
}
