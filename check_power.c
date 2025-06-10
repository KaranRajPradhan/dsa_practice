#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_power(int x, int y)
{
	double logxy = log(y) / log(x);
	
	return logxy == floor(logxy);
}

int main()
{
	printf("%s\n", is_power(2,128) ? "true" : "false");
	printf("%s\n", is_power(2,127) ? "true" : "false");
	printf("%s\n", is_power(5,25) ? "true" : "false");
	printf("%s\n", is_power(3,9) ? "true" : "false");
}
