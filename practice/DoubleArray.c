#include <stdio.h>
#include <stdlib.h>


int allocate2DArray( int ***input_array, int rows, int cols){

    int **arr = NULL;
    /* allocate rows */
    arr = (int **)malloc( rows * sizeof(int *) );
    if (arr == NULL) return 0;

    /* allocate cols */
    for(int i = 0; i < rows; i++){
        arr[i] = (int *) malloc( cols * sizeof(int) );
        if (arr[i] == NULL) return 0;
    }

    *input_array = arr;
    return 1;
}

int free2DArray( int **matrix, int rows){
    for(int i = 0; i < rows; i++){
        free( matrix[i]);
    }
    free(matrix);
    return 1;
}

#define METHOD 2
int main() {
    int **matrix = NULL;
    int rows = 3, cols = 4;


#if METHOD == 1 
    matrix = (int**) malloc( rows * sizeof(int *) );
    if(matrix == NULL){
        printf("alloc error\n");
    }

    for(int i = 0; i < rows; i++){
        matrix[i] = (int* ) malloc( cols * sizeof(int) );
    }
#endif

#if METHOD == 2
    allocate2DArray(&matrix, rows, cols);
#endif

    /* Print out */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    free2DArray(matrix, rows);

    return 1;
}
