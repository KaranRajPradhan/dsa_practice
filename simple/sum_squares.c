#include <stdio.h>

int sum_squares(int num)
{
	int sum = 0;
	
	for (int i=1; i<=num; i++)
		sum += i * i;

	return sum;
}

int sum_squares_recursive(int num)
{
	if (num == 0) return 0;
	else return num * num + sum_squares_recursive(num - 1);
}

// n(n+1)(2n+1)/6
int sum_squares_formula(int num)
{
	return (num*(num+1)*((2*num)+1)) / 6;
}

int main()
{
	int n = 5;

	// printf("Sum of %d squares: %d\n", n, sum_squares(n));
	// printf("Sum of %d squares: %d\n", n, sum_squares(n));	
	printf("Sum of %d squares: %d\n", n, sum_squares_formula(n));
}

