#include <stdio.h>

void naive_swap(int x, int y)
{
	printf("Before swap: x=%d,y=%d\n", x, y);

	int temp = x;
	x = y;
	y = temp;

	printf("After swap: x=%d,y=%d\n", x, y);
}

void swap_by_reference(int *x, int *y)
{		
	int temp = *x;
	*x = *y;
	*y = temp;	
}

void bitwise_swap(int x, int y)
{
	printf("Before swap: x=%d,y=%d\n", x, y);

	x = x ^ y;
	y = x ^ y;
	x = x ^ y;

	printf("After swap: x=%d,y=%d\n", x, y);
}

int main()
{
	int x = 5;
	int y = 10;

	// naive_swap(x, y);
	
	// bitwise_swap(x, y);
	
	printf("Before swap: x=%d,y=%d\n", x, y);
	swap_by_reference(&x, &y);
	printf("After swap: x=%d,y=%d\n", x, y);
	
	return 0;
}

