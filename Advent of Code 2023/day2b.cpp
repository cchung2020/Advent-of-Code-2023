#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <ranges>

using namespace std;
using namespace views;

void day2b() {
	string w;
	char c;
	int gameNum;
	long long int sum = 0;

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

		map<string, int> max_needed;

		for (auto group : games) {
			for (auto [num, color] : group) {
				max_needed[color] = max(max_needed[color], num);
			}
		}

		sum += max_needed["red"] * max_needed["green"] * max_needed["blue"];
	}

	print("{}", sum);
}
