#include <stdio.h>

#define SIZE 10 
#define BLOCKS 1
#define THREADS_PER_BLOCK 5

__global__ void OddEvensort(int *array, int size) {

	bool odd = true;
	__shared__ bool swappedodd;
	__shared__ bool swappedeven;

	int temp;
	swappedodd  = true;
	swappedeven = true;
	
	while (true) {
		if (odd == true) {
			//Swapping at Odd locations
			__syncthreads();
			swappedodd = false;
			__syncthreads();
			
			int idx = threadIdx.x + blockIdx.x * blockDim.x;
			
			if (idx<(size / 2)) {
				if (array[2 * idx]>array[2 * idx + 1]) {
					printf("\nThread Id %d : is swapping %d <-> %d \
					\nThread Id %d : [%d] <-> [%d]\n", idx, array[2 * idx], \
					array[2 * idx + 1], idx, 2 * idx, (2 * idx + 1));
					//swap the numbers at odd location (array[2*idx],array[2*idx+1]);
					temp = array[2 * idx];
					array[2 * idx] = array[2 * idx + 1];
					array[2 * idx + 1] = temp;
					swappedodd = true;
				}
			}
			__syncthreads();
		
		} else {
			//Swapping at Even locations
			__syncthreads();
			swappedeven = false;
			__syncthreads();

			int idx = threadIdx.x + blockIdx.x * blockDim.x;
			if (idx<(size / 2) - 1) {
				if (array[2 * idx + 1] > array[2 * idx + 2]) {
					printf("\nThread Id %d : is swapping %d <-> %d\
					\nThread Id %d : [%d] <-> [%d]\n\
					", idx, array[2 * idx + 1], array[2 * idx + 2], idx, \
					(2 * idx + 1), (2 * idx + 2));
					//swap the numbers at even location(array[2*idx+1],array[2*idx+2]);
					temp = array[2 * idx + 1];
					array[2 * idx + 1] = array[2 * idx + 2];
					array[2 * idx + 2] = temp;
					swappedeven = true;
				}
			}
			__syncthreads();
		}

		if (!(swappedodd || swappedeven))
			break;

		odd = !odd;
	}
	__syncthreads();
}

int main(void)
{
	int *a, *a_sorted, i;
	int *d_a;
	int size = sizeof(int)*SIZE;

	cudaMalloc((void**)&d_a, size);

	a = (int*)malloc(size);
	a_sorted = (int*)malloc(size);

	printf("\nEnter %d numbers to sort: ", SIZE);
	for (i = 0; i< SIZE; i++) {
		scanf("%d", &a[i]);
	}

	printf("\nUnsorted array is:\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}printf("\n");

	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);

	OddEvensort<<<BLOCKS, THREADS_PER_BLOCK>>>(d_a, SIZE);

	cudaMemcpy(a_sorted, d_a, size, cudaMemcpyDeviceToHost);
	
	printf("\nSorted array is:\n");
	for (i = 0; i<SIZE; i++) {
		printf("%d ", a_sorted[i]);
	}printf("\n");

	free(a);
	free(a_sorted);
	cudaFree(d_a);
	
	return 0;
}
