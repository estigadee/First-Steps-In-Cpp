#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int x1, y1, r1;
	cout << "Okryjnost s koordinati: (x1, y1, r1) = ";
	cin >> x1 >> y1 >> r1;

	int x2, y2, r2;
	cout << "Okryjnost s koordinati: (x2, y2, r2) = ";
	cin >> x2 >> y2 >> r2;

	double Distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

	if (Distance == 0 && r1 == r2)
	{
		cout << "okryjnostite syvpadat" << endl;
	}
	else
		if (Distance == r1 + r2 || Distance == abs(r1 - r2))
		{
			cout << "Okryjnostite se dopirat." << endl;
		}
		else
			if (Distance > r1 + r2 || Distance < abs(r1 - r2) || (Distance == 0 && (r1 > r2 || r2 > r1)))
			{
				cout << "Okryjnostite ne se dopirat i ne se presichat." << endl;
			}
			else
			{
				cout << "Okryjnostite se presichat." << endl;
			}


	return 0;
}