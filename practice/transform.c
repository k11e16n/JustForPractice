#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *s){ 
	int sum = 0; 
	for(int i = 0;s[i] != '\0';i++){
		sum = sum*10+s[i]-'0'; 
	} 
	return sum; 
};

void itoa(int n,char *s){ int flag = 1;
	if (n<0){ 
		n = -n;
		flag = 0;
	}
	int i = 0;
	while(n != 0){
		//注意要把'0'加回來 
		s[i++] = n%10+'0'; 
		n = n/10; 
	} 
	if(!flag) s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
} void reverse(char *s){ 
	for(int i = 0,j = strlen(s)-1;i<j;i++,j--){ 
		int c = s[i]; 
		s[i] = s[j];
		s[j] = c; 
	} 
}
int main(){
	char s[] = "12345"; //string to integer 
	int i = my_atoi(s); 
	printf("%d\n",i); 
}
