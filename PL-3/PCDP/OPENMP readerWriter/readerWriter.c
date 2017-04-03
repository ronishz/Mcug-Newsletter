#include<omp.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>

int var=100;
int ReadCount=0;
sem_t Sem;

void main()
{
	sem_init(&Sem, 0, 1);
	int ThreadId = 0;
	int NReader, NWriter;
	int i,j;

	printf("\nEnter number of readers: ");
	scanf("%d",&NReader);
	printf("Enter number of writers: ");
	scanf("%d",&NWriter);
	printf("\n");
	#pragma omp parallel num_threads((NReader+NWriter)) shared(ThreadId)       //threadId variable is shared among all the threads
	{
	    printf("Executing in parallel region.....\n");

	    #pragma omp for nowait
	    for(i=0 ; i<NReader ; i++)
	    {	
		printf("Reader %d started\n",i);

		        sem_wait(&Sem);

		ThreadId = omp_get_thread_num();
		printf("Reader %d with thread id %d is reading shared variable %d\n",i,ThreadId,var);    

		        sem_post(&Sem);
	    }

	    #pragma omp for nowait
	    for(j=0 ; j<NWriter ; j++)
	    {
		printf("Writer %d started\n",j);

		sem_wait(&Sem);
		sleep(1);

		var=var+100;

		ThreadId = omp_get_thread_num();
		printf("Writer %d with ThreadId %d has updated the shared variable to %d\n",j,ThreadId,var);

		sem_post(&Sem);
	    }
	}//end of parallel construct
}
