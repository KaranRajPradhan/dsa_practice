#include <stdio.h>
#include <string.h>

int sum_of_digits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		int ld = num % 10;
		sum += ld;
		num /= 10;
	}

	return sum;
}

int recursive_sum(int num)
{
	if (num == 0)
		return 0;

	return (num % 10) + recursive_sum(num/10);
	
}

int string_sum_of_digits(char *s)
{
	int sum = 0;
	for (int i=0; i<strlen(s); i++)
	{
		int digit = s[i] - '0';
		sum += digit;
	}

	return sum;
}


int main()
{
	int n = 54321;
	
	printf("Sum of digits of %d: %d\n", n, sum_of_digits(n));


	printf("Recursive sum of digits of %d: %d\n", n, recursive_sum(n));
	
	char *str = "54321";
	printf("ASCII sum of digits of %s: %d\n", str, string_sum_of_digits(str));

	return 0;
}

