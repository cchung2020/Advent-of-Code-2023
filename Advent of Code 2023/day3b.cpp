#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <ranges>
#include <optional>
#include <sstream>

using namespace std;
using namespace views;

optional<pair<int, int>> symbol_gear_neighbor(vector<string>& grid, int i, int j);

void day3b() {
	vector<string> grid;

	string line;
	while (getline(cin, line)) {
		grid.push_back(line);
	}

	map<pair<int, int>, vector<int>> record;

	for (int i = 0; i < grid.size(); i++) {
		int number = 0;
		optional<pair<int, int>> coords;

		for (int j = 0; j < grid[i].size(); j++) {
			if (isdigit(grid[i][j])) {
				number *= 10;
				number += grid[i][j] - '0';

				optional<pair<int,int>> result = symbol_gear_neighbor(grid, i, j);

				if (result.has_value()) {
					coords = result;
				}

				if (j == grid[i].size() - 1) {
					if (coords.has_value()) {
						record[coords.value()].push_back(number);
					}
					number = 0;
					coords = {};
				}
			}
			else if (!isdigit(grid[i][j])) {
				if (coords.has_value()) {
					record[coords.value()].push_back(number);
				}
				number = 0;
				coords = {};
			}
		}

	}

	long long int sum = 0;

	for (auto& [coord, nums] : record) {
		if (nums.size() == 2) {
			sum += nums[0] * nums[1];
		}
	}

	println("{}", sum);
}

optional<pair<int,int>> symbol_gear_neighbor(vector<string>& grid, int i, int j) {
	if (i > 0 && grid[i - 1][j] != '.'
		&& !isdigit(grid[i - 1][j]) && grid[i-1][j] == '*') {
		return { {i - 1, j} };
	}
	else if (i < grid.size() - 1 && grid[i + 1][j] != '.'
		&& !isdigit(grid[i + 1][j]) && grid[i + 1][j] == '*') {
		return { {i + 1, j} };
	}
	else if (j > 0 && grid[i][j - 1] != '.'
		&& !isdigit(grid[i][j - 1]) && grid[i][j - 1] == '*') {
		return { {i, j - 1} };
	}
	else if (j < grid[i].size() - 1 && grid[i][j + 1] != '.'
		&& !isdigit(grid[i][j + 1]) && grid[i][j + 1] == '*') {
		return { {i, j + 1} };
	}

	else if (i > 0 && j > 0 && grid[i - 1][j - 1] != '.'
		&& !isdigit(grid[i - 1][j - 1]) && grid[i - 1][j - 1] == '*') {
		return { {i - 1, j - 1} };
	}
	else if (i < grid.size() - 1 && j < grid[i].size() - 1
		&& grid[i + 1][j + 1] != '.' && !isdigit(grid[i + 1][j + 1]) && grid[i + 1][j + 1] == '*') {
		return { {i + 1, j + 1} };
	}
	else if (j > 0 && i < grid.size() - 1
		&& grid[i + 1][j - 1] != '.' && !isdigit(grid[i + 1][j - 1]) && grid[i + 1][j - 1] == '*') {
		return { {i + 1, j - 1} };
	}
	else if (j < grid[i].size() - 1 && i > 0
		&& grid[i - 1][j + 1] != '.' && !isdigit(grid[i - 1][j + 1]) && grid[i - 1][j + 1] == '*') {
		return { {i - 1, j + 1} };
	}

	return { };
}
