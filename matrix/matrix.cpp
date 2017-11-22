#include "matrix.h"
#include <iostream>
using namespace std;


MatrixR::MatrixR(const int nRow, const int  nCol)
	:nRow_(nRow), nCol_(nCol)
{
	if (nRow <= 0 & nCol <= 0)
		throw std::invalid_argument("Arguments must be positive numbers");

	pData = new int[nRow*nCol]{ 0 };
}

MatrixR::MatrixR(const MatrixR & a)
{
	nCol_ = a.nCol_;
	nRow_ = a.nRow_;
	copy(a, *this);
}

MatrixR::~MatrixR()
{
	delete[] pData;
	pData = nullptr;
	nRow_ = 0;
	nCol_ = 0;
}

int & MatrixR::at(const ptrdiff_t nRow, const ptrdiff_t nCol)
{
	if ((nRow < 0 & nCol < 0) || (nRow >= nRow_ & nCol >= nCol_))
		throw std::invalid_argument("Index is out of range");
	return pData[nCol_*nRow + nCol];
}

const int & MatrixR::at(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	if ((nRow < 0 & nCol < 0) || (nRow >= nRow_ & nCol >= nCol_))
		throw std::invalid_argument("Index is out of range");
	return pData[nCol_*nRow + nCol];
}

int MatrixR::Rows() const
{
	return nRow_;
}

int MatrixR::Cols() const
{
	return nCol_;
}

std::ostream & MatrixR::writeTo(std::ostream & ostrm) const
{

	for (int nRow(0); nRow < nRow_; nRow += 1)
	{
		for (int nCol(0); nCol < nCol_; nCol = nCol + 1)
		{
			ostrm << "[" << nRow << ", " << nCol << "] = " << pData[(nCol_*nRow) + nCol] << "   ";
		}
		ostrm << "\n";
	}

	return ostrm;
}
int MatrixR::length() const
{
	return nRow_*nCol_;
}


void MatrixR::copy(const MatrixR & a, MatrixR& b)
{
	b.pData = new int[a.length()];
	for (int i(0); i < b.length(); i++) {
		b.pData[i] = a.pData[i];
	}
}

