/* 
Title: Roman Numeral Converter
Author: Jarom Harris, harrisjarom@gmail.com
Language: C++
Time Spent: 4 hours
Date: 3/1/2020
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsSubtractiveNotation(size_t numeralIndex, vector<int> lettersTranslated) {
	if (numeralIndex == (lettersTranslated.size() - 1))
		return false;
	else if (lettersTranslated.at(numeralIndex) < lettersTranslated.at(numeralIndex + 1))
		return true;
	else
		return false;
}

int RomanToModern(string roman) {
	vector<int> lettersTranslated;
	// The following makes a vector with decimal values corresponding to the roman numeral.
	// This will make it easier to compare their values and determine if we need addition 
	// or subraction.
	for (size_t i = 0; i < roman.size(); ++i) {
		if (roman.at(i) == 'I')
			lettersTranslated.push_back(1);
		else if (roman.at(i) == 'V')
			lettersTranslated.push_back(5);
		else if (roman.at(i) == 'X')
			lettersTranslated.push_back(10);
		else if (roman.at(i) == 'L')
			lettersTranslated.push_back(50);
		else if (roman.at(i) == 'C')
			lettersTranslated.push_back(100);
		else if (roman.at(i) == 'D')
			lettersTranslated.push_back(500);
		else if (roman.at(i) == 'M')
			lettersTranslated.push_back(1000);
		else {
			lettersTranslated.clear();
			break;  // clearing the vector indicates that there was an invalid input
		}
	}
	int newModern = 0;
	for (size_t i = 0; i < lettersTranslated.size(); ++i) {
		if (IsSubtractiveNotation(i, lettersTranslated)) {
			lettersTranslated.at(i) = lettersTranslated.at(i + 1) - lettersTranslated.at(i);
			lettersTranslated.at(i + 1) = 0;
		}
		newModern += lettersTranslated.at(i);
	}
	return newModern;	// will return 0 is the input had something other than MDCLXVI
}

string ModernToRoman(int number) {  // Numbers are subtracted from the input number while
	string roman;					// roman numerals are pushed onto a string.
	while (number != 0) {
		if (number >= 1000) {
			roman.push_back('M');
			number = number - 1000;
		}
		else if ((number < 1000) && (number >= 900)) {
			roman.push_back('C');
			roman.push_back('M');
			number = number - 900;
		}
		else if ((number < 900) && (number >= 500)) {
			roman.push_back('D');
			number = number - 500;
		}
		else if ((number < 500) && (number >= 400)) {
			roman.push_back('C');
			roman.push_back('D');
			number = number - 400;
		}
		else if ((number < 400) && (number >= 100)) {
			roman.push_back('C');
			number = number - 100;
		}
		else if ((number < 100) && (number >= 90)) {
			roman.push_back('X');
			roman.push_back('C');
			number = number - 90;
		}
		else if ((number < 90) && (number >= 50)) {
			roman.push_back('L');
			number = number - 50;
		}
		else if ((number < 50) && (number >= 40)) {
			roman.push_back('X');
			roman.push_back('L');
			number = number - 40;
		}
		else if ((number < 40) && (number >= 10)) {
			roman.push_back('X');
			number = number - 10;
		}
		else if ((number < 10) && (number >= 9)) {
			roman.push_back('I');
			roman.push_back('X');
			number = number - 9;
		}
		else if ((number < 9) && (number >= 5)) {
			roman.push_back('V');
			number = number - 5;
		}
		else if (number == 4) {
			roman.push_back('I');
			roman.push_back('V');
			number = number - 4;
		}
		else {
			roman.push_back('I');
			number--;
		}
	}
	return roman;
}

bool IsInteger(string input) {
	for (size_t i = 0; i < input.size(); ++i) {
		if (!isdigit(input.at(i)))
			return false;
	}
	return true;
}


int main() {
	string inputNumber;
	int modernNumber = 0;
	cout << "Welcome to the Roman Numeral Converter!" << endl;
	cout << "This utility converts roman numerals to modern numbers and vice versa." << endl << endl;

	while (true) {
		cout << "Enter your roman numeral or modern number, or enter DONE:" << endl;
		getline(cin, inputNumber);

		if (inputNumber == "DONE")
			break;
		else if (IsInteger(inputNumber)) {
			modernNumber = stoi(inputNumber);
			string newRoman = ModernToRoman(modernNumber);
			cout << newRoman << endl << endl;
		}
		else {
			modernNumber = RomanToModern(inputNumber);
			if (modernNumber != 0)
				cout << modernNumber << endl << endl;
			else
				cout << "Invalid input. Please try again." << endl << endl;
		}
		modernNumber = 0;
	}

	cout << "Thanks for using the Roman Numeral Converter." << endl;

	system("pause");
	return 0;
}