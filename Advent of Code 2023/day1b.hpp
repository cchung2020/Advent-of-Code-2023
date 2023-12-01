#pragma once

#include <iostream>
#include <print>
#include <string>
#include <optional>
#include <ranges>
#include <set>
#include <string_view>

using namespace std;
using namespace views;

optional<char> starts_with_num(string_view str);

void day1b() {
	string line;
	int sum = 0;

	while (getline(cin, line)) {
		string digits;

		for (auto [i, c] : line | views::enumerate) {
			if (isdigit(c)) {
				digits += c;
			}
			else {
				auto result = starts_with_num(string_view(line | drop(i)));
				if (result.has_value()) {
					digits += result.value();
				}
			}
		}

		string num = { digits[0], digits.back() };
		sum += stoi(num);
	}

	print("{}", sum);
}

optional<char> starts_with_num(string_view str) {
	string three_letters = str
		| take(3)
		| ranges::to<string>();
	string four_letters = str
		| take(4)
		| ranges::to<string>();
	string five_letters = str
		| take(5)
		| ranges::to<string>();

	set<string> letters = { three_letters, four_letters, five_letters };

	if (letters.contains("one")) {
		return { '1' };
	}
	else if (letters.contains("two")) {
		return { '2' };
	}
	else if (letters.contains("three")) {
		return { '3' };
	}
	else if (letters.contains("four")) {
		return { '4' };
	}
	else if (letters.contains("five")) {
		return { '5' };
	}
	else if (letters.contains("six")) {
		return { '6' };
	}
	else if (letters.contains("seven")) {
		return { '7' };
	}
	else if (letters.contains("eight")) {
		return { '8' };
	}
	else if (letters.contains("nine")) {
		return { '9' };
	}

	return {};
}
