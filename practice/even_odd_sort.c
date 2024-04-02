#include <stdio.h>

void sort_array(int start, int end, int array[]){
	printf("\n%d to %d\n", start, end);
	int i,j,temp;
	for(i=start+1;i<=end;i++){
		temp=array[i];
		for( j=i-1; j>=start && array[j] > temp; j--){
			array[j+1]= array[j];
		}
		array[j+1]=temp;
	}
}

int main(){
	int input_array[]={42,32,77,21,54,89,31,56};
	int output_array[8] = {0};
	int i=0, array_size=(sizeof input_array/sizeof (int));
	int even_num=0, odd_num=0;
	int even_location=0, odd_location=array_size-1;

	// make total array
	for(i=0;i<array_size;i++){
		if( input_array[i]%2==0){//even
			even_num++;
			output_array[even_location++]=input_array[i];
		}else{//odd
			odd_num++;
			output_array[odd_location--]=input_array[i];
		}
	}

	for(i=0;i<array_size;i++){
		printf("%d, ", input_array[i]);
	}
	printf("\neven_num:%d, odd_num:%d\n",even_num, odd_num);
	for(i=0;i<array_size;i++){
		printf("%d, ", output_array[i]);
	}
	// sort array
	sort_array(0,even_num-1,output_array);
	for(i=0;i<array_size;i++){
		printf("%d, ", output_array[i]);
	}
	sort_array(even_num,array_size-1,output_array);
	for(i=0;i<array_size;i++){
		printf("%d, ", output_array[i]);
	}
}
