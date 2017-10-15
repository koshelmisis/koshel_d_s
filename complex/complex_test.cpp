#include <sstream>
#include <iostream>
#include "complex.h"


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
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

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");

	Complex b;
	b += Complex(7, 1);
	b = b * z;

	cout << "b = b * z: " << b << endl;

	b -= z;
	cout << "b -= z: " << b << endl;

	b *= z;
	cout << "b *= z: " << b << endl;


	return 0;
}


std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good())                                 // ?????
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaganary;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);    // ?????
		}
	}
	return istrm;
}