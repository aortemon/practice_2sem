#pragma once

class Matrix {
private:
	int size;
	double* nums;
public:
	Matrix(int size) {
		this->size = size;
		this->nums = new double[this->size * this->size + 1];
	};
	void input();
	void print();
	void set(int, double);
	double get(int);
	Matrix t();
	Matrix operator+(Matrix& m);
	Matrix operator*(double k);
	Matrix operator*(Matrix& m);
};