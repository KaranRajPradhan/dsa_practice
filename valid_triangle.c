#include <stdio.h>
#include <stdbool.h>

// A triangle is valid if sum of any two sides is always greater then the third side
bool valid_triangle(int a, int b, int c)
{
	if ( a + b <= c || a + c <= b || b + c <= a)
		return false;
	return true;
}

int main()
{
	printf("Triangle Valid? %s\n", valid_triangle(7, 10, 5) ? "true": "false");
	printf("Triangle Valid? %s\n", valid_triangle(7, 2, 5) ? "true": "false");

	return 0;
}
