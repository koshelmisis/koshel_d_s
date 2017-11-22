#include <iostream>;
#include <sstream>;
#include "matrix.h"

using namespace std;
int main()
{
	MatrixR m(2, 2);
	m.at(0, 0) = 1;
	m.at(0, 1) = 2;
	m.at(1, 0) = 3;
	m.at(1, 1) = 4;
	cout << m << endl;

	return 0;
}