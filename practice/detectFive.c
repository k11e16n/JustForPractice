#include <stdio.h>

int detectWinner( int* inputArray[], int m, int n){

}

void printArray( int (*inputArray)[10], int m, int n){
	int i = 0, j = 0;
	for (i=0; i<m;i++){
		for (j=0; j<n;j++){
			//printf("%d, ", inputArray[i][j]);
			printf("%d, ", *(*(inputArray + i) + j ) );
		}
		printf("\n");
	}
	printf("sizeof:%zu\n", sizeof inputArray);
}

#define MAXROW	10
#define MAXCOL	10
int main(){
	int chess[MAXROW][MAXCOL] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 1, 2, 0, 0, 0},
		{0, 0, 2, 1, 2, 1, 1, 0, 0, 0},
		{0, 0, 0, 2, 1, 1, 0, 0, 0, 0},
		{0, 0, 2, 1, 2, 2, 2, 0, 0, 0},
		{0, 1, 1, 0, 0, 2, 0, 0, 0, 0},
		{0, 2, 0, 0, 0, 0, 2, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	printArray( chess, 10, 10);

	int x=0, y=0, winCondition=5;
	for(x=0;MAXROW-winCondition; x++){
		for(y=0;MAXCOL-winCondition; y++){
			//detect function here
		}
	}
}
