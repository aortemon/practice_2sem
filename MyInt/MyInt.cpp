#include <iostream>
using namespace std;
#include "Header.h"

unsigned MyInt::get_n() {
	return this->n;
}

unsigned MyInt::number_of_digits() {
	short k = 0;
	unsigned m = this->n;
	while (m > 0) {
		k++;
		m /= 10;
	}
	return k;
}

bool MyInt::is_prime() {
	unsigned m = this->n;
	if (m <= 2) return false;
	for (int i = 2; i <= sqrt(n) + 1; i++)
		if (m % i == 0) return false;
	return true;
}
bool MyInt::is_perfect() {
	unsigned m = this->n;
	unsigned amount = 0;
	for (int i = 1; i < m / 2 + 1; i++) {
		if (m % i == 0) amount += i;
	}
	return amount == m;
}
bool MyInt::is_symmetric() {
	return this->reversed() == this->n;
}


unsigned MyInt::reversed() {
	unsigned reversed = 0, m = this->n;
	for (int i = 0; i < this->number_of_digits(); i++) {
		reversed = reversed * 10 + m % 10;
		m /= 10;
	}
	return reversed;
}
unsigned MyInt::number_of_denoms() {
	unsigned k = 0, m = this->n;
	for (int i = 1; i < m / 2 + 1; i++) {
		if (m % i == 0) k++;
	}
	return k;
}

void Sequence::add(unsigned value) {
	if (pos < this->n) {
		this->seq[this->pos] = MyInt(value);
		this->pos++;
	}
}

void Sequence::print() {
	for (int i = 0; i < this->n; i++) {
		std::cout << this->seq[i].get_n()<< " ";
	}
}

double Sequence::arithmetic_mean() {
	double amount = 0;
	unsigned k = 0;
	for (int i = 0; i < this->n; i++) {
		if (this->seq[i].is_perfect()) {
			k++;
			amount += this->seq[i].get_n();
		}
	}
	if (k == 0) return 0;
	return amount / k;
}

double Sequence::harmonic_mean() {
	double amount = 0;
	unsigned k = 0;
	for (int i = 0; i < this->n; i++) {
		if (this->seq[i].is_prime()) {
			k++;
			amount += 1.0 / this->seq[i].get_n();
		}
	}
	if (k == 0) return 0;
	std::cout <<'\n'<< amount << " " << k << '\n';
	return k / amount;
}

int main() {
	MyInt num(6);

	std::cout << "Number: " << num.get_n() << ";\n";
	std::cout << "Number of digits: " << num.number_of_digits() << "; \n";
	std::cout << "Is prime: " << num.is_prime() << "; \n";
	std::cout << "Is perfect: " << num.is_perfect() << "; \n";
	std::cout << "Reversed: " << num.reversed() << "; \n";
	std::cout << "Is symmetric: " << num.is_symmetric() << "; \n";
	std::cout << "Number of denoms: " << num.number_of_denoms() << "; \n\n";

	unsigned size = 5, tmp;
	Sequence seq(size);
	std::cout << "Input: ";
	for (int i = 0; i < size; i++){
		std::cin >> tmp;
		seq.add(tmp);
	}
	std::cout << "\nOutput: ";
	seq.print();
	std::cout << "\nArithmetic mean of perfect nums: " << seq.arithmetic_mean();
	std::cout << "\nHarmonic mean of prime nums: " << seq.harmonic_mean() << "\n";


	int d = 496;
	int s = 0;
	for (int i = 1; i < d / 2 + 1; i++) {
		if (d % i == 0) {
			s += i;
			std::cout << i << "\t" << s << "\n";
		}
	}
	
}