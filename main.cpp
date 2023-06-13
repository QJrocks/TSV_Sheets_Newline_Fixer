#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cout << "You need to drag a .tsv file onto this program to work!" << std::endl;
		std::cin.get();
		return -1;
	}

	std::string filename = std::string(argv[1]);
	std::string outfileName = filename;
	outfileName = outfileName.replace(outfileName.begin() + outfileName.find(".tsv"), outfileName.end(), ".txt");
	
	std::wifstream infile(filename, std::fstream::binary);
	std::wofstream outfile(outfileName, std::fstream::trunc | std::fstream::binary);

	wchar_t prevChar = 0;
	wchar_t currentChar = 0;

	while (infile && outfile) {
		infile.read(&currentChar, 1);
		if (currentChar == L' ' && prevChar == L'\r') {
			currentChar = L'\n';
		}
		prevChar = currentChar;

		outfile.write(&currentChar, 1);
	}

	std::cout << "Success!" << std::endl;
	std::cin.get();
	return 0;
}