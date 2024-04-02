#include <stdio.h>

int highest_bit_position(int i)
{
	i |= (i >>  1);  
	i |= (i >>  2);  
	i |= (i >>  4);  
	i |= (i >>  8);  
	i |= (i >> 16);  
	return i - (i >> 1);
}

int main(){
	int input;
	printf("input a int number: ");
	scanf("%d", &input);
	printf("bit position:%d\n", highest_bit_position(input));
}
