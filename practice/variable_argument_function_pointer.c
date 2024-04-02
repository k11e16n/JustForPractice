#include <stdio.h>

struct my_handler_index {
	const char *name;
	int (*handler)();
};

int handler0 (int a, int b)
{
	return a+b;
}

int handler1 (int a, int b, int c)
{
	return a+b+c;
}

int handler2 (int a, int b, int c, int d)
{
	return a+b+c+d;
}

const struct my_handler_index handler_index[] = {
	[0] = {"handler0", handler0},
	[1] = {"handler1", handler1},
	[2] = {"handler2", handler2},
};

int main (){
	int i;
	printf("%s:%d\n", handler_index[0].name, handler_index[0].handler(1,2));
	printf("%s:%d\n", handler_index[1].name, handler_index[1].handler(1,2,3));
	printf("%s:%d\n", handler_index[2].name, handler_index[2].handler(1,2,3,4));
}
