#ifndef VEC3D_1110
#define VEC3D_1110

#include <iosfwd>

struct Vector
{
public:
	Vector() = default;
	Vector(const double xv, const double yv, const double zv)
		:x(xv), y(yv), z(zv)
	{
	}

	Vector(const Vector& v)
		: x{ v.x }
		, y{ v.y }
		, z{ v.z }
	{
	}

	Vector& operator = (const Vector v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	bool operator == (const Vector& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
	bool operator != (const Vector& v) const { return !operator==(v); }
	Vector& operator * (const double c);
	Vector& operator / (const double c);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);


public:
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };


	static const char leftBrace{ '(' };
	static const char separator{ ';' };
	static const char rightBrace{ ')' };


};
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator*=(const Vector& v1, const Vector& v2); // скалярное произведение
Vector operator*(const Vector& v1, const Vector& v2); // векторное произведение
inline std::ostream& operator<<(std::ostream& ostrm, const Vector& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vector& rhs)
{
	return rhs.readFrom(istrm);
}

#endif