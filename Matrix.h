#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Car.h"

class Matrix{
private:
        int m_rows;
        int m_columns;
        Car** m_matrix;
public:
	Matrix(int rows,int columns);
	Matrix();
	Matrix(const Matrix& other);
	Matrix& operator =(const Matrix& other);
	~Matrix();
	int getRows();
	int getColumns();
	
private:
	void allocateMemory();
	void rotateAboutDiagonal();
	void rotateAboutMid();
	
public:
	void init();
	void rotate();
	void print();
	void set(int row,int col,const Car& car);
	Car& get(int row,int col);
	friend  std::ostream& operator <<(std::ostream& os,const Matrix& matrix);
	Car* operator[](int row);
};

#endif //MATRIX_H