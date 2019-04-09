#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "point.h"
#include "line.h"

typedef long unsigned int luint;

using namespace std;
class Line;

class Fuzzy
{
public:
	Fuzzy();
	Fuzzy(const double [], int, bool);
	~Fuzzy();
	bool isNormal();
	void showCore();
	void showHeight();
	void showLines();
	void showNormalization();
	void showPoints();
	void showSupp();
private:
	bool pointsOnly = false;
	double height;
	vector<Point> points;
	vector<Point> normalizedPoints;
	vector<Line> lines;
	vector<Line> normalizedLines;
};

