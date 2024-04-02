#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *PrintHello(void)
{
	pthread_detach(pthread_self());
	int stack[1024 * 20] = {0,};
	sleep(1);
	long tid = 0;
	printf("Hello World! It’s me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}
int main (int argc, char *argv[])
{
	pthread_t pid;
	int rc;
	long t;
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&pid, NULL, PrintHello, NULL);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			//exit(-1);
		}
		sleep(3);
	printf(" \n— main End —- \n");
	pthread_exit(NULL);
}
