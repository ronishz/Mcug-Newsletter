//Title::N-array Search Using OpenMp(HARDCODED)
#include <stdio.h>
#include <iostream>
#include <omp.h>

#define NN 30

using namespace std;

void BinarySearch (int *A, int lo, int hi, int key, int Ntrvl, int *pos)
{
	float offset, step;
	int  *mid 	= new int[Ntrvl+1];
	char *locate 	= new char[Ntrvl+2];
	int  i;

	locate[0] 	= 'R';
	locate[Ntrvl+1] = 'L';

	#pragma omp parallel
	{
		while (lo <= hi && *pos == -1)
		{
			int lmid;
			// set thread pointers
			#pragma omp single
			{
				mid[0] = lo - 1;
				step = (float)(hi - lo + 1)/(Ntrvl+1);
			}

			#pragma omp for private (offset) firstprivate(step)
			for (i = 1; i <= Ntrvl; i++) {
				offset = step * i + (i - 1);
				lmid = mid[i] = lo + (int) offset;
				if (lmid <= hi)
				{
					if (A[lmid] > key)
						locate[i] = 'L';
					else if (A[lmid] < key)
						locate[i] = 'R';
					else {
						locate[i] = 'E';
						*pos = lmid;
					}
				}
				else
				{
					mid[i] = hi + 1;
					locate[i] = 'L';
				}
			}
			// compare array
			#pragma omp single
			{
				for (i = 1; i <= Ntrvl; i++) {
					if (locate[i] != locate[i-1]) {
						lo = mid[i-1] + 1;
						hi = mid[i] - 1;
					}
				}
				if (locate[Ntrvl] != locate[Ntrvl+1])
					lo = mid[Ntrvl] + 1;
			}
		}
	}
	delete[] locate;
	delete[] mid;
}

void init_data(int *S)
{
	int i;
	for (i = 0; i < NN; i++){
		S[i] = 2*i;
	}
}

int main(int argc, char* argv[])
{
	int pos = -1;
	int S[NN];
	int intervals = 4;

	init_data(S);

	for (int j = 0; j < NN; j++){
		printf("%3d ",S[j]);
	}
	printf("\n\n");

	for (int r = 1; r <= 2*NN; r+= 13) {
		pos = -1;
		BinarySearch(S, 0, NN-1, r, intervals, &pos);
		if (pos != -1) printf("key = %d found at index %d\n", r, pos );
		else printf("key = %d NOT found.\n",r);
	}
	printf("\n\n");

	return 0;
}

/* OUTPUT:

student@B4L0106:~$ cd Desktop
student@B4L0106:~/Desktop$ g++ -g -fopenmp orgn-ary.cpp
student@B4L0106:~/Desktop$ ./a.out
  0   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30  32  34  36  38  40  42  44  46  48  50  52  54  56  58

key = 1 NOT found.
key = 14 found at index 7
key = 27 NOT found.
key = 40 found at index 20
key = 53 NOT found.


student@B4L0106:~/Desktop$
*/
