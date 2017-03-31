//Title::N-array Search Using OpenMp(User Input)
#include <stdio.h>
#include <iostream>
#include <omp.h>
//#define NN 30

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

void init_data(int *S,int NN)
{
	int i;

	printf("Enter elements:");
	for (i = 0; i < NN; i++){
	scanf("%d",&S[i]);
	}
}

int main(int argc, char* argv[])
{
	int pos = -1,NN,j,n;

	printf("Enter size of array:");
	scanf("%d",&NN);

	int S[NN];
	int intervals = 1;



	init_data(S,NN);

	for (int j = 0; j < NN; j++){
		printf("%3d ",S[j]);
	}
	printf("\n\n");


	printf("Enter no of elements you want to search:");
	scanf("%d",&n);
	int r[n];

	printf("Enter element:");

	for(j=0;j<n;j++){

	scanf("%d",&r[j]);
		pos = -1;
		BinarySearch(S, 0, NN-1, r[j], intervals, &pos);
		if (pos != -1) printf("key = %d found at index %d\n", r[j], pos );
		else printf("key = %d NOT found.\n",r);

	}
	printf("\n\n");

	return 0;
}


/*OUTPUT:

student@B4L0106:~/Desktop$ g++ -g -fopenmp n-array.cpp
student@B4L0106:~/Desktop$ ./a.out
Enter size of array:5
Enter elements:2
4
6
7
8
  2   4   6   7   8

Enter no of elements you want to search:3
Enter element:6 2 8
key = 6 found at index 2
key = 2 found at index 0
key = 8 found at index 4
*/



