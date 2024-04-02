#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	char *input_string = argv[1];
	char temp;
	int i,j;
	for(i=0, j=strlen(input_string)-1; i<j; i++, j--){
		temp = input_string[j];
		input_string[j] = input_string[i];
		input_string[i] = temp;
	}
	printf("%s\n", input_string);
}
