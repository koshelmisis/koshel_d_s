#include <iostream>
#include "array.h"

int main()
{
	using namespace std;
	Array mass = Array(3);
	mass.add(1);
	mass.add(2);
	mass.add(3);
	Array mass2(mass);

	cout << "mass" << mass << endl;
	cout << "mass2" << mass2 << endl;


	return 0;
}

