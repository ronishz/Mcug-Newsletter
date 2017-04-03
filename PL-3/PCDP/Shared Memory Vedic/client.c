#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#define SIZE 30

int main(){

	char *s, *sss;
	key_t key=5678;
	int shmid;
	if((shmid=shmget(key, SIZE, IPC_CREAT)) ==-1)
		perror("shmget failure");
	else{
		if((sss = shmat(shmid, NULL, 0666)) ==(char *) -1)
			perror("shmat failure");
		else{
			s=sss;
			int p = *s;
			printf("2 digit number: %d\n", p);
			
			int tens, ones;
			tens = p / 10;
			ones = p % 10;
			int a, b, c;
			a = tens * tens;
			b = tens * ones * 2;
			c = ones * ones;
			int res[4];
			res[0] = c % 10;
			res[1] = (b + (c/10)) % 10;
			res[2] = (a + ( (b + (c/10)) / 10 )) % 10;
			res[3] = (a + ( (b + (c/10)) / 10 )) / 10;
			int i;
			printf("Multiplication is: ");
			for (i=3; i>=0; i--)
				printf("%d",res[i]);
			printf("\n");
			*s='*';
			shmdt(sss);
		}
	}
}
