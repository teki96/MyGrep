#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include "grep.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1) {
		bool oflag = false,
			lflag = false;

		if (argc == 3) {
			printLine(&argv[1], &argv[2], &argv[3], oflag, lflag);
		}

		if (argc == 4) {
			string flags = argv[1];
			if (flags.at(1) == 'o') {
				flags.erase(0, 2);
				if (flags.find("l") != string::npos) {
					lflag = true;
				}
				if (flags.find("o") != string::npos) {
					oflag = true;
				}
			}
			printLine(&argv[2], &argv[3], &argv[1], oflag, lflag);
		}
	}
	if (argc == 1)
	{
		setlocale(LC_ALL, "");
		char bigStr[50];
		char searchStr[50];
		char* result;
		try {
			cout << "Give a string from which to search for: ";
			cin.getline(bigStr, 49);

			cout << "Give search string: ";
			cin.getline(searchStr, 49);
		}
		catch (const exception& e)
		{
			cout << "An exception occurred. Exception Nr. " << e.what() << '\n';
			return 1;
		}
		result = strcasestr(bigStr, searchStr);

		if (result == nullptr) {
			cout << "\"" << searchStr << "\"" << " NOT found in " << bigStr << endl;
		}

		else {
			cout << "\"" << searchStr << "\"" << " found in " << bigStr << " at position " << result - bigStr + 1 << endl;
		}
	}

	return EXIT_SUCCESS;
}
