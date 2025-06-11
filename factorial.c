#include <stdio.h>

int find_factorial(int num)
{
	int fact = 1;

	for (int i=num; i>1; i--)
		fact *= i;

	return fact;

}

int find_factorial_recursive(int num)
{
	if (num == 1)
		return 1;
	return num * find_factorial_recursive(num-1);
}

int main()
{
	int a = 5;
	int b = 10;

	printf("Factorial of %d: %d\n", a, find_factorial(a));
	printf("Factorial of %d: %d\n", b, find_factorial(b));

	
	printf("Recursive Factorial of %d: %d\n", a, find_factorial_recursive(a));
	printf("Recursive Factorial of %d: %d\n", b, find_factorial_recursive(b));
	
	return 0;
}
