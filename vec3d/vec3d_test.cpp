#include <iostream>
#include <sstream>
#include "vec3d.h"

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Vector z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error : " << str << " -> " << z << endl;

	}
	return istrm.good();
}


int main()
{
	using namespace std;
	Vector a;
	Vector b(0.1, 0.2, 2.5);
	Vector c(b);
	Vector d(2, 3, 4);

	cout << "b" << b << endl;
	cout << "c" << c << endl;
	cout << "d" << d << endl;

	c = b*d;
	cout << "d*b" << c << endl;

	c = b *= d;
	cout << "d*=b" << c << endl;

	b * 2;
	cout << "b*2" << b * 2 << endl;

	b / 2;
	cout << "b/2" << b / 2 << endl;

	return 0;
}

std::ostream& Vector::writeTo(std::ostream& ostrm) const
{

	ostrm << leftBrace << x << separator << y << separator << z << rightBrace;	return ostrm;
}

std::istream& Vector::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double X(0.0);
	char comma(0);
	double Y(0.0);
	double Z(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> X >> comma >> Y >> comma >> Z >> rightBrace;
	if (istrm.good())
	{
		if ((Vector::leftBrace == leftBrace) && (Vector::separator == comma)
			&& (Vector::rightBrace == rightBrace))
		{
			x = X;
			y = Y;
			z = Z;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}