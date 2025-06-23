#include <stdio.h>

int nth_term(int a, int b, int n)
{
	int diff = b - a;
	int nth = a;

	for (int i=1; i<n; i++)
		nth += diff;

	return nth;
}

// t(n) = a(1) + (n-1) * d
int nth_term_formula(int a, int b, int n)
{
	return (a + (n-1) * (b-a));
}

int main()
{
	int a = 2;
	int b = 3;
	int n = 4;

	// printf("%dth term of AP: %d\n", n, nth_term(a, b, n));
	printf("%dth term of AP: %d\n", n, nth_term_formula(a, b, n));

	return 0;
}
