#pragma once

class Integer {
public: 
	unsigned get_number_of_digits();
	unsigned get_reversed_num();
	unsigned get_value();
	bool get_prime();
	bool get_perfect();
	bool is_symmetric();
	unsigned count_of_dels();
	Integer(unsigned N) {
		this->n = N;
		this->num_of_digits = this->count_digits();
		this->reversed = reverse_num();
		this->prime = this->is_prime();
		this->perfect = this->is_perfect();
	}
	~Integer() {};
private:
	unsigned n;
	bool prime;
	bool perfect;
	unsigned num_of_digits;
	unsigned count_digits();
	unsigned reverse_num();
	bool is_prime();
	bool is_perfect();
	unsigned reversed;
};

unsigned Integer::count_of_dels() {
	int c = 0;
	for (int i = 1; i < this->n; i++) {
		if (this->n % i == 0) c++;
	}
	return c;
}

unsigned Integer::get_value() {
	return this->n;
}

bool Integer::get_prime() {
	return this->prime;
}

unsigned Integer::get_number_of_digits() {
	return this->num_of_digits;
}

unsigned Integer::get_reversed_num() {
	return this->reversed;
}

unsigned Integer::count_digits() {
	int m = this->n;
	int k = 1;
	while (m / 10 > 0) {
		k++;
		m /= 10;
	}
	return k;
}

unsigned Integer::reverse_num() {
	int num = this->n;
	int rev = 0; 
	for (int i = 0; i < this->num_of_digits; i++) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return rev;
}

bool Integer::is_symmetric() {
	return (this->n) == (this->reversed);
}

bool Integer::is_prime() {
	int m = this->get_value();
	for (int i = 2; i < int(sqrt(this->get_value())) + 1; i++) {
		if (m % i == 0) {
			return false;
		}
	}
	return true;
}

bool Integer::is_perfect() {
	int sum = 0;
	unsigned m = this->get_value();
	for (int denom = 1; denom <= m / 2 + 1; denom++) {
		if (m % denom == 0) sum += denom;
	}
	if (m == sum) return true;
	return false;
}

bool Integer::get_perfect() {
	return this->perfect;
}




class Set {
public:
	Set(unsigned N) {
		size = N;
		arr = new unsigned[size];
	};
	~Set() {};
	void init();
	void add(unsigned n);
	void print();
	float a_average();
	float h_average();
private:
	unsigned size;
	unsigned cur = 0;
	unsigned* arr;
};


void Set::add(unsigned n) {
	if (cur < this->size - 1) {
		this->arr[cur] = n;
		cur++;
	}
};



void Set::print() {
	for (int i = 0; i < this->size; i++) {
		std::cout << " " << this->arr[i] << " ";
	}
}

bool is_perfect(unsigned m) {
	int sum = 0;
	for (int denom = 1; denom <= m / 2 + 1; denom++) {
		if (m % denom == 0) sum += denom;
	}
	if (m == sum) return true;
	return false;
}

bool is_prime(unsigned m) {
	for (int i = 2; i < int(sqrt(m)) + 1; i++) {
		if (m % i == 0) {
			return false;
		}
	}
	return true;
}

float Set::a_average() {
	unsigned sum = 0, k = 0;
	for (int i = 0; i < this->size; i++) {
		if (is_perfect(this->arr[i])) {
			k++;
			sum += this->arr[i];
		}
	}
	return sum / k;
}

float Set::h_average() {
	unsigned sum = 0, k = 0;
	for (int i = 0; i < this->size; i++) {
		if (is_prime(this->arr[i])) {
			k++;
			sum += this->arr[i] * this->arr[i];
		}
	}
	return sum / k;
}