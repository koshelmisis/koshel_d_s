#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include <iosfwd>

class Priorityqueue
{
public:
	Priorityqueue() = default;
	~Priorityqueue();
	Priorityqueue(const Priorityqueue& rhs);
	Priorityqueue& operator=(const Priorityqueue& rhs);
	void push(const int& v);
	void pop();
	int& bot();
	const int& bot() const;
	bool isEmpty() const;
	std::ostream& writeTo(std::ostream& ostr) const;
private:
	struct Node
	{
		Node(Node* pNext, const int& v);
		~Node() = default;
		Node* pNext_{ nullptr };
		int pData_{ int(0) };
	};
	Node* pHead_{ nullptr };
	Node* pTail_{ nullptr };
};
std::ostream& operator<<(std::ostream& ostrm, const Priorityqueue& rhs);
#endif