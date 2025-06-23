#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)
{
	if (num == 2 || num == 3)
		return true;
	if (num <= 1 || num % 2 == 0 || num % 3 == 0)
		return false;
	for (int i=5; i*i <= num; i+=6)
	{
		if ((num % i == 0) || (num % i+2 == 0))
			return false;
	}
	return true;
}

int main()
{
	for (int i=0; i<20; i++)
		printf("%d: %d\n", i, is_prime(i));
	
	return 0;
}


