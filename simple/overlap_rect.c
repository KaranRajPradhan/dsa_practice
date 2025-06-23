#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int check_overlap(Point l1, Point r1, Point l2, Point r2)
{
	if (l1.x > r2.x || l2.x > r1.x)
		return 0;
	if (r1.y > l2.y || r2.y > l1.y)
		return 0;
	return 1;
}

int main()
{
	Point l1 = { 0, 10 }, r1 = { 10, 0 };
	Point l2 = { 5, 5 }, r2 = { 15, 0 };
	Point l3 = { 15, 5 }, r3 = { 20, 0 };

	if (check_overlap(l1, r1, l2, r2))
		printf("Rectangles Overlap\n");
	else
		printf("Rectangles Don't Overlap\n");
	
	
	if (check_overlap(l1, r1, l3, r3))
		printf("Rectangles Overlap\n");
	else
		printf("Rectangles Don't Overlap\n");
	
	return 0;
}

