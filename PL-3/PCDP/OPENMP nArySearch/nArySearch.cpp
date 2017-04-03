// Concurrent version of Binary Search
#include <iostream>
#include <omp.h>

using namespace std;
int no1;
void nArySearch (int *A, int lo, int hi, int key, int nAry, int *pos)
{
	float offset, step;
	int  *mid 	= new int[nAry+1];
	char *locate 	= new char[nAry+2];

	locate[0] 	= 'R'; 
	locate[nAry+1] = 'L';

	#pragma omp parallel
	{
		while (lo <= hi && *pos == -1){
			int lmid; // set thread pointers
			#pragma omp single
			{
				mid[0] = lo - 1;
				step = (float)(hi - lo + 1)/(nAry+1);
			}
			
			#pragma omp for private(offset) firstprivate(step)
			for (int i = 1; i <= nAry; i++){
				offset = step * i + (i - 1);
				lmid = mid[i] = lo + (int) offset;
				if (lmid <= hi){
					if (key < A[lmid])
						locate[i] = 'L';
					else if (key > A[lmid])
						locate[i] = 'R';
					else{
						locate[i] = 'E';
						*pos = lmid; 
					} 
				}
				else{
					mid[i] = hi + 1;
					locate[i] = 'L';
				}
			}
			// compare array
			#pragma omp single
			{
				for (int i = 1; i <= nAry; i++){
					if (locate[i] != locate[i-1]){
						lo = mid[i-1] + 1;
						hi = mid[i] - 1;
					}
				}
				if (locate[nAry] != locate[nAry+1]) 
					lo = mid[nAry] + 1;
			}
		}
	}
	delete[] locate;
	delete[] mid;
}

int main(int argc, char* argv[]){	
	int pos = -1, S[no1], r[10], n1, i, nAry = 4;

	cout<<"\nEnter the Number of Elements: ";
	cin>>no1;

	cout<<"\nEnter the Elements: ";
	for (int i = 0; i < no1; i++){
		cin>>S[i];		
	}

	cout<<"\nInput Data is: ";
	for (int j = 0; j < no1; j++){
		cout<<S[j]<<"  ";
	}

	cout<<"\n\nEnter the Number of elements you want to search: ";
	cin>>n1;
	cout<<"\nEnter the elements to be searched: ";
	for(i=0;i<n1;i++){
		cin>>r[i];
	}
	cout<<endl;

	for(int k=0;k<n1;k++){
		pos = -1;
		nArySearch(S, 0, no1-1,r[k], nAry, &pos);
		if (pos != -1) 
			cout<<"Key = "<<r[k]<<" Found at Position = "<<pos+1<<"\n";
		else 
			cout<<"Key = "<<r[k]<<" NOT found.\n",r[k];
	}	
	return 0;
}
