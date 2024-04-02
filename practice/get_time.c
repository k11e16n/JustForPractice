#include <stdio.h>
#include <time.h>

int main(){

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "timestamp:%ld\n", time(NULL) );
	printf ( "Current local time and date: %s\n", asctime (timeinfo) );

	return 0;
}
