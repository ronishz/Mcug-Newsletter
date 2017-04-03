#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#define SIZE 30

int main(){

	char *s, *sss;
	key_t key=5678;
	int shmid;
	if((shmid=shmget(key, SIZE, IPC_CREAT)) == -1)
		perror("shmget failure");
	else{
		if((sss = shmat(shmid, NULL, 0666 )) == (char *) -1)
			perror("shmat failure");
		else{
			s=sss;
			int p;
			printf("Enter a 2 digit number:");
			scanf("%d",&p);
			*s=p;
			
			while(*s!='*')
				printf("");
			shmdt(sss);
		}
	}
}
