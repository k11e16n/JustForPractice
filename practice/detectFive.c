#include <stdio.h>

#define MAXROW	10
#define MAXCOL	10
#define WINCONDITION 5

int detectWinner( int (*inputArray)[10], int m, int n){ /* Why define like this? */
	int i=0, row=0, col=0, count=0;
	if( (MAXCOL-n)<WINCONDITION && (MAXROW-m)<WINCONDITION){
		// printf("[%d][%d]Now way right or down!\n",m, n);
		return 0;
	}

	// printf("Start counting raw\n");
	for(row=0; row<WINCONDITION; row++){
		if(inputArray[m+row][n] == 0){
			continue;
		}
		if(inputArray[m][n] == inputArray[m+row][n]){
			count++;
		}else{
			break;
		}
	}
	if(count==WINCONDITION){
		printf("Row detected.\n");
		return inputArray[m][n];
	}

	// printf("Start counting col\n");
	count=0;
	for(col=0; col<WINCONDITION; col++){
		if(inputArray[m][n+col] == 0){
			continue;
		}
		if(inputArray[m][n] == inputArray[m][n+col]){
			count++;
		}else{
			break;
		}
	}
	if(count==WINCONDITION){
		printf("COL detected.\n");
		return inputArray[m][n];
	}

	// printf("Start counting right slope\n");
	count=0;
	for(i=0; i<WINCONDITION; i++){
		if(inputArray[m+i][n+i] == 0){
			break;
		}
		if(inputArray[m][n] == inputArray[m+i][n+i]){
			count++;
		}else{
			break;
		}

	}
	if(count==WINCONDITION){
		printf("right slope detected.\n");
		return inputArray[m][n];
	}

	if( n<WINCONDITION-1 ){
		// printf("[%d][%d]Now way left!\n",m, n);
		return 0;
	}

	// printf("Start counting left slope\n");
	count=0;
	for(i=0; i<WINCONDITION; i++){
		if(inputArray[m+i][n-i] == 0){
			break;
		}
		if(inputArray[m][n] == inputArray[m+i][n-i]){
			count++;
		}else{
			break;
		}
	}
	if(count==WINCONDITION){
		printf("left slope detected.\n");
		return inputArray[m][n];
	}

	return 0;
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

int main(){
	int chess[MAXROW][MAXCOL] = {
		{0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 1, 2, 1, 1, 0, 0, 0},
		{0, 0, 0, 2, 1, 1, 0, 0, 0, 0},
		{0, 0, 2, 1, 2, 2, 2, 0, 0, 0},
		{2, 1, 1, 0, 0, 1, 0, 0, 0, 2},
		{1, 2, 0, 1, 0, 0, 1, 0, 2, 2},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 2},
		{1, 1, 0, 0, 0, 0, 2, 0, 1, 2},
		{1, 0, 0, 0, 0, 1, 2, 2, 2, 1}
	};
	printArray( chess, MAXROW, MAXCOL);

	int x=0, y=0, winner=0;
	for(x=0;x<MAXROW; x++){
		for(y=0;y<MAXCOL; y++){
			//detect function here
			winner = detectWinner(chess, x, y);
			if(winner){
				goto GoodResult;
			}
		}
	}
	printf("Winner Not Detected\n");
	return 0;
GoodResult:
	printf("[%d][%d]Detected winner is %d\n", x, y, winner);
	return 1;
}
