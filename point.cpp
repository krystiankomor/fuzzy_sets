#include "point.h"


Point::Point()
{
}

Point::Point(double valX, double valY)
{
	x = valX;
	y = valY;
}
Point::Point(const Point & p1, double r)
{
	x = p1.x;
	y = p1.y / r;
}

Point::~Point()
{
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Point::show()
{
	cout << x << " " << y << endl;
}

bool Point::operator<(const Point & p2)
{
	if(x < p2.x)
	{
		return true;
	}
	else if(x > p2.x)
	{
		return false;
	}
	else
	{
		if(y < p2.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
