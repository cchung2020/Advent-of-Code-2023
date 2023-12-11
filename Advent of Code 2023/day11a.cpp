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

void day11a() {
	vector<string> grid;

	string line;
	while (cin >> line) {
		grid.push_back(line);
	}

	for (int i = 0; i < grid.size(); i++) {
		bool noStarsInRow = ranges::all_of(grid[i], [](auto c) {
			return c != '#';
		});
		if (noStarsInRow) {
			grid.insert(grid.begin() + i, grid[i]);
			i++;
		}

	}

	for (int i = 0; i < grid[0].size(); i++) {
		bool noStarsInColumn = true;
		for (int j = 0; j < grid.size(); j++) {
			if (grid[j][i] == '#') {
				noStarsInColumn = false;
			}
		}

		if (noStarsInColumn) {
			for (int j = 0; j < grid.size(); j++) {
				grid[j].insert(grid[j].begin() + i, '.');
			}

			i++;
		}
	}

	vector<pair<int, int>> coords;

	for (auto [x, l] : grid | enumerate) {
		for (auto [y, thing] : l | enumerate) {
			if (thing == '#') {
				coords.push_back({ x,y });
			}
		}
	}

	vector<int> paths;

	for (auto [x, y] : coords) {
		for (auto [x2, y2] : coords) {
			int pathLength = abs(x2 - x) + abs(y2 - y);
			paths.push_back(pathLength);
		}
	}

	int sum = accumulate(paths.begin(), paths.end(), 0);
	println("{}", sum / 2);
}
