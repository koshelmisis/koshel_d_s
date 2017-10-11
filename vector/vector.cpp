
#include <iostream>
#include <sstream>

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


};
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator*=(const Vector& v1, const Vector& v2); // скалярное произведение
Vector operator*(const Vector& v1, const Vector& v2); // векторное произведение


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
	Vector b(0.0, 0.2, 2.3);
	Vector c(b);

	cout << "b" << b << endl;

	return 0;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);

}
Vector operator-(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);

}
Vector operator*=(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);

}
Vector operator*(const Vector& v1, const Vector& v2)
{
	return Vector(v1.y*v2.z - v1.z*v2.y, v1.z * v2.x-v1.x*v2.z, v1.x * v2.y-v1.y*v2.x);

}
Vector& Vector::operator *(const double c)
{
	x = x*c;
	y = y*c;
	z = z*c;
	return *this;
}
Vector& Vector::operator /(const double c)
{
	x = x / c;
	y = y / c;
	z = z / c;
	return *this;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Vector& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vector& rhs)
{
	return rhs.readFrom(istrm);
}