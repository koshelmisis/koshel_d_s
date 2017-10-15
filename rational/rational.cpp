#include <iostream>
#include "rational.h"



Rational::Rational(const int chis) : Rational(chis, 1)
{
}
Rational::Rational(const int chislit, const int znamen) : chis(chislit), znam(znamen)
{
	if (0 == znam) {}
}
Rational& Rational:: operator+=(const Rational& rhs)
{
	chis += rhs.chis;
	znam += rhs.znam;
	return *this;
}
