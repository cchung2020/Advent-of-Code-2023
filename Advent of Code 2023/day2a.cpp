#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <ranges>

using namespace std;
using namespace views;

void day2a() {
	string w;
	char c;
	int gameNum;
	int idSum = 0;

	while (cin >> w >> gameNum >> c) {
		string line;
		getline(cin, line);

		auto games = line 
			| split(';')
			| transform([](auto l) { 
			return l
				| split(',') 
				| transform([](auto s) {
				return s
					| split(' ')
					| filter([](auto v) { return v.size() > 0; })
					| ranges::to<vector<string>>();
				})
				| transform([](auto v) { return pair(stoi(v[0]), v[1]); });
			});

		bool gameOk = true;

		for (auto group : games) {
			map<string, int> record;
			for (auto [num, color] : group) {
				record[color] += num;
			}

			if (record["red"] > 12 || record["green"] > 13 || record["blue"] > 14) {
				gameOk = false;
			}
		}

		if (gameOk) {
			idSum += gameNum;
		}
	}

	print("{}", idSum);
}
