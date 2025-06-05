#include <stdio.h>

int find_sum(int num)
{
	int sum = 0;
	for (int i=1; i<=num; i++)
		sum = sum + i;
	return sum;
}

int find_sum_recursive(int num)
{
	if (num == 0) return 0;
	else return num + find_sum_recursive(num-1);
}

// (n(n+1))/2
int find_sum_formula(int num)
{
	return (num * (num+1)) / 2;
}

int main()
{
	int n = 5;
	//printf("Sum of %d natural numbers: %d\n", n, find_sum(n));
	//printf("Sum of %d natural numbers: %d\n", n, find_sum_recursive(n));
	printf("Sum of %d natural numbers: %d\n", n, find_sum_formula(n));
}

