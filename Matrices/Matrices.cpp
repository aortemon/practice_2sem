#include <iostream>
using namespace std;

#include "Header.h"

void Matrix::set(int i, double value) {
	this->nums[i] = value;
}

double Matrix::get(int i) {
	return this->nums[i];
}

void Matrix::input() {
	std::cout << "Please, enter the values: \n";
	double tmp;
	for (int i = 0; i < this->size * this->size; i++) {
		std::cin >> tmp;
		this->set(i, tmp);
	}
}

void Matrix::print() {
	for (int i = 0; i < this->size * this->size; i++) {
		if (i > 0 && i % this->size == 0) std::cout << '\n';
		std::cout << this->get(i) << ' ';
	}
	std::cout << '\n';
}

Matrix Matrix::t() {
	Matrix result(this->size);
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			result.set(j * this->size + i, this->get(i * this->size + j));
		}
	}
	return result;
}

Matrix Matrix::operator+(Matrix& m) {
	if (this->size != m.size) return Matrix(1);
	Matrix result(this->size);
	for (int i = 0; i < this->size * this->size; i++) {
		result.set(i, this->get(i) + m.get(i));
	}
	return result;
}

Matrix Matrix::operator*(double k) {
	Matrix result(this->size);
	for (int i = 0; i < this->size * this->size; i++) {
		result.set(i, k * this->get(i));
	}
	return result;
}

Matrix Matrix::operator*(Matrix& m) {
	if (this->size != m.size) return Matrix(1);
	Matrix result(this->size);
	double tmp;
	for (int i = 0; i < this->size * this->size; i++) {
		tmp = 0;
		for (int j = 0; j < this->size; j++) {
			tmp += this->get(i / this->size * this->size + j) * m.get(i % this->size + this->size * j);
		}
		result.set(i, tmp);
	}
	return result;
}

int main() {
	Matrix m(2), n(2);
	std::cout << "Input the first matrix: \n";
	m.input();
	std::cout << "Input the second matrix: \n";
	n.input();
	std::cout << "Amount is: \n";
	(m + n).print();
	std::cout << "Product is: \n";
	(m * n).print();
}