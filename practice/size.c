#include<stdio.h>

void foo(char *infunc){
	printf("infunc:%p\n",infunc);
	infunc = "kerker";
	printf("infunc:%p\n",infunc);
	printf("&infunc:%p\n",&infunc);
	printf("result:%s\n",infunc);
}

int main(int argc, char* argv[] )
{
	char str[]="H";
	char *p=str;
	int n=10;
	printf("%zu, %zu, %zu\n",sizeof(str), sizeof(p), sizeof(n));

	int a[]={6,7,8,9,10};
	int *p2 = a;
	*(p2++)+=123;
	*(++p2)+=123;
	for(n=0;n<5;n++){
		printf("%d\n", a[n]);
	}

	printf("sizeof(short)     = %zu\n", sizeof(short));
	printf("sizeof(int)       = %zu\n", sizeof(int));
	printf("sizeof(long)      = %zu\n", sizeof(long));
	printf("sizeof(long long) = %zu\n\n", sizeof(long long));

	printf("sizeof(size_t)    = %zu\n", sizeof(size_t));
	printf("sizeof(off_t)     = %zu\n", sizeof(off_t));
	printf("sizeof(void *)    = %zu\n", sizeof(void *));
	printf("sizeof(char )    = %zu\n", sizeof(char ));
	printf("sizeof(char *)    = %zu\n", sizeof(char *));
	printf("sizeof(bool)    = %zu\n", sizeof(_Bool));

	char *myArray1[50];
	char (*myArray2)[50];
	char myArray3[50];
	printf("size: %zu, %zu, %zu\n", sizeof myArray1, sizeof myArray2, sizeof myArray3);

	short aaa=0x4000;
	int bbb = aaa << 17;
	printf("size: %x%x\n", aaa,bbb);
	printf("size: %llx\n", aaa);
	printf("size: %llx\n", bbb<<17);


	char *inmain = NULL;
	printf("inmain: %p\n", inmain);
	printf("&inmain: %p\n", &inmain);
	foo(inmain);
	printf("result:%s\n",inmain);

	int number=43980;
	int *tp;
	tp=&number;
	*tp=*tp+1;

	printf("0x%x(%d)\n", *tp, *tp);
	printf("0x%x\n", *((unsigned char*)tp));
	printf("%d, %d\n", '0', '1');
}
