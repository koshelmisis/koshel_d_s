#indef VECDT_VECDT_H
#define VECDT_VECDT_H
#include <iosfwd>
#include <sstream>
#include <iostream>
using namespace std;
template <typename T>
struct Vec3dt
{
public:
	Vec3dt() = default;// умолчательный конструктор
	Vec3dt(const T a, const T b, const T c);
	Vec3dt(const Vec3dt<T>& v); // копирующий конструктор
	~Vec3dt() = default; //деструктор
	bool operator==(const Vec3dt<T>& rhs);
	bool operator!=(const Vec3dt<T>& rhs) { return !operator==(rhs); }
	Vec3dt<T>& operator+=(const Vec3dt<T>& rhs);
	Vec3dt<T>& operator-=(const Vec3dt<T>& rhs);
	Vec3dt<T>& Multiply(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs);

	std::ostream& writeTo(std::ostream& ostr) const;
	T x{ T() };
	T y{ T() };
	T z{ T() };

};


template <typename T>
Vec3dt<T>::Vec3dt(const T a, const T b, const T c) :x(a), y(b), z(c) {}
template <typename T>
Vec3dt<T>::Vec3dt(const Vec3dt<T>& v) : x(v.x), y(v.y), z(v.z)
{

}
template <typename T>
inline bool Vec3dt<T>:: operator==(const Vec3dt<T>& rhs)
{
	double eps = 1E-10;
	return (std::abs(x - rhs.x) < eps) && (std::abs(y - rhs.y)) && (std::abs(z - rhs.z) < eps);// ???????
}
template <typename T>
Vec3dt<T>& Vec3dt<T>::operator-=(const Vec3dt<T>& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
template <typename T>
Vec3dt<T>& Vec3dt<T>::operator+=(const Vec3dt<T>& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

template <typename T>
Vec3dt<T> operator+(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs)
{
	return Vec3dt<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename T>
Vec3dt<T> operator-(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs)
{
	return Vec3dt<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}


template <typename T>
double Module(const Vec3dt<T>& rhs)//длина вектора
{
	return std::sqrt(lhs.x * rhs.x + lhsy * rhs.y + lhs.z * rhs.z);//????
}

template <typename T>

Vec3dt<T> operator*=(const Vec3dt<T>& v1, const Vec3dt<T>& v2)
{
	return Vec3dt<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);

}
template <typename T>

Vec3dt<T> operator*(const Vec3dt<T>& v1, const Vec3dt<T>& v2)
{
	return Vec3dt<T>(v1.y*v2.z - v1.z*v2.y, v1.z * v2.x - v1.x*v2.z, v1.x * v2.y - v1.y*v2.x);

}

template <typename T>
Vec3dt<T>& Vec3dt<T>::Multiply(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs)//векторное произведение
{
	return Vec3dt<T>(lhs.y*rhs.z - lhs.z*rhs.y; lhs.z*rh.x - lhs.x*rhs.z; lhs.x*rhs.y - lhs.y*rhs.x);//????
}

template <typename T>
std::ostream& operator<<(std::ostream& ostrm, Vec3dt<T>& b)
{
	return b.writeTo(ostrm);
}
template <typename T>
std::ostream&
Vec3dt<T>::writeTo(std::ostream& ostr)
const
{
	ostr << "{" << x << "," << y << "," << z << "}";
	return ostr;
}
#endl