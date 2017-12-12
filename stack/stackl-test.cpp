#include "stackl.h"
#include <iostream>

using namespace std;

int main()
{
	StackL s;
	s.push(10);
	s.push(56);
	s.push(74);
	s.push(25);

	cout << "Push:" << endl;
	cout << s << endl;

	s.pop();

	cout << "Pop:" << endl;
	cout << s << endl;

	cout << "IsEmpty: " << s.isEmpty() << endl;

	StackL s2(s);

	cout << "Copy costructor: " << endl;
	cout << s2 << endl;
	s2.top() = 10101;
	cout << "Top: " << endl;
	cout << s2 << endl;

	StackL sEmpty;
	StackL sCopiedFromEmpty(sEmpty);

	cout << "Copy from empty costructor: " << endl;
	cout << sCopiedFromEmpty << endl;

	StackL s3;

	s3.push(1);
	s3.push(2);
	s3.push(-3);


	cout << "Stack s3:" << endl << s3 << endl;

	s2 = s3;

	cout << "s2 = s3:" << endl << s2 << endl;

	StackL s4;

	s4.push(20);
	s4.push(54);
	s4.push(96);

	cout << "Stack s4:" << endl << s4 << endl;

	s3 = s4;

	cout << "s3 = s4:" << endl << s3 << endl;


	return 0;

};