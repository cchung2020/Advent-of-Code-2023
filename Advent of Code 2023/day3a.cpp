#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <ranges>
#include <sstream>

using namespace std;
using namespace views;

bool symbol_neighbor(vector<string>& grid, int i, int j);

void day3a() {
	vector<string> grid;

	string line;
	while (getline(cin, line)) {
		grid.push_back(line);
	}

	long long int sum = 0;

	for (int i = 0; i < grid.size(); i++) {
		int number = 0;
		bool symbol = false;
		
		for (int j = 0; j < grid[i].size(); j++) {
			if (isdigit(grid[i][j])) {
				number *= 10;
				number += grid[i][j] - '0';

				symbol = symbol || symbol_neighbor(grid, i, j);

				if (j == grid[i].size() - 1) {
					if (symbol) {
						sum += number;
					}
					number = 0;
					symbol = false;
				}
			}
			else if (!isdigit(grid[i][j])) {
				if (symbol) {
					sum += number;
				}
				number = 0;
				symbol = false;
			}
		}

	}

	println("{}", sum);
}

bool symbol_neighbor(vector<string>& grid, int i, int j) {
	if (i > 0 && grid[i - 1][j] != '.' 
			&& !isdigit(grid[i - 1][j])) {
		return true;
	}
	else if (i < grid.size() - 1 && grid[i + 1][j] != '.' 
			&& !isdigit(grid[i + 1][j])) {
		return true;
	}
	else if (j > 0 && grid[i][j - 1] != '.' 
			&& !isdigit(grid[i][j - 1])) {
		return true;
	}
	else if (j < grid[i].size() - 1 && grid[i][j+1] != '.' 
			&& !isdigit(grid[i][j + 1])) {
		return true;
	}

	else if (i > 0 && j > 0 && grid[i - 1][j - 1] != '.' 
			&& !isdigit(grid[i - 1][j - 1])) {
		return true;
	}
	else if (i < grid.size() - 1 && j < grid[i].size() - 1 
			&& grid[i + 1][j + 1] != '.' && !isdigit(grid[i + 1][j + 1])) {
		return true;
	}
	else if (j > 0 && i < grid.size() - 1
			&& grid[i + 1][j - 1] != '.' && !isdigit(grid[i + 1][j - 1])) {
		return true;
	}
	else if (j < grid[i].size() - 1 && i > 0 
			&& grid[i - 1][j + 1] != '.' && !isdigit(grid[i - 1][j + 1])) {
		return true;
	}

	return false;
}