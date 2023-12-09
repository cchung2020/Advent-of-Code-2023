#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;
using namespace views;
using ranges::to;
using i64 = long long int;

void day9a() {
	i64 sum = 0;

	string line;
	while (getline(cin, line)) {
		vector<i64> nums = line
			| split(' ')
			| views::transform([](auto s) {return stoll(s | to<string>()); })
			| to<vector>();

		vector<vector<int>> gaps = { {} };
		for (int i = 0; i < nums.size() - 1; i++) {
			gaps.back().push_back(nums[i+1] - nums[i]);
		}

		bool all_zeros = ranges::all_of(gaps.back(), [](auto n) {
			return n == 0;
		});

		while (!all_zeros) {
			gaps.push_back({});
			for (int i = 0; i < gaps[gaps.size()-2].size() - 1; i++) {
				gaps.back().push_back(gaps[gaps.size() - 2][i+1] - gaps[gaps.size() - 2][i]);
			}

			all_zeros = ranges::all_of(gaps.back(), [](auto n) {
				return n == 0;
			});
		}

		i64 newVal = 0;
		for (auto& v : gaps) {
			newVal += v.back();
		}

		sum += nums.back() + newVal;
	}

	println("{}", sum);
}
