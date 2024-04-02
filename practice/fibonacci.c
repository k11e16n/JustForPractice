#include <stdio.h>
#include <time.h>

int F1( int n ){
	if( n == 0 || n == 1){
		return n;
	}
	return F1(n-2) + F1(n-1);
}

int F2( int n){
	if( n == 0 || n == 1){
		return n;
	}
	int i=0, result=0, pre1=1, pre2=0;
	for(i=2; i<=n; i++){
		result = pre2+pre1;
		pre2=pre1;
		pre1=result;
	}
	return result;
}

int main(int argc, char* argv[]){
	int input=atoi(argv[1]);
	clock_t begin = clock();

	printf("F1:%d\n", F1(input));
	clock_t end = clock();
	printf("spend time:%f\n" ,(double)(end - begin) / CLOCKS_PER_SEC);

	begin = clock();
	printf("F2:%d\n", F2(input));
	end = clock();
	printf("spend time:%f\n" ,(double)(end - begin) / CLOCKS_PER_SEC);
}
