#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*Merging function to merge two sorted lists into one whole sorted list using merging procedure.*/

int * merge(int a[], int b[], size_t length_a, size_t length_b){
	
	int * c = (int *) malloc((length_a + length_b) * sizeof(*c));

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while(i < length_a && j < length_b){
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		} 
		else 
		{
			c[k++] = b[j++];
		}
	}
	// after we completely go through all elements of one list we put the remaining elements of the other list in C
	for (;i < length_a;++i)
		c[k++] = a[i];
	for (;j < length_b;++j)
		c[k++] = b[j];

	return c;
}

bool testArray(int array[], int expectedResult[], size_t size)
{	
	size_t i;
	for (i = 0; i < size; ++i){
		if (array[i] != expectedResult[i])
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{	

	int a[] = {5,10,11,13,16,20};
	int b[] = {1,2,3,4,6};

	int * test = merge(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	int expected[] = {1,2,3,4,5,6,10,11,13,16,20};

	int a2[] = {-5,0,1,4,6,8,9,12,55};
	int b2[] = {3,4,11,99,102};

	int * test2 = merge(a2,b2,sizeof(a2)/sizeof(a2[0]),sizeof(b2)/sizeof(b2[0]));
	int expected2[] = {-5,0,1,3,4,4,6,8,9,11,12,55,99,102};

/*--------------------------------Unit Tests---------------------------------*/
	assert(testArray(test,expected,sizeof(expected)/sizeof(expected[0])));
	assert(testArray(test2,expected2,sizeof(expected2)/sizeof(expected2[0])));
/*---------------------------------------------------------------------------*/

	free(test);
	free(test2);
	
	return 0;
}
