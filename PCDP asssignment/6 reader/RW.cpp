#include<stdio.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

int main()
{
 int i=0,NumberofReaderThread=0,NumberofWriterThread;

 

omp_lock_t writelock;
omp_init_lock(&writelock);

int readCount=0;

 printf("\nEnter number of Readers thread(MAX 10)");
 scanf("%d",&NumberofReaderThread); 
 printf("\nEnter number of Writers thread(MAX 10)");
 scanf("%d",&NumberofWriterThread); 

int tid=0;
#pragma omp parallel
#pragma omp for

 for(i=0;i<NumberofReaderThread;i++)
 {
    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );
    sleep(2); 
    

    printf("\nReader %d is trying to enter into the Database for reading the data",i);


    omp_set_lock(&writelock);
    readCount++;
    if(readCount==1)
    {

      printf("\nReader %d is reading the database",i); 
    }
    
    omp_unset_lock(&writelock);
    readCount--;
    if(readCount==0)
    {
      printf("\nReader %d is leaving the database",i);  
    }
 }

#pragma omp parallel shared(tid)
#pragma omp for nowait
 for(i=0;i<NumberofWriterThread;i++)
 { 
    
    printf("\nWriter %d is trying to enter into database for modifying the data",i);
  
    omp_set_lock(&writelock);

    printf("\nWriter %d is writting into the database",i); 
    printf("\nWriter %d is leaving the database",i); 
    
    omp_unset_lock(&writelock);
 }
 
  omp_destroy_lock(&writelock); 
 return 0;
}

/*output:
[student@student ~]$ gedit rw.cpp
[student@student ~]$ g++ -g -fopenmp rw.cpp
[student@student ~]$ ./a.out

Enter number of Readers thread(MAX 10)3

Enter number of Writers thread(MAX 10)2
Current local time and date: Fri Mar 27 15:13:42 2015
Current local time and date: Fri Mar 27 15:13:42 2015

Reader 2 is trying to enter into the Database for reading the data
Reader 2 is reading the database
Reader 2 is leaving the database
Reader 0 is trying to enter into the Database for reading the data
Reader 0 is reading the database
Reader 0 is leaving the databaseCurrent local time and date: Fri Mar 27 15:13:44 2015

Reader 1 is trying to enter into the Database for reading the data
Reader 1 is reading the database
Reader 1 is leaving the database
Writer 0 is trying to enter into database for modifying the data
Writer 0 is writting into the database
Writer 0 is leaving the database
Writer 1 is trying to enter into database for modifying the data
Writer 1 is writting into the database
Writer 1 is leaving the database[student@student ~]$ 
*/

