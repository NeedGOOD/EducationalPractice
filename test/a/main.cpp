#include <iostream>
#include <string>

int main(int argc, char** argv) {
	int menu, x;
	std::string word1, word2;
	std::cout << "Enter first word: ";
	std::cin >> word1;
	std::cout << "Enter second word: ";
	std::cin >> word2;
	std::cout << "\nSelect a function\n1. Size words;\n2. Connect words;\n3. Replace the first word with the second;\n4. Swap place;\n5. Compare two words.\nEnter numbers: ";
	std::cin >> menu;
	std::cout << "\nYour words \"" << word1 << ' ' << word2 << "\" was changing to: ";
	
	switch (menu) {
		case 1: std::cout << word1.size() + word2.size() << '\n'; break;
		case 2: std::cout << word1.append(word2); break;
		case 3: word1.replace(0, 9, word2); break;
		case 4: word1.swap(word2); break;
		case 5: x = word1.compare(word2); break;
		default: std::cout << "There are 5 modes!\n"; break;
	}
	
	if (menu == 3) {
		std::cout << word1 << '\n';
	}
	
	if (menu == 4) {
		std::cout << word1 << ' ' << word2 << '\n';
	}
	
	if (menu == 5) {
		if (x == -1) {
			std::cout << "ascending alphabet - 1. " << word1 << "; 2. " << word2 << ".\n";
		}
		
		if (x == 0) {
			std::cout << "words identical - 1. " << word1 << "; 1. " << word2 << ".\n";
		}
		
		if (x == 1) {
			std::cout << "ascending alphabet - 1. " <<  word2 << "; 2. " << word1 << ".\n";
		}
	}
	return 0;
}
