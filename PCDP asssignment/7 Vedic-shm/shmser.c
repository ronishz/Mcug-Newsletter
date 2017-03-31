#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
 

#define SHMSZ     27

int square(int n);

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
	int i,n=52;
    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5678;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 1;
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
        return 1;
    }
    
   /*
    * Sleep until Client sends data
    */
     while (*shm != '*')    
        sleep(1);
    s = shm;    //Intialize pointer s to shared memory
 
   s++;         //Increament s as first char is '*'
   /*
    * Take char form of number in m from shared mem using pointer s
    */
   char m=*s;   
   /*
    * Convert number from charecter form to into its original form(int)
    */
   n=(int)m;
   /*
    * Call function square
    */
    int r=square(n);
    s=shm;      //Reinitialize pointer s
    s++;        //Increment it to leave space for '%' which wakes up client
    
    int a=1000;
    /*
     *Put the result on shared memory by converting one by one digit to its
     *charecter ascii equivalent.
     */
    for (i=0;i<4;i++){
        *s = (char)(r/a+48);
        r=r%a;
        a=a/10;
        s++;
        }
    s = NULL;   //Put last char as NULL
    /*
     *Put first char as '%' to indicate that server has put the result on 
     *shared memory & client can wakes up and procide
     */
    *shm='%';   
    /*
     *Wait until client finished;
     */
    while (*shm != '$')
        sleep(1);

    return 0;
}
/*
 *Function to square a 2-digit number using vedic mathematics
 */
int square(int n){
	int a,b;
	a=n/10;
	b=n%10;
	int res=a*a*100+a*b*2*10+b*b;
	return res;
}
