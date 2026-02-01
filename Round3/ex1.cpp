#include <iostream>

int main(int argc, char* argv[]){
	std::cout << "Number of command line arguments: " << argc - 1 << std::endl;
	std::cout << "And they are:" << std::endl;

	for (int i = 1; i < argc; i++){
		std::cout << argv[i] << std::endl;
	}

	return 0;

}
