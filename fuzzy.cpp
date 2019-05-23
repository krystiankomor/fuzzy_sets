#include "fuzzy.h"


Fuzzy::Fuzzy()
{
}

Fuzzy::Fuzzy(const double * p, const int & s, const bool & b = false)
{
	double tmpX, tmpY;

	pointsOnly = b;

	for(int i = 0; i < s * 2; i = i + 2)
	{
		tmpX = *(p + i);
		tmpY = *(p + i + 1);

		points.push_back(Point(tmpX, tmpY));

		if(i == 0 || tmpY > height)
		{
			height = tmpY;
		}
	}

	sort(points.begin(), points.end());

	for(int i = 0; i < s; i++)
	{
		normalizedPoints.push_back(Point(points[i], height));
	}
	for(int i = 0; i < s - 1; i++)
	{
		lines.push_back(Line(points[i], points[i + 1]));
		normalizedLines.push_back(Line(normalizedPoints[i], normalizedPoints[i + 1]));
	}
}

Fuzzy::~Fuzzy()
{
}

bool Fuzzy::isNormal()
{
	return height == 1;
}

void Fuzzy::showCore()
{
	cout << "core(A) = ";
	if(height != 1)
	{
		cout << "empty" << endl;
		return;
	}
	Point * p;
	luint limit = points.size();
	for(luint i = 0; i < limit; i++)
	{
		p = &points[i];
		if(p->getY() == 1)
		{
			if(i + 1 < limit && (p + 1)->getY() == 1)
			{
				cout << "[" << p->getX() << ",";
				int i2 = 1;
				while(i + i2 < limit && (p + i2)->getY() == 1)
				{
					++i2;
				}
				cout << (p + i2 - 1)->getX() << "]";
				i = i + i2 - 1;
			}
			else
			{
				cout << "{" << p->getX() << "}";
			}
		}
	}

	cout << endl;
}
void Fuzzy::showHeight()
{
	cout << "u(A) = " << height << " at x";

	Point * p;
	luint limit = points.size();
	for(luint i = 0; i < limit; i++)
	{
		p = &points[i];
		if(p->getY() == height)
		{
			if(i + 1 < limit && (p + 1)->getY() == height)
			{
				cout << "[" << p->getX() << ",";
				int i2 = 1;
				while(i + i2 < limit && (p + i2)->getY() == height)
				{
					++i2;
				}
				cout << (p + i2 - 1)->getX() << "]";
				i = i + i2 - 1;
			}
			else
			{
				cout << "{" << p->getX() << "}";
			}
		}
	}
	cout << endl;
}

void Fuzzy::showLines()
{
	for(luint i = 0; i < lines.size(); i++)
	{
		lines[i].show(false);
		cout << " in x[" << points[i].getX() << "," << points[i+1].getX();
		if(i == lines.size() - 1)
			cout <<"]";
		else
			cout << ")";
		cout << endl;
	}
}

void Fuzzy::showNormalization()
{
	if(height == 1){
		cout << "None"<< endl;
		return;
	}
	for(luint i = 0; i < normalizedLines.size(); i++)
	{
		normalizedLines[i].show(false);
		cout << " in x[" << normalizedPoints[i].getX() << "," << normalizedPoints[i+1].getX();
		if(i == normalizedLines.size() - 1)
			cout <<"]";
		else
			cout << ")";
		cout << endl;
	}
}

void Fuzzy::showPoints()
{
	int i = 1;
	for(Point p : points)
	{
		cout << "P" << i++ << ": " << p.getX() << " " << p.getY() << endl;
	}
}

void Fuzzy::showSupp()
{
	cout << "supp(A) = ";
	Point * p;
	luint limit = points.size();
	for(luint i = 0; i < limit; i++)
	{
		p = &points[i];
		if(p->getY() > 0)
		{
			if(i == 0) cout << "[" << p->getX();
			else cout << "(" << (p - 1)->getX();

			cout << ",";

			int i2 = 1;
			while(i + i2 < limit && (p + i2)->getY() > 0)
			{
				++i2;
			}
			if(i + i2  == limit)
			{
				cout << (p + i2 - 1)->getX() << "]";
			}
			else
			{
				cout << (p + i2)->getX() << ")";
			}
			i = i + i2;
		}
	}

	cout << endl;
}
