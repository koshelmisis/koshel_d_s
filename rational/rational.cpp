#include <iostream>
#include <sstream>

struct Rational
{
	Rational() {}
	explicit Rational(const int chic);
	Rational(const int chiclit, const int znamen);
	bool operator==(const Rational& rhs) const { return (chic == rhs.chic) && (znam == rhs.znam); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator*(const Rational& rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	int chic{ 0 };
	int znam{ 0 };

	static const char drob{ '/' };

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}



int main()
{
	using namespace std;

	Rational z;
	z += Rational(3, 2);

	Rational b;
	b += Rational(6, 4);
	b = b * z;


	cout << "b = b * z: " << b << endl;

	b = b + z;
	cout << "b + z: " << b << endl;

	b = b - z;
	cout << "b - z: " << b << endl;

	b *= z;
	cout << "b *= z: " << b << endl;


	return 0;
}

Rational::Rational(const int chic)
	: Rational(chic, 0)
{
}

Rational::Rational(const int chiclit, const int znamen)
	: chic(chiclit)
	, znam(znamen)
{
}

Rational& Rational::operator+=(const Rational& rhs)
{
	chic += rhs.chic;
	znam += rhs.znam;
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	chic -= rhs.chic;
	znam -= rhs.znam;
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum;
	sum.chic = lhs.chic*rhs.znam + rhs.chic*lhs.znam;
	sum.znam = lhs.znam*rhs.znam;
	for (int i = 2; i < 6; i++)
	{
		if (i == 4)i++;
		if (sum.chic % i == 0 && sum.znam % i == 0)
		{
			do {
				sum.chic = sum.chic / i;
				sum.znam = sum.znam / i;
			} while (sum.chic % i == 0 && sum.znam % i == 0);
		}
	}
	return sum;
}

Rational& Rational::operator*(const Rational& rhs)
{
	chic = chic*rhs.chic;
	znam = znam*rhs.znam;
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	{
		Rational min;
		min.chic = lhs.chic*rhs.znam - rhs.chic*lhs.znam;
		min.znam = lhs.znam*rhs.znam;
		for (int i = 2; i < 6; i++)
		{
			if (i == 4)i++;
			if (min.chic % i == 0 && min.znam % i == 0)
			{
				do {
					min.chic = min.chic / i;
					min.znam = min.znam / i;
				} while (min.chic % i == 0 && min.znam % i == 0);
			}
		}
		return min;
	}
}

Rational& Rational::operator*=(const int rhs)
{
	chic *= rhs;
	znam *= rhs;
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	chic *= rhs.chic;
	znam *= rhs.znam;
	return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << chic << drob << znam;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char Drob(0);
	int chiclit(0);
	int znamen(0);
	istrm >> chiclit >> Drob >> znamen;
	if (istrm.good())                                 
	{
		if (Rational::drob == Drob)
		{
			chic = chiclit;
			znam = znamen;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);    
		}
	}
	return istrm;
}