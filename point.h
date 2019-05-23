#pragma once
#include <iostream>

using namespace std;

class Point
{
public:
	Point();
	Point(const Point &, double);
	Point(double, double);
	~Point();
	double getX();
	double getY();
	void show();
	bool operator<(const Point &);
private:
	double x;
	double y;
};

