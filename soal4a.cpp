#include <iostream>
#include <string>

bool dfsmDivisibleBy3EvenOnes(const std::string &input) {
	std::string state = "q0"; // State awal: jumlah 0 habis dibagi 3 dan jumlah 1 genap
	
	for (char ch : input) {
		if (ch == '0') {
			// Transisi state berdasarkan jumlah 0 habis dibagi 3
			if (state == "q0") state = "q1";
			else if (state == "q1") state = "q2";
			else if (state == "q2") state = "q0";
			else if (state == "q3") state = "q4";
			else if (state == "q4") state = "q5";
			else if (state == "q5") state = "q3";
		} else if (ch == '1') {
			// Transisi state berdasarkan jumlah 1 genap atau ganjil
			if (state == "q0") state = "q3";
			else if (state == "q1") state = "q4";
			else if (state == "q2") state = "q5";
			else if (state == "q3") state = "q0";
			else if (state == "q4") state = "q1";
			else if (state == "q5") state = "q2";
		} else {
			return false; // hanya menerima 0 dan 1
		}
		std::cout << "Input: " << ch << ", Pergi ke state: " << state << "\n";
	}
	
	return state == "q0"; // State final: jumlah 0 habis dibagi 3 dan jumlah 1 genap
}

int main() {
	std::string input;
	std::cout << "Masukkan string (hanya 0 dan 1): ";
	std::cin >> input;
	
	if (dfsmDivisibleBy3EvenOnes(input)) {
		std::cout << "String diterima.\n";
	} else {
		std::cout << "String ditolak.\n";
	}
	
	return 0;
}

