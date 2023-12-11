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
using ranges::to;
using i64 = long long int;

void day11b() {
	vector<string> grid;

	string line;
	while (cin >> line) {
		grid.push_back(line);
	}

	vector<int> gridSkips;
	vector<int> rowSkips;

	int skips = 0;
	for (int i = 0; i < grid.size(); i++) {
		bool noStarsInRow = ranges::all_of(grid[i], [](auto c) {
			return c != '#';
		});
		if (noStarsInRow) {
			skips++;
		}
		rowSkips.push_back(skips);
	}

	skips = 0;
	for (int i = 0; i < grid[0].size(); i++) {

		bool noStarsInColumn = true;
		for (int j = 0; j < grid.size(); j++) {
			if (grid[j][i] == '#') {
				noStarsInColumn = false;
			}
		}

		if (noStarsInColumn) {
			skips++;
		}
		gridSkips.push_back(skips);
	}

	vector<pair<int, int>> coords;

	for (auto [x, l] : grid | enumerate) {
		for (auto [y, thing] : l | enumerate) {
			if (thing == '#') {
				coords.push_back({ x,y });
			}
		}
	}

	vector<i64> paths;

	for (auto [x, y] : coords) {
		for (auto [x2, y2] : coords) {
			i64 xSkips = abs(rowSkips[x] - rowSkips[x2]);
			i64 xGap = abs(x2 - x) + xSkips * 1000000 - xSkips;

			i64 ySkips = abs(gridSkips[y] - gridSkips[y2]);
			i64 yGap = abs(y2 - y) + ySkips * 1000000 - ySkips;

			paths.push_back(xGap + yGap);
		}
	}

	i64 sum = accumulate(paths.begin(), paths.end(), 0LL);
	println("{}", sum / 2);
}
