#include<stdio.h>
#include<signal.h>
#include<time.h>

int main()
{
	printf("main function\n");
	struct sigevent sev = { 0 };
	timer_t timerid=0;
	
	int id= timer_create(CLOCK_THREAD_CPUTIME_ID,&sev,&timerid);
	timer_gettime(id,TIMER_TOLERANCE,NULL,NULL);
	
}
