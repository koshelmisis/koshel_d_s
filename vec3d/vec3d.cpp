
#include <iostream>
#include "vec3d.h"



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
	return Vector(v1.y*v2.z - v1.z*v2.y, v1.z * v2.x - v1.x*v2.z, v1.x * v2.y - v1.y*v2.x);

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
