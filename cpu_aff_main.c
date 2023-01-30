#define _GNU_SOURCE
#include <assert.h>
#include <sched.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    //printf("nproc = %ld\n",nproc);
    printf("sched_getaffinity = ");
    for (i = 0; i < nproc; i++)
    {
        printf("%d ", CPU_ISSET(i, &mask));
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    cpu_set_t mask;
    int p,nproc;
    //printf("pid of process : %d\n",getpid());
    //wn5gNr_print_affinity();
    //printf("sched_getcpu = %d\n", sched_getcpu());
    wn5gNr_print_affinity();
    int n = atoi(argv[1]);
    nproc = sysconf(_SC_NPROCESSORS_ONLN);
    printf("number of processors : %d\n",nproc);
    p = nproc-1;
    printf("select processor in between '0'-'%d'\n",p); 
    
    switch(n)
    {
    case 0:
        CPU_ZERO(&mask);
        //while(1){
	    CPU_SET(0,&mask);
	//}
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1) 
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());// determine cpu on which the calling thread is running   
        break;
    case 1:
        CPU_ZERO(&mask);
        //while(1){
	CPU_SET(1,&mask);
	//}
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 2:
        CPU_ZERO(&mask);
        //while(1){
	CPU_SET(2, &mask);
	//}
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 3:
        CPU_ZERO(&mask);
        //while(1){
	CPU_SET(3, &mask);
	//}
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 4:
        CPU_ZERO(&mask);
        CPU_SET(4, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 5:
        CPU_ZERO(&mask);
        CPU_SET(5, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 6:
        CPU_ZERO(&mask);
        CPU_SET(6, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 7:
        CPU_ZERO(&mask);
        CPU_SET(7, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 8:
        CPU_ZERO(&mask);
        CPU_SET(8, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 9:
        CPU_ZERO(&mask);
        CPU_SET(9, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 10:
        CPU_ZERO(&mask);
        CPU_SET(10, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 11:
        CPU_ZERO(&mask);
        CPU_SET(11, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    case 12:
        CPU_ZERO(&mask);
        CPU_SET(12, &mask);
        if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1)
        {
            perror("sched_setaffinity");
            assert(false);
        }
        wn5gNr_print_affinity();
        printf("sched_getcpu = %d\n", sched_getcpu());
        break;
    default :
        printf("Entered value is not valid\n");
        break;
    }
    return EXIT_SUCCESS;
}
