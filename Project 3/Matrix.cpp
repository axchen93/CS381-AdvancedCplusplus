#include<iostream>
#include<cstdlib>
#include<cassert>
#include "SA.cpp"
using namespace std;

template<class T>
class Matrix {
private:
	int x_high;
	int x_low;
	int y_high;
	int y_low;
	SA< SA <T> > * matrix;
public:

	Matrix() {
		x_high = x_low = y_high = y_low = 0;
		matrix = NULL;
	}

	Matrix(int xh, int yh){
		x_low = y_low = 0;
		x_high = xh - 1;
		y_high = yh - 1;
		matrix = new SA< SA<T> >(xh);
		for(int i = 0; i<x_high + 1; i++){
			SA<T> temp(yh);
			(*matrix)[i] = temp;
		}
	}

	Matrix(int xl, int xh, int yl, int yh) {
		x_high = xh;
		x_low = xl;
		y_high = yh;
		y_low = xl;
		matrix = new SA< SA<T> >(x_low, x_high);
		for (int i = x_low; i< x_high + 1; i++) {
			SA<T> temp(y_low, y_high);
			(*matrix)[i] = temp;
		}
	}

	Matrix(Matrix<T>& x) {
		x_high = x.x_high;
		x_low = x.x_low;
		y_high = x.y_high;
		y_low = x.y_low;
		matrix = new SA< SA<T> >(x_low, x_high);
		for (int i = x_low; i< x_high + 1; i++) {
			(*matrix)[i] = x[i];
		}
	}

	~Matrix() {
		delete matrix;
	}

	void setMax() {
		for (int i = x_low; i< x_high + 1; i++) {
			for (int j = y_low; j < y_high+1; j++) {
				(*matrix)[i][j] = INT_MAX;
			}
		}
	}

	SA<T>& operator[](int i) {
		return (*matrix)[i];
	}

	Matrix<T>& operator+(Matrix<T>& x) {
		if (x_high - x_low + 1 != x.x_high - x.x_low + 1 && y_high - y_low + 1 != x.y_high - x.y_low + 1) {
			cout << "different size matricies, cannot add\r\n";
			exit(1);
		}
		Matrix<T> *ans = new Matrix<T>(x);
		int row = x_high - x_low + 1;
		int col = y_high - y_low + 1;

		for (int i = 0; i< row; i++) {
			SA<T> temp = (*matrix)[x_low + i];
			for (int j = 0; j< col; j++) {
				(*ans)[ans->x_low + i][ans->y_low + j] += temp[y_low + j];
			}
		}
		return *ans;
	}

	Matrix<T>& operator*(Matrix<T>& x) {
		if (y_high - y_low + 1 != x.x_high - x.x_low + 1) {
			cout << "Cannot do multiply these 2 matrix!\n";
			exit(1);
		}
		int row = x_high - x_low;
		int col = x.y_high - x.y_low;
		Matrix<T> *ans = new Matrix<T>(0, row, 0, col);

		int size = y_high - y_low + 1;
		for (int i = 0; i<row + 1; i++) {
			for (int j = 0; j<col + 1; j++) {
				(*ans)[i][j] = 0;
				for (int k = 0; k<size; k++) {
					(*ans)[i][j] += (*matrix)[x_low + i][y_low + k] * (*x.matrix)[x.x_low + k][x.y_low + j];
				}
			}
		}

		return *ans;

	}

	void print() {
		for (int i = x_low; i< x_high + 1; i++) {
			SA<T> temp = (*matrix)[i];
			cout << temp << endl;
		}
	}


};