#include <stdio.h>
#include <stdlib.h>


#define GET_BIT(x,n) (( (x) & (1 << (n)) )!=0)

int main( int argc, char*argv[]){

	int input_number=atoi(argv[1]);
	int i=0, start_addr=0, number_of_one=0, max_length=0, max_start_addr=0, reset_flag=1;
	int array[8]={0};

	for ( i=0; i<8; i++){
		if( GET_BIT( input_number, i) == 1){
			array[i] = 1;
			number_of_one++;
			if(reset_flag==1){
				reset_flag=0;
				start_addr=i;
			}
			if( number_of_one > max_length){
				max_length = number_of_one;
				max_start_addr=start_addr;
			}

		}else{
			array[i] = 0;
			reset_flag=1;
			number_of_one=0;
		}
	}
	for ( i=7; i>=0; i--){
		printf("%d", array[i]);
	}
	printf("\nmax number of one is [%d], start addr is [%d]\n", max_length, max_start_addr);
}
