#pragma once

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include<iostream>

class Array
{
public:
	Array() = default; //дефолтный конструктор

	Array(const ptrdiff_t & s) //конструктор

	{
		pdata = new int[s];
		size_ = s;
	}

	Array(const Array & rhs) //конструктор копирования

	{
		pdata = new int[rhs.size_];
		for (int i = 0; i < rhs.length_; i++)
		{
			pdata[i] = rhs[i];
		}
		size_ = rhs.size_;
		length_ = rhs.length_;
	}

	Array::~Array()
	{
		delete[] pdata;
		pdata = nullptr;
		size_ = 0;
		length_ = 0;
	}

	Array& operator=(const Array& a);

	int& operator[](const ptrdiff_t index);
	const int& operator[](const ptrdiff_t index) const;

	ptrdiff_t size() const { return size_; }
	ptrdiff_t length() const { return length_; }

	void resize(const int& a);
	void add(const int& a);
	void addbegin(const int& a);
	void addindex(const int& a, int index);
	void remove(const int& removableElementIndex);
	void sort();

	std::ostream& writeTo(std::ostream& ostr);

private:
	static const char leftbrace{ '[' };
	static const char rightbrace{ ']' };

	ptrdiff_t size_{ 0 };
	ptrdiff_t length_{ 0 };
	int* pdata{ nullptr };
};

inline std::ostream& operator << (std::ostream& ostrm, Array& b)
{
	return b.writeTo(ostrm);
}

#endif //ARRAY_ARRAY_H