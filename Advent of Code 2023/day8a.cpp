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
#include <optional>

using namespace std;
using namespace views;
using ranges::to;

void day8a() {
	map<string, pair<string, string>> record;

	string orderInput;
	getline(cin, orderInput);
	
	string dest, p1, p2;
	char c;

	int steps = 0;

	while (cin >> dest >> c >> c >> p1 >> p2) {
		p1.pop_back();
		p2.pop_back();

		record[dest] = { p1, p2 };
	}

	string current = "AAA";

	int inputI = 0;

	while (current != "ZZZ") {
		if (orderInput[inputI] == 'L') current = record[current].first;
		else current = record[current].second;


		inputI = (inputI + 1) % orderInput.size();
		steps++;
	}

	println("{}", steps);
}
