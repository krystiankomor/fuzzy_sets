#pragma once
#include <iostream>
#include <point.h>

using namespace std;


class Line
{
public:
	Line();
	Line(Point, Point);
	~Line();
	double getA();
	double getB();
	void show(bool newLine = true);
private:
	bool onlyX = false;
	double a = 0;
	double b = 0;
	double x = 0;
};

