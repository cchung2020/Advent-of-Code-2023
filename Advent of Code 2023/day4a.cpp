#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <sstream>

using namespace std;
using namespace views;

void day4a() {
	string w;
	char c;
	int cardNum;

	int total = 0;

	while (cin >> w >> cardNum >> c) {
		set<int> winners;
		vector<int> numbers;
		string line;

		string str;
		getline(cin, str);

		stringstream stream;
		stream << str;

		while (stream >> str && str != "|") {
			winners.insert(stoi(str));
		}
		while (stream >> str) {
			numbers.push_back(stoi(str));
		}

		int score = 0;

		for (auto n : numbers) {
			if (winners.contains(n)) {
				if (score == 0) {
					score = 1;
				}
				else {
					score *= 2;
				}
			}
		}

		total += score;
	}

	println("{}", total);
}