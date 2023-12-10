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

enum class Direction {
	Up,
	Right,
	Left,
	Down
};

tuple<int, int, Direction> next_shapeb(vector<string>& grid, int x, int y, Direction dir);
void remove_outer_area(vector<string>& grid, int x, int y);

void day10b() {
	vector<string> grid;

	string line;
	while (cin >> line) {
		grid.push_back(line);
	}


	int x, y;
	for (auto [i, line] : grid | enumerate) {
		for (auto [j, p] : line | enumerate) {
			if (p == 'S') {
				x = i;
				y = j;
			}
		}
	}


	x++;
	Direction dir = Direction::Down;

	while (grid[x][y] != '!') {
		int oldX = x;
		int oldY = y;

		tie(x, y, dir) = next_shapeb(grid, x, y, dir);
		grid[oldX][oldY] = '!';
		//println("{} {} {}", x, y, static_cast<int>(dir));
	}
	
	for (int i = 0; i < grid.size(); i++) {
		remove_outer_area(grid, i, 0);
		remove_outer_area(grid, i, grid[i].size() - 1);
	}

	for (int j = 0; j < grid.size(); j++) {
		remove_outer_area(grid, 0, j);
		remove_outer_area(grid, grid.size() - 1, j);
	}


	int area = 0;

	for (auto l : grid) {
		for (auto p : l) {
			if (p != '#' && p != '!') {
				area++;
			}
		}
	}

	println("{}", area);

	for (auto l : grid) println("{}", l);

}

tuple<int, int, Direction> next_shapeb(vector<string>& grid, int x, int y, Direction dir) {
	using enum Direction;
	switch (grid[x][y]) {
	case '|': {
		if (dir == Up) return { x - 1, y, Up };
		else           return { x + 1, y, Down };
	}
	case '-': {
		if (dir == Right) return { x, y + 1, Right };
		else              return { x, y - 1, Left };
	}
	case 'L': {
		if (dir == Left) return { x - 1, y, Up };
		else             return { x, y + 1, Right };
	}
	case 'J': {
		if (dir == Right) return { x - 1, y, Up };
		else              return { x, y - 1, Left };
	}
	case '7': {
		if (dir == Right) return { x + 1, y, Down };
		else              return { x, y - 1, Left };
	}
	case 'F': {
		if (dir == Left)  return { x + 1, y, Down };
		else              return { x, y + 1, Right };
	}
	case '.': {
		println("dot at {} {}", x, y);
		return { x, y, dir };
	}
	case 'S': {
		return { x, y, dir };
	}
	default: {
		println("default switch reached at {} {}", x, y);
		return { x, y, dir };
	}
	}
}

void remove_outer_area(vector<string>& grid, int x, int y) {
	vector<pair<int, int>> neighbors = { {x,y} };

	while (neighbors.size() > 0) {
		x = neighbors.back().first;
		y = neighbors.back().second;
		neighbors.pop_back();

		if (x > 0 && grid[x - 1][y] != '#' && grid[x - 1][y] != '!') {
			neighbors.push_back({ x - 1, y });
			grid[x - 1][y] = '#';
		}
		if (y > 0 && grid[x][y - 1] != '#' && grid[x][y - 1] != '!') {
			neighbors.push_back({ x, y - 1 });
			grid[x][y - 1] = '#';
		}
		if (x < grid.size() - 1 && grid[x + 1][y] != '#' && grid[x + 1][y] != '!') {
			neighbors.push_back({ x + 1, y });
			grid[x + 1][y] = '#';
		}
		if (y < grid[0].size() - 1 && grid[x][y + 1] != '#' && grid[x][y + 1] != '!') {
			neighbors.push_back({ x, y + 1 });
			grid[x][y + 1] = '#';
		}
	}
}