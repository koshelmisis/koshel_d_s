#include "priorityqueue.h"
#include <iostream>
#include <sstream>

Priorityqueue::Node::Node(Node* pNext, const int& pData) : pNext_(pNext), pData_(pData)
{
}

bool Priorityqueue::isEmpty() const
{
	return (pTail_ == nullptr);
}

Priorityqueue::Priorityqueue(const Priorityqueue& rhs)
{
	Node* copyFrom(rhs.pTail_);
	while (copyFrom != nullptr)
	{
		push(copyFrom->pData_);
		copyFrom = copyFrom->pNext_;
	}
}
Priorityqueue& Priorityqueue::operator=(const Priorityqueue& rhs)
{
	Node* copyFrom(rhs.pTail_);
	Node* copyTo(pTail_);
	
	while ((copyTo != pHead_) && (copyFrom != rhs.pHead_))
	{
		copyTo->pData_ = copyFrom->pData_;
		copyTo = copyTo->pNext_;
		copyFrom = copyFrom->pNext_;
	}

	if ((copyTo != pHead_) && (copyFrom != rhs.pHead_))
	{
		copyTo->pData_ = copyFrom->pData_;
	}

	else
	{
		if ((copyTo == pHead_) && (copyFrom != rhs.pHead_))
		{
			copyTo->pData_ = copyFrom->pData_;

			while (copyFrom != nullptr)
			{
				push(copyFrom->pData_);
				copyFrom = copyFrom->pNext_;
			}
		}

		else
		{
			copyTo->pData_ = copyFrom->pData_;
			pHead_ = copyTo;
			pHead_->pNext_ = nullptr;
			copyTo = copyTo->pNext_;
			Node* pDelete(copyTo);

			while (copyTo != nullptr)
			{
				copyTo = copyTo->pNext_;
				delete pDelete;
				pDelete = copyTo;
			}
		}
	}
	return *this;
}

Priorityqueue::~Priorityqueue()

{
	while (!isEmpty())
	{
		pop();
	}
}

void Priorityqueue::push(const int& v)
{

	if (isEmpty())
	{
		pHead_ = new Node(nullptr, v);
		pTail_ = pHead_;
	}

	else
	{
		pHead_->pNext_ = new Node(nullptr, v);
		pHead_ = pHead_->pNext_;
	}
}

void Priorityqueue::pop()
{
	if (!isEmpty())
	{
		Node* pDelete(pTail_);
		pTail_ = pTail_->pNext_;
		delete pDelete;
	}
}


int& Priorityqueue::bot()

{
	if (isEmpty()) 
	{
		throw std::invalid_argument("Error");
	}
	return pTail_->pData_;
}

const int& Priorityqueue::bot() const
{
	if (isEmpty()) 
	{
		throw std::invalid_argument("Error");
	}
	return pTail_->pData_;
}

std::ostream& Priorityqueue::writeTo(std::ostream& ostrm) const

{
	if (!isEmpty())
	{
		Priorityqueue write(*this);

		while (!write.isEmpty())
		{
			ostrm << write.bot() << std::endl;
			write.pop();
		}
	}

	else
	{
		ostrm << "is Empty";
	}

	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Priorityqueue& rhs)
{
	return rhs.writeTo(ostrm);
}

