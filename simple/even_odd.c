#include <stdio.h>
#include <stdbool.h>

bool is_even_mod(int num)
{
	return (num % 2 == 0);
}


bool is_even_and(int num)
{
	return ((num & 1) == 0);
}


bool is_even_shift(int num)
{
	return (num == ((num >> 1) << 1));
}

int main()
{
	int a = 100;
	int b = 101;

	is_even_mod(a) ? printf("%d is even\n", a) : printf("%d is odd\n", a);
	is_even_mod(b) ? printf("%d is even\n", b) : printf("%d is odd\n", b);


	is_even_and(a) ? printf("%d is even\n", a) : printf("%d is odd\n", a);
	is_even_and(b) ? printf("%d is even\n", b) : printf("%d is odd\n", b);


	is_even_shift(a) ? printf("%d is even\n", a) : printf("%d is odd\n", a);
	is_even_shift(b) ? printf("%d is even\n", b) : printf("%d is odd\n", b);
}

