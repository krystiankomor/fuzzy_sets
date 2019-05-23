#include "line.h"

Line::Line()
{
}

Line::Line(Point p1, Point p2)
{
	double x1 = p1.getX();
	double x2 = p2.getX();
	double y1 = p1.getY();
	double y2 = p2.getY();

	if(x1 != x2)
	{
		a = (y2 - y1) / (x2 - x1);
		b = y1 - (a * x1);
	}
	else
	{
		x = x1;
		onlyX = true;
	}

}

Line::~Line()
{
}

double Line::getA()
{
	return a;
}

double Line::getB()
{
	return b;
}

void Line::show(bool newLine)
{
	if(onlyX)
	{
		cout << "x = " << x;
		if(newLine) cout << endl;
	}
	else
	{
		cout << "y = ";
		if(a != 0)
		{
			cout << a << "x ";
			if(b > 0)
			{
				cout << "+ " << b;
			}
			else if(b < 0)
			{
				cout << "- " << (-1 * b);
			}
		}
		else
		{
			cout << b;
		}
		if(newLine)
		{
			cout << endl;
		}
	}
}
