#include<stdio.h>
#include<math.h>

typedef struct{
	int x;
	int y;
}Point;

double dist(Point p1,Point p2)
{
	return hypot(p1.x-p2.x,p1.y-p2.y);
}


int main()
{
	Point p1;
	Point p2;
	p1.x=1;
	p1.y=1;
	p2.x=2;
	p2.y=2;
	printf("%f",dist(p1,p2));
	return 0;
}
