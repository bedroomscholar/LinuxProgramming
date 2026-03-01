#include <iostream>
#include <cstdlib>
#include <pthread.h>

#define NUMBER_OF_THREADS 5

void* print_hello(void* thread_id){
	long tid = (long)thread_id;
	std::cout << "Hello World! Thread ID: " << tid << std::endl;
	pthread_exit(NULL);
	return NULL;
}


int main(){
	pthread_t threads[NUMBER_OF_THREADS];
	int rc;

	for (long t = 0; t < NUMBER_OF_THREADS; t++) {
		std::cout << "Main: creating thread " << t << std::endl;

		rc = pthread_create(&threads[t], NULL, print_hello, (void*)t);

		if (rc) {
			std::cerr << "ERROR: pthread_create() returned " << rc << std::endl;
			exit(-1);
		}

	}

	for (long t = 0; t < NUMBER_OF_THREADS; t++) {
		pthread_join(threads[t], NULL);
	}

	std::cout << "Main: all threads completed." << std::endl;
	return 0;
}

