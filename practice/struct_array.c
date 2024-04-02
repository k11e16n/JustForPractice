#include <stdio.h>
#include <stdlib.h>


struct myStruct
{
	int a;
};

foo2( struct myStruct *ker){
	ker->a=4;
}

foo1( struct myStruct ker[]){
	ker[0].a=3;
	printf("%d\n",ker[0].a);
	foo2(&ker[0]);
}

void foo3(char* test){
	char* name = alloca(10);
	snprintf(name, sizeof(name), "fuck");
	printf("in foo3:[%s]\n",name);
	memcpy(test,name, sizeof(test));
}

void foo4(char res[])
{
	snprintf(res, sizeof(res), "123456789");
	printf("sizeof(res):%d\n", sizeof(res));
}

int main( int argc, char* argv[] ){

	struct myStruct ker[2] = {1,2};
	printf("%d,%d\n",ker[0].a, ker[1].a);
	foo1(ker);
	printf("%d,%d\n",ker[0].a, ker[1].a);

	char *test=alloca(10);
	char test2[10]={0};
	foo3(test);
	foo4(test2);
	printf("[%s][%s]\n", test,test2);
	return 1;
}
