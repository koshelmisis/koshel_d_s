#include "array.h"
#include <iostream>

std::ostream & Array::writeTo(std::ostream& ostrm)
{
	for (ptrdiff_t i(0); i < length_+1; i++)
		ostrm << leftbrace << i << rightbrace << " ";
	return ostrm;

}

int& Array:: operator[](const ptrdiff_t index)
{
	return pdata[index];
}
const int& Array:: operator[](const ptrdiff_t index) const
{
	return pdata[index];
}

	void Array::resize(const int & a)
	{
		if (length_ < a) {
			int *newarr = new int[a];
			for (ptrdiff_t i(0); i < length_; i++) {
				newarr[i] = pdata[i];
			}
			delete[] pdata;
			pdata = newarr;
			size_ = a;
		}
		else {
			int *newarr = new int[a];
			for (ptrdiff_t i(0); i < a; i++) {
				newarr[i] = pdata[i];
			}
			delete[] pdata;
			pdata = newarr;
			size_ = a;
			length_ = a;
		}
	}

	void Array::add(const int & a)
	{
		if (length_ < size_) {
			pdata[length_] = a;
			length_++;
		}
		else {
			resize(size_ * 2);
			pdata[length_] = a;
			length_++;
		
		}
	}
	void Array::addbegin(const int & a)
	{
		resize(size_ * 2);
		for (int i = length_; i > 1; i--)
		{
			pdata[i] = pdata[i - 1];
		}
		pdata[0] = a;
	
	}
	void Array::addindex(const int& a, int index)
	{
		resize(size_ * 2);
		for (int i = length_; i > index+1; i--)
		{
			pdata[i] = pdata[i - 1];
		}
		pdata[index] = a;
		for (int i = index-1; i > 1; i--)
		{
			pdata[i] = pdata[i - 1];
		}
	}
	void Array::remove(const int& index)
	{
		for (int i = index; i <length_-2; i++)
		{
			pdata[i] = pdata[i + 1];
		}
	}
	void Array::sort()
	{
		int k = 0;
		int kmax = pdata[0];

		for (int i = 0; i < length_ - 1; i++)
		{
			if (pdata[i + 1] < pdata[i])
				k++;
			else
			{
				if (k > kmax)
					kmax = k;
				k = 1;
			}
			if (k > kmax)
				kmax = k;
		}
	}
