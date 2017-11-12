#include"rect2d.h"

#include<iostream>
#include<sstream>



 Rect2d operator+(const Rect2d& r1, const Rect2d& r2)
{
	Rect2d r3;
	if (r1.x2 > r2.x2) r3.x2 = r1.x2; else r3.x2 = r2.x2;
	if (r1.y1 < r2.y1) r3.y1 = r1.y1; else r3.y1 = r2.y1;
	if (r1.y2 > r2.y2) r3.y2 = r1.y2; else r3.y2 = r2.y2;	
	if (r1.x1 < r2.x1) r3.x1 = r1.x1; else r3.x1 = r2.x1;

	return r3;
}
 Rect2d operator-(const Rect2d& r1, const Rect2d& r2)
 {
	 Rect2d r3;
	 if (r1.x2 >= r2.x1  &&  r1.y2 >= r2.y1)
	 {
		 if (r2.x2 > r1.x1) r3.x1 = r2.x2; else r3.x1 = r1.x1;
		 if (r2.x2 > r1.x1) r3.x1 = r2.x2; else r3.x1 = r1.x1;
		 //???
	 }

	 return r3;
 }

 ostream& Rect2d::writeTo(std::ostream& ostrm) const
 {
	 ostrm <<s1<< sc1<< x1 << separator<< y1 <<sc2<<separator<<sc1<< x2 <<separator<< y2<<sc2<<s2;
	 return ostrm;
 }

 ostream& operator<<(std::ostream& ostrm, const Rect2d& rhs)
 {
	 return rhs.writeTo(ostrm);
 }


