#include <stdio.h>
#include <unistd.h>

int main() {
	char buffer[256];

	if (getcwd(buffer, sizeof(buffer)) != NULL) {
		printf("Current working directory: %s\n", buffer);
	} else {
		printf("Error getting current directory\n");
	}
	
	return 0;
}

