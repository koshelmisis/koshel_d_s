#ifndef RATIONAL_1110
#define RATIONAL_1110

#include <iosfwd>

struct Rational
{

	Rational() {}
	explicit Rational(const int chis);
	Rational(const int chis, const int znam);
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }


	int chis;
	int znam;
	static const char drob{ '/' };

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

};
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}
#endif