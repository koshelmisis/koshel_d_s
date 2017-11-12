
#include"rect2d.h"

#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	Rect2d r1;
	Rect2d r2(1.0, 2.0, 3.0, 4.0);
	Rect2d r3(2.0, 3.0, 4.0, 5.0);
	Rect2d r4(r2);
	cout << r4 << endl;
	Rect2d r5(r2+r3);
	cout << r5 << endl;



	return 0;
};