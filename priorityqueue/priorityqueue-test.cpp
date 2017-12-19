#include "priorityqueue.h"
#include <iostream>

using namespace std;

int main()
{
	Priorityqueue p1;
	cout << p1 << endl;
	p1.push(15);
	p1.push(-8);
	cout << "Queue 15, -8:" << endl << p1 << endl;
	p1.pop();
	cout << "pop:" << endl << p1 << endl;
	Priorityqueue p2(p1);
	cout << "p2(p1):" << endl << p2 << endl;
	p2.push(96);
	p2.push(100);
	p2.push(155);
	cout << "p2:" << endl << p2 << endl;
	p1 = p2;
	cout << "p1 = p2:" << endl << p1 << endl;
	Priorityqueue p3;
	p3.push(78);
	p3.push(95);
	p3.push(15);
	cout << "p3:" << endl << p3 << endl;
	p3 = p3;	
	cout << "p3 = p3:" << endl << p3 << endl;
	p3.push(852);
	p3.push(963);
	p3.push(20);
	cout << "p3:" << endl << p3 << endl;
	p2 = p3;
	cout << "p2 = p3:" << endl << p2 << endl;
	return 0;

}