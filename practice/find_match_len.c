#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max( int a, int b){
	return (a>b)?a:b;
}

int max_match_length( char * str1, char * str2){
	int i, j, result, **array, *array_data;
	int str1_len=strlen(str1)+1;
	int str2_len=strlen(str2)+1;

	// alloc the size and construct the array
	array = (int**)malloc( sizeof(int*)*str1_len + sizeof(int)*str1_len*str2_len);
	for (i = 0, array_data = (int *)(array+str1_len); i < str1_len; i++, array_data += str2_len){
		array[i]=array_data;
	}

	// initial the first element
	for (i=0; i<str1_len; i++){
	       	array[i][0] = 0;
	}
	for (j=0; j<str2_len; j++){
	       	array[0][j] = 0;
	}

	// construct the table
	for (i=1; i<str1_len; i++){
		for (j=1; j<str2_len; j++){
			if (*(str1+i) == *(str2+j)){
				array[i][j] = array[i-1][j-1] + 1;
			}else{
				array[i][j] = max(array[i-1][j], array[i][j-1]);
			}
		}
	}
	result = array[strlen(str1)][strlen(str2)];
	if(array) free(array);
	return result;
}

int main(){
	char str1[256], str2[256];
	printf("input str1:");
	scanf("%s", str1);
	printf("input str2:");
	scanf("%s", str2);
	printf("max=%d\n", max_match_length(str1,str2));
}
