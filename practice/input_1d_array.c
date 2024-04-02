#include <stdio.h>
#include <stdlib.h>

int main(){

	int i, length, *array;
	printf("Please input array size:");
	scanf("%d", &length);

	array = (int*)malloc( sizeof(int)*length);

	printf("Please fillup the array.\n");

	for(i=0;i<length;i++){
		scanf("%d", &array[i]);
	}

	// print out the array
	for(i=0;i<length;i++){
		printf("[%d]", array[i]);
	}

	if(array) free(array);
}
