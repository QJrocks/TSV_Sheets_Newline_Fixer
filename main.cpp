#include <fstream>
#include <iostream>

//Change this as needed
constexpr char outfileName[] = "spell_card_commentary.txt";

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cout << "You need to drag a .tsv file onto this program to work!" << std::endl;
		std::cin.get();
		return -1;
	}

	std::ifstream infile(argv[1], std::fstream::binary);
	std::ofstream outfile(outfileName, std::fstream::trunc | std::fstream::binary);

	char prevChar = 0;
	char currentChar = 0;

	while (infile && outfile) {
		infile.read(&currentChar, 1);
		if (currentChar == 0x20 && prevChar == 0x0D) {
			currentChar = 0x0A;
		}
		prevChar = currentChar;

		outfile.write(&currentChar, 1);
	}

	std::cout << "Success!" << std::endl;
	std::cin.get();
	return 0;
}