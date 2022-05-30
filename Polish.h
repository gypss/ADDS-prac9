#ifndef POLISH_H
#define POLISH_H
#include <string>
#include <vector>

class Polish {
public:
	std::string convert(std::vector<std::string> input, int length);
	void makeStacks(std::vector<std::string>, int length);
	bool isValid();
	std::string calculate(std::vector<std::string> input, int length);

	std::vector<char> opts;
	std::vector<char> nums;
};

#endif 