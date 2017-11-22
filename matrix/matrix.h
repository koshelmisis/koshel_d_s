#ifndef MATRIX
#define MATRIX
#include <iosfwd>
using namespace std;

class MatrixR
{
public:
	MatrixR();
	MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol);
	MatrixR(const MatrixR& rhs);
	~MatrixR();
	int& at(const ptrdiff_t nRow, const ptrdiff_t nCol);
	const int& at(const ptrdiff_t nRow, ptrdiff_t nCol) const;
	MatrixR& operator=(const MatrixR& matr);
	void copy(const MatrixR& a, MatrixR& b);
	int Rows() const;
	int length() const;
	int Cols() const;
	ostream& writeTo(std::ostream& ostrm) const;
	
private:
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int* pData{ nullptr };

};
inline std::ostream& operator<<(std::ostream& ostrm, const MatrixR& rhs)
{
	return rhs.writeTo(ostrm);
}
#endif
