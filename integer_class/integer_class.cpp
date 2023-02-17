#include <iostream>
using namespace std;
#include "Header.h"



int main() {

	/*Integer num(12);
	std::cout << "Num:            " << num.get_value() << ";\n";
	std::cout << "Num of digits:  " << num.get_number_of_digits() << ";\n";
	std::cout << "Reversed:       " << num.get_reversed_num() << ";\n";
	std::cout << "Palindrome:     " << num.is_symmetric() << ";\n";
	std::cout << "Prime:          " << num.get_prime() << ";\n";
	std::cout << "Perfect:        " << num.get_perfect() << ";\n";
	std::cout << "Number of dels: " << num.count_of_dels() << ";\n";*/

	Set arr(3);
	arr.add(6);
	arr.add(7);
	arr.add(8);
	arr.print();
	std::cout << "Average of perfect subset: " << arr.a_average() << "\n";
	std::cout << "Average of prime subset: " << arr.h_average();
}