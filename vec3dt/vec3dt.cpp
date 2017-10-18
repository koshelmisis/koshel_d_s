#include "vec3dt.h"
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
	Vec3dt<double> vec1;
	cout << "empty constructor" << vec1 << endl;
	Vec3dt<double> vec2(2.0, 3.0, 4.0);
	cout << "constructor with 3 param" << vec2 << endl;
	Vec3dt<double> vec3(vec2);
	cout << "copying constructor" << vec3 << endl;
	Vec3dt<double> vec4(3.0, 4.0, 5.0);
	Vec3dt<double> vec5(vec4*vec3);
	cout << "*" << vec5 << endl;
	Vec3dt<double> vec6(4.0, 5.0, 6.0);
	Vec3dt<double> vec7(vec6 *= vec3);
	cout << "*=" << vec7 << endl;
	Vec3dt<double> vec8(5.0, 6.0, 7.0);
	Vec3dt<double> vec9(vec4 + vec3);
	cout << "+" << vec9 << endl;
	Vec3dt<double> vec10(5.0, 6.0, 7.0);
	Vec3dt<double> vec11(vec4 - vec3);
	cout << "-" << vec11 << endl;
	Vec3dt<double> vec12(5.0, 6.0, 7.0);
	Vec3dt<double> vec13(vec4 += vec3);
	cout << "+=" << vec13 << endl;
	Vec3dt<double> vec14(5.0, 6.0, 7.0);
	Vec3dt<double> vec15(vec4 -= vec3);
	cout << "-=" << vec15 << endl;
	return 0;
};
