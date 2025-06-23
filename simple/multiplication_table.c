#include<stdio.h>

void print_table(int num)
{
	for (int i = 1; i <= 10; i++)
		printf("%d * %d = %d\n", num, i, num*i);
}

void print_table_recursive(int num, int i)
{
	if (i == 11) return;
	printf("%d * %d = %d\n", num, i, num*i++);
	//i++;
	print_table_recursive(num, i);
}

int main()
{
	print_table(5);
	print_table_recursive(10, 1);
}
