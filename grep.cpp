#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char* strcasestr(const char* bigStr, const char* searchStr)
{
	char* big_p = new char[strlen(bigStr) + 1];
	char* search_p = new char[strlen(searchStr) + 1];

	char* point_p;
	int offset;

	strcpy(big_p, bigStr);
	strcpy(search_p, searchStr);

	int i = 0;
	while (*(big_p + i) != '\0') {
		*(big_p + i) = tolower(*(big_p + i));
		i++;
	}

	i = 0;
	while (*(search_p + i) != '\0') {
		*(search_p + i) = tolower(*(search_p + i));
		i++;
	}

	point_p = strstr(big_p, search_p);
	offset = point_p - big_p;

	delete[] big_p;
	delete[] search_p;

	return point_p != nullptr ? (char*)bigStr + offset : point_p;
}

void printLine(char* arg1[], char* arg2[], char* arg3[], bool o, bool l)
{

	fstream filu(*arg2);

	if (!filu.is_open())
		cout << "Could not open file\n";
	else
	{
		string search = *arg1;
		string rivi;

		int rivinumero = {};
		int occured = {};

		while (getline(filu, rivi)) {
			rivinumero++;
			if (rivi.find(search) != string::npos) {
				if (l == true) {
					cout << rivinumero << ":\t" << rivi << endl;
				}
				else {
					cout << rivi << endl;
				}
				++occured;
			}
		}
		if (o == true) {
			cout << "Occurrences of lines containing \"" << search << "\": " << occured << endl;
		}
	}
}
