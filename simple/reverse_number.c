#include <stdio.h>

int reverse_number(int num)
{
	int rev_num = 0;
	while (num != 0)
	{
		rev_num = (rev_num * 10) + (num % 10);
		num = num / 10;	
	}

	return rev_num;
}

void reverse_number_recursion(int num, int *rev_num, int *base_pos)
{
	if (num > 0)
	{
		reverse_number_recursion(num / 10, rev_num, base_pos);
		*rev_num += (num % 10) * (*base_pos);
		*base_pos *= 10;
	}
}

int main()
{
	int n = 12345;
	printf("Reverse of %d: %d\n", n, reverse_number(n));

	int rev_num = 0;
	int base_pos = 1;
	reverse_number_recursion(n, &rev_num, &base_pos);
	printf("Recursive Reverse of %d: %d\n", n, rev_num);

	return 0;
}
