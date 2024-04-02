#include <stdio.h>
#include <stdlib.h>

void print_char(char c)
{
	for (int i = 7; i >= 0; --i)
	{
		printf("%c", (c & (1 << i)) ? '1' : '0' );
	}
	printf(" ");
}

int main( int argc, char* argv[]){

	unsigned total_length=strlen(argv[1]);
	char *input_string = argv[1];
	int i =0;
	while( *(input_string+i) != '\0'){
		print_char(*(input_string+i));
		i++;
	}
}
