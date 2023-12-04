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

void day4b() {
	string w;
	char c;
	int cardNum;

	int total = 0;
	map<int, int> record;

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

		int matches = 0;

		for (auto n : numbers) {
			if (winners.contains(n)) {
				matches++;
			}
		}
		
		record[cardNum]++;
		for (int j = cardNum + 1; j <= cardNum + matches; j++) {
			record[j] += record[cardNum];
		}

	}

	for (auto [card, count] : record) {
		total += count;
	}

	println("{}", total);
}
