#pragma once

class MyInt {
public:
	MyInt() {
		this->n = 0;
	}
	MyInt(unsigned N) {
		this->n = N;
	}
	~MyInt() {};
	unsigned get_n();
	unsigned number_of_digits();
	bool is_prime();
	bool is_perfect();
	bool is_symmetric();
	unsigned reversed();
	unsigned number_of_denoms();
private:
	unsigned n;
};

class Sequence {
public:
	Sequence(unsigned size) {
		this->n = size;
		this->seq = new MyInt[size];
	};
	~Sequence() {};
	void add(unsigned);
	void print();
	double arithmetic_mean();
	double harmonic_mean();

private:
	unsigned n;
	unsigned pos = 0;
	MyInt* seq;
};

