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

tuple<int, int, Direction> next_shape(vector<string>& grid, int x, int y, Direction dir);

void day10a() {
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

	int cycleLength = 0;

	println("{} {}", x, y);
	cycleLength++;
	x++;
	Direction dir = Direction::Down;

	while (grid[x][y] != 'S') {
		tie(x, y, dir) = next_shape(grid, x, y, dir);
		cycleLength++;
		println("{} {} {}", x, y, static_cast<int>(dir));
	}

	println("{}", cycleLength / 2);
}

tuple<int, int, Direction> next_shape(vector<string>& grid, int x, int y, Direction dir) {
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
			println("S reached at {} {}", x, y);
			return { x, y, dir };
		}
		default: {
			println("default switch reached at {} {}", x, y);
			return { x, y, dir };
		}
	}
}
