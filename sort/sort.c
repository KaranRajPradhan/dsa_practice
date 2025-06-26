#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length)
{
	bool swapped = false;
	int i = 0;
	do
	{
		swapped = false;
		for (int j=0; j<(length-1-i); j++)
		{

			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped = true;
			}
		}
		i++;
	} while (swapped);
}

void selection_sort(int a[], int length)
{
	for (int i=0; i<(length-1); i++)
	{
		int min_pos = i;
		for (int j=i+1; j<(length); j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		if (min_pos != i)
		{
			int temp = a[min_pos];
			a[min_pos] = a[i];
			a[i] = temp;
		}
	}
}

void insertion_sort(int a[], int length)
{
	for (int i=1; i<length; i++)
	{
		int j = i - 1;
		int key = a[i];
		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main(void)
{
	int a[] = {1,3,7,9,0,2,4,5,8,6};
	int length = 10;

	printf("Array before sort:\n");
	for (int i=0; i<length; i++)
		printf("%d,", a[i]);
	printf("\n");

	// bubble_sort(a, length);
	//selection_sort(a, length);
	insertion_sort(a, length);
	
	printf("Array after sort:\n");
	for (int i=0; i<length; i++)
		printf("%d,", a[i]);
	printf("\n");
}

