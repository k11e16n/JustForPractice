#include <stdio.h>
#include <stdlib.h>

enum _flags {
	FLAG1 = 0x1,
	FLAG2 = 0x2,
	FLAG3 = 0x4,
	FLAG4 = 0x8,

	NO_FLAGS = 0,
	ALL_FLAGS = FLAG1 | FLAG2 | FLAG3 | FLAG4
};
int main( int argc, char* argv[] ){

	enum _flags mask;
	if(argc==2) mask = atoi(argv[1]);
	else mask = ALL_FLAGS;
	if(mask & FLAG1) printf("FLAG1\n");
	if(mask & FLAG2) printf("FLAG2\n");
	if(mask & FLAG3) printf("FLAG3\n");
	return 0;
}
