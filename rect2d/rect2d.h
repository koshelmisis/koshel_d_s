#ifndef RECT
#define RECT
#include <iosfwd>
using namespace std;

struct Rect2d
{
public:
	Rect2d() = default;
	~Rect2d() = default;
	Rect2d(const Rect2d& v) = default;
	Rect2d(const double X1, const double Y1, const double X2, const double Y2) : x1(X1), y1(Y1), x2(X2), y2(Y2)
	{}
	bool operator == (const Rect2d& v) const { return (x1 == v.x1) && (x2 == v.x2) && (y1 == v.y1) && (y2 == v.y2); };
	bool operator!=(const Rect2d& r1) { return !operator==(r1); }
	ostream& writeTo(std::ostream& ostrm) const;

public:
	double x1{ 0.0 };
	double y1{ 0.0 };
	double x2{ 0.0 };
	double y2{ 0.0 };
	static const char s1{ '{' };
	static const char s2{ '}' };
	static const char sc1{ '(' };
	static const char sc2{ ')' };
	static const char separator{ ',' };


};
Rect2d operator+(const Rect2d& r1, const Rect2d& r2); //сложение прямоугольников
Rect2d operator-(const Rect2d& r1, const Rect2d& r2); //вычитание прямоугольников

ostream& operator<<(std::ostream& ostrm, const Rect2d& rhs);
#endif

 
