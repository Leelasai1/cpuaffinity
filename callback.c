#define _GNU_SOURCE
#include <assert.h>
#include <sched.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void thread_function();


/* Enable this code to get the no.of CPU's. Call from main function */ 
 
#if 0 
void wn5gNr_print_affinity()
 {
    cpu_set_t mask;
    long nproc, i;

    if (sched_getaffinity(0, sizeof(cpu_set_t), &mask) == -1)
    {
        perror("sched_getaffinity");
        assert(false);
    }
    nproc = sysconf(_SC_NPROCESSORS_ONLN); //returns number of processors currently online.
    printf("sched_getaffinity = ");
    for (i = 0; i < nproc; i++)
    {
        printf("%d ", CPU_ISSET(i, &mask));
    }
    printf("\n");
 }
#endif


int main(int argc,char *argv[])
{
   // wn5gNr_print_affinity();
    
    int nproc, i;
    nproc = sysconf(_SC_NPROCESSORS_ONLN); //returns number of processors currently online.
//    printf("Number of CPU core : %d\n",nproc);
    i=nproc-1;
//    printf("Enter values in between '0'-'%d'\n",i);
    int var1=atoi(argv[1]);
    int var2=atoi(argv[2]);
    printf("Thread_1 value : %d\nThread_2 value : %d\n",var1,var2); 
    

    if((var1<0) || (var1>i))
    {
        printf("value_1 is less than or more than number of CPU's\n");
        return 0;
    }else if((var2<0) || (var2>i))
    {
        printf("value_2 is less than or more than number of CPU's\n");
        return 0;
    }
    

/*    if((var1<0) || (var1>i))
    {
        printf("value_1 is less than or more than number of CPU's\n");
        return 0;
    }
*/
    cpu_set_t set_1,set_2;
    CPU_ZERO(&set_1); 
    CPU_SET(var1,&set_1);
  
    CPU_ZERO(&set_2);
    CPU_SET(var2,&set_2);

    pthread_t thread_1,thread_2;
    pthread_create(&thread_1,NULL,(void *)thread_function,NULL);
    pthread_create(&thread_2,NULL,(void *)thread_function,NULL);
   
    pthread_setaffinity_np(thread_1,sizeof(cpu_set_t),&set_1);
    pthread_setaffinity_np(thread_2,sizeof(cpu_set_t),&set_2);
    
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);


}

void thread_function()
{
    int nproc, i;
    nproc = sysconf(_SC_NPROCESSORS_ONLN); //returns number of processors currently online.    
    printf("no of processor : %d\n",nproc);
}




