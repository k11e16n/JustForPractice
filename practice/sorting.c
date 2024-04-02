#include <stdio.h>

// sort structure
struct sort{
	char name[32];
	void (*func)(int*, int);
};

void swap( int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void print_array( int *input_array, int array_size){
	int i;
	for(i=0; i< array_size; i++)
		printf("%d ", input_array[i]);
	printf("\n");
}

void insertion_sort( int *input_array, int array_size){
	int i, j, temp;
	for(i=1;i<array_size;i++){
		temp = input_array[i];
		for(j=i-1; j>0 && input_array[j]>temp; j--){
			input_array[j+1] = input_array[j];
		}
		input_array[j+1]=temp;
	}
}

void selection_sort( int *input_array, int array_size ){
	int i, j, min, temp;
	for( i=0; i<array_size-1; i++){
		min = i;
		for( j=i+1; j<array_size; j++){
			if(input_array[min] > input_array[j]){
				min=j;
			}
		}
		swap(&input_array[i], &input_array[min]);;
	}
}

void bubble_sort( int *input_array, int array_size ){
	int i, j, temp;
	for(i=0;i<array_size-1;i++){
		for(j=0;j<array_size-i-1;j++){
			if( input_array[j] > input_array[j+1]){
				swap(&input_array[j], &input_array[j+1]);;
			}
		}
	}
}

void quicksort_r( int *input_array, int start, int end ){
	if(start>=end){
		return;
	}
	int pivot=start, i=start+1, j=end;
	while(i<=j){
		while(input_array[i]<input_array[pivot]){
			i++;
		}
		while(input_array[j]>input_array[pivot]){
			j--;
		}
		if(i<=j){
			swap(&input_array[i],&input_array[j]);
		}
	}
	swap(&input_array[pivot],&input_array[j]);
	quicksort_r( input_array, start, j-1 );
	quicksort_r( input_array, j+1, end );
}

void quick_sort( int *input_array, int array_size ){
	quicksort_r(input_array, 0, array_size-1);
}

int main(){
	int array[] = {14, 63, 25, 37, 97, 36, 73, 11, 24, 67, 77}, array_size=11, i, selection;
	struct sort sort[] = {
		{"insertion_sort",insertion_sort},
		{"bubble_sort",bubble_sort},
		{"selection_sort",selection_sort},
		{"quick_sort", quick_sort}
	};

	for(i=0;i<(sizeof(sort)/sizeof(struct sort));i++){
		printf("[%d] %s\n", i+1, sort[i].name );
	}
	printf("Please sellect a sort:");
	scanf("%d", &selection);

	// original array
	printf("Original:\n");
	print_array(array, array_size);

	// doing sorting
	sort[selection-1].func(array, array_size);

	// print result
	printf("\nResult:\n");
	print_array(array, array_size);
}
