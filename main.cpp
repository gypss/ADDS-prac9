#include "Polish.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(void) {

	Polish pol;
	string input;
	vector<string> str;

	getline(cin, input);

	for (int i = 0; i < (int)input.length(); i++) {

		if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || isdigit(input[i])) {
			string element(1, input[i]);
			str.push_back(element);
		}
		else if (input[i] == ' ') {
			continue;
		}
		else {
			cout << "Error" << endl;
			return 1;
		}
		
	}



	string expression = pol.calculate(str, str.size());

	cout << expression;

}