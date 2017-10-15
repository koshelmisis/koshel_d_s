#include <iostream>
#include <sstream>
#include "rational.h"

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
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
	Rational z;
	z += Rational(2);

	cout << z << endl;
	return 0;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << chis << drob << znam;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char drob(0);
	int chislit(0);
	int znamenat(0);
	istrm >> chislit >> drob >> znamenat;
	if (istrm.good())                                 // ?????
	{
		if (Rational::drob == drob)
		{
			chis = chislit;
			znam = znamenat;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);    // ?????
		}
	}
	return istrm;
}

