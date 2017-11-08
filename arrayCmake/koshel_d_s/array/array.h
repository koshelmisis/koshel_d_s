#pragma once

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include<iostream>

class Array
{
public:
	Array() = default; //дефолтный конструктор

	Array(const ptrdiff_t & size_) //конструктор

	{
		pdata = new int[size_];
		size = size_;
	}

	Array(const Array & rhs) //конструктор копирования

	{
		pdata = new int[rhs.size];
		for (ptrdiff_t i(0); i < rhs.length; i++)
		{
			pdata[i] = rhs[i];
		}
		size = rhs.size;
		length = rhs.length;
	}

	Array::~Array()
	{
		delete[] pdata;
		pdata = nullptr;
		size = 0;
		length = 0;
	}

	Array& operator=(const Array& a);

	int& operator[](const ptrdiff_t index);
	const int& operator[](const ptrdiff_t index) const;

	ptrdiff_t Size() const { return size; }
	ptrdiff_t Length() const { return length; }

	void Resize(const int& a);
	void Add(const int& a);

	std::ostream& writeTo(std::ostream& ostr);
	std::istream& readFrom(std::istream& istrm);

private:
	ptrdiff_t size{ 0 };
	ptrdiff_t length{ 0 };
	int* pdata{ nullptr };
};

inline std::ostream& operator«(std::ostream& ostrm, Array& b)
{
	return b.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Array& rhs)
{
	return rhs.readFrom(istrm);
}
#endif //ARRAY_ARRAY_H