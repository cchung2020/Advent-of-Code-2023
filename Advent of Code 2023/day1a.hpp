#include <iostream>
#include <print>
#include <string>

using namespace std;

void day1a() {
	string line;

	int sum = 0;

	while (getline(cin, line)) {
		string digits;

		for (auto c : line) {
			if (isdigit(c)) {
				digits += c;
			}
		}
		println("{}", digits);

		string num;
		num += digits[0];
		num += digits.back();

		if (num.size() > 0) {
			sum += stoi(num);
		}
	}

	print("{}", sum);
}
