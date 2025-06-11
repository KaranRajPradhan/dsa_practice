#include <stdio.h>
#include <math.h>

float distance_points(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	printf("Distance: %f\n", distance_points(3, 4, 4, 3) * 1.0);
	
	return 0;
}
