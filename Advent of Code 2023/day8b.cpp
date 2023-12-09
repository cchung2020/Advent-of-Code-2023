#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <ranges>

using namespace std;
using namespace views;
using i64 = long long int;

void day8b() {
	map<string, pair<string, string>> record;

	string orderInput;
	getline(cin, orderInput);

	string dest, p1, p2;
	char c;
	
	while (cin >> dest >> c >> c >> p1 >> p2) {
		p1.pop_back();
		p2.pop_back();

		record[dest] = { p1, p2 };
	}

	vector<pair<string, i64>> currents;
	for (auto& [dest, pair] : record) {
		if (dest.back() == 'A') currents.push_back({dest, 0});
	}

	vector<i64> starting;
	for (auto&& [i, current] : currents | enumerate) {
		string copy = current.first;

		i64 inputI = 0;
		i64 first_z = 0;

		while (copy.back() != 'Z') {
			if (orderInput[inputI] == 'L') copy = record[copy].first;
			else copy = record[copy].second;

			inputI = (inputI + 1) % orderInput.size();
			first_z++;
		}

		starting.push_back(first_z);
	}

	i64 steps = 1;
	for (auto n : starting) {
		steps = abs(n) * abs(steps) / (gcd(n, steps));
	}

	println("{}", steps);
}
