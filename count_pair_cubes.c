#include <stdio.h>
#include <math.h>

int count_pairs(int num)
{
	int count = 0;
	for (int i=1; i*i*i<=num; i++)
	{
		int cb = i*i*i;
		int diff = num - cb;
		int cbrtdiff = cbrt(diff);

		if (cbrtdiff*cbrtdiff*cbrtdiff == diff)
			count++;
	}
	return count;
}

int main()
{
	int n = 9;
	printf("Count of pairs for %d: %d\n", n, count_pairs(n));
}
