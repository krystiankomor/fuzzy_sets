#include <iostream>
#include <algorithm>
#include "fuzzy.h"

int main()
{
	int POINTS = 0;
	cout << "No. of points: ";
	cin >> POINTS;
	int VALUES = POINTS * 2;
	double * points = new double[VALUES];
	double tmp;
	for(int i = 0; i < VALUES; i++)
	{
		cin >> tmp;
		points[i] = tmp;
	}

	Fuzzy * fuzzySet = new Fuzzy(points, POINTS, false);
	
	cout << "Points:" << endl;
	fuzzySet->showPoints();	
	
	cout << "Straight lines:" << endl;
	fuzzySet->showLines();
	
	cout << "Height of set:" << endl;
	fuzzySet->showHeight();
	
	cout << "Core of set:" << endl;
	fuzzySet->showCore();
	
	cout << "The carrier of the fuzzy set:" << endl;
	fuzzySet->showSupp();
	
	cout << "Is normal?" << endl;
	if(fuzzySet->isNormal())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
	
	cout << "Normalization" << endl;
	fuzzySet->showNormalization();
	
	cout << endl;
	
	
	delete fuzzySet;
	delete [] points;
	return 0;
}
