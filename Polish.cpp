#include "Polish.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Polish::calculate(vector<string> input, int length) {

	string expression = this->convert(input, length);

	this->makeStacks(input, length);

	if (!this->isValid()) {
		return "Error";
	}
	else
	return expression;

}

string Polish::convert(vector<string> input, int length) {

	vector<string> infix;

	for (int i = length-1; i >= 0; i--) {
		if (input[i][0] == '*' || input[i][0] == '/' || input[i][0] == '+' || input[i][0] == '-') {
			
			string first = infix[0];
			string last = infix[1];
			string newStr = first + input[i] + last;

			if (i != 0 && !((input[i][0] == '+' || input[i][0] == '-') && (input[i - 1][0] == '+' || input[i - 1][0] == '-'))) {
				newStr = "(" + newStr + ")";
			}

			infix.erase(infix.begin());
			infix.erase(infix.begin());
			infix.insert(infix.begin(), newStr);
		}
		else {
			infix.insert(infix.begin(), input[i]);
		}

	}

	return infix[0];
}

void Polish::makeStacks(vector<string> input, int length) {

	for (int i = 0; i < length; i++) {
		if (input[i][0] == '+' || input[i][0] == '-' || input[i][0] == '/' || input[i][0] == '*') {
			opts.push_back(input[i][0]);
		}
		else if (input[i][0] != '(' && input[i][0] != ')'){
			nums.push_back(input[i][0]);
		}
	}

}

bool Polish::isValid() {

	if (opts.size() == nums.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}


