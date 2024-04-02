#include <stdio.h>
#include <stdlib.h>


/*
 * METHOD_1
 * this is the basic method, not good for read and use, but onlu using malloc once, so you can easily free the pointer. 
 *
 * METHOD_2
 */

#define METHOD_2 1

int main(){

#if METHOD_1
	int m,n, arr_length_m, arr_length_n, *array;

	printf("Please input array m size :");
	scanf("%d", &arr_length_m);
	printf("Please input array n size :");
	scanf("%d", &arr_length_n);

	// alloc the size
	array = (int*)malloc( sizeof(int*)*arr_length_m*arr_length_n);

	printf("Please fillup the array.\n");

	for(m=0;m<arr_length_m;m++){
		for(n=0;n<arr_length_n;n++){
			scanf("%d", (array+m*arr_length_n+n));
		}
	}

	// print all array
	for(m=0;m<arr_length_m;m++){
		printf("[ ");
		for(n=0;n<arr_length_n;n++){
			printf("%d, ", *(array+m*arr_length_n+n));
		}
		printf("]\n");
	}

	// free
	if(array) free(array);

#elif METHOD_2

	int i, m, n, arr_length_m, arr_length_n, **array, *array_data;

	printf("Please input array m size :");
	scanf("%d", &arr_length_m);
	printf("Please input array n size :");
	scanf("%d", &arr_length_n);

	// alloc the size and construct the array
	array = (int**)malloc( sizeof(int*)*arr_length_m + sizeof(int)*arr_length_m*arr_length_n);
	for (i = 0, array_data = (int *)(array+arr_length_m); i < arr_length_m; i++, array_data += arr_length_n){
		array[i]=array_data;
	}

	printf("Please fillup the array.\n");

	for(m=0;m<arr_length_m;m++){
		for(n=0;n<arr_length_n;n++){
			scanf("%d", &array[m][n]);
		}
	}

	// print all array
	for(m=0;m<arr_length_m;m++){
		printf("[ ");
		for(n=0;n<arr_length_n;n++){
			printf("%d ", array[m][n]);
		}
		printf("]\n");
	}

	// free
	if(array) free(array);
#endif
}
