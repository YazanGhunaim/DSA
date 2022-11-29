#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// merge but modified to work with a single list
void merge(int a[], size_t mid, size_t l, size_t h)
{
	int data[h+1];

	size_t i,j,k;
	i = l;
	j = mid + 1;
	k = l;	

	while(i <= mid && j <= h){
		if (a[i] < a[j])
		{
			data[k++] = a[i++];
		}
		else
		{
			data[k++] = a[j++];
		}
	}

	for (;i <= mid;++i)
		data[k++] = a[i];
	for (;j <= h;++j)
		data[k++] = a[j];

	// copy elements back to original array
	for (size_t i = l; i <= h; ++ i)
		a[i] = data[i];
}

void mergeSort(int array[], size_t l, size_t h)
{
	size_t mid;

	if (l < h)
	{	
		mid = (l + h) / 2;
		mergeSort(array,l,mid);
		mergeSort(array,mid + 1,h);
		merge(array,mid,l,h);
	}
}

void printArray(int *array, size_t size)
{
	for (size_t i = 0; i < size; ++ i)
		printf("%d ", *(array + i));

	printf("\n");
}

void getLowHigh(size_t * low, size_t * high, size_t sizeOfArray)
{
	*low = 0;
	*high = sizeOfArray - 1;
}

int main(int argc, char const *argv[])
{
	int array[] = {6,1,8,2,6,7,8,9,10,11,5,1,9,2,3,49,151,128,11,212,0,-10,-5};
	
	size_t l,h;
	size_t sizeOfArray = sizeof(array)/sizeof(array[0]);
	
	getLowHigh(&l,&h);

	mergeSort(array,l,h);

	printArray(array, sizeOfArray);

	return 0;
}
