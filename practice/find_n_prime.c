#include <stdio.h>
#include <stdlib.h>

int is_prime( int input_num ){
	if(input_num == 1){
		return 0;
	}
	int i;
	for(i=2; i<=input_num/2; i++){
		if( input_num%i == 0){
			return 0;
		}
	}
	return 1;
}

int main( int argc, char* argv[]){
	int input_number=atoi(argv[1]), round=1, num=1;

	while( round <= input_number){
		if(is_prime(num)){
			round++;
			num++;
		}else{
			num++;
		}
	}
	printf("the %dth prime is :%d\n", input_number, num-1);
}
