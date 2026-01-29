#include <stdio.h>
#include <stdlib.h>
int main(){
	int *array = (int*)malloc(10 * sizeof(int));

	if (array == NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}

	for (int i = 0; i < 10; i++){
		array[i] = 1 + i;
	}
	
	printf("Array contents: \n");
	for (int i = 0; i < 10; i++){
		printf("%d\n", array[i]);
	}

	free(array);
	array = NULL;

	return 0;
}

