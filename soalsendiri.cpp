#include <iostream>
#include <string>

bool dfsmStartsWithAbEndsWithBa(const std::string &input) {
	std::string state = "q0"; // State awal
	
	for (char ch : input) {
		if (state == "q0") {
			if (ch == 'a') state = "q1"; 
			else state = "q4"; 
		} else if (state == "q1") {
			if (ch == 'b') state = "q2"; 
			else state = "q4";
		} else if (state == "q2") {
			if (ch == 'b') state = "q2"; 
			else state = "q3";
		} else if (state == "q3") {
			if (ch == 'a') state = "q5"; 
			else state = "q2";
		} else if (state == "q4") {
			if (ch == 'a') state = "q4"; 
			else state = "q4";
		}else if (state == "q5") {
			if (ch == 'a') state = "q5"; 
			else state = "q2";
		}
		
		std::cout << "Input: " << ch << ", Pergi ke state: " << state << "\n";
	}
	
	return state == "q3"; // State final adalah q3 yang mencocokkan awalan "ab" dan akhiran "ba"
}

int main() {
	std::string input;
	std::cout << "Masukkan string: ";
	std::cin >> input;
	
	if (!input.empty() && dfsmStartsWithAbEndsWithBa(input)) {
		std::cout << "String diterima.\n";
	} else {
		std::cout << "String ditolak.\n";
	}
	
	return 0;
}

