/*
#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <optional>
#include <sstream>

using namespace std;
using namespace views;

long long int back_type(
	map<pair<string, string>,
	vector<tuple<long long int, long long int, long long int>>>& records
	, pair<string, string> pairType, long long int num);

void day5b() {
	map<pair<string, string>, vector<tuple<long long int, long long int, long long int>>> records;

	string line, word, destination, source;
	char c;

	cin >> word;
	getline(cin, line);

	vector<long long int> seeds = line
		| split(' ')
		| filter([](auto r) { return r.size() > 0; })
		| views::transform([](auto s) { return stoll(s | ranges::to<string>()); })
		| ranges::to<vector<long long int>>();

	vector<pair<long long int, long long int>> seedRanges = seeds
		| chunk(2)
		| ranges::to<vector<vector<long long int>>>()
		| views::transform([](auto& v) { return pair(v[0], v[1]); })
		| ranges::to<vector<pair<long long int, long long int>>>();

	string lineType;
	pair<string, string> recordType = {};

	while (getline(cin, line)) {
		if (line.size() > 0 && !isdigit(line[0])) {
			lineType = line;
			auto from_to = line
				| take_while([](auto c) { return c != ' '; })
				| split('-')
				| ranges::to<vector<string>>();
			recordType = pair(from_to[0], from_to[2]);
		}
		else if (line.size() > 0 && isdigit(line[0])) {
			stringstream stream;
			stream << line;
			long long int destination, source, size;
			stream >> destination >> source >> size;

			records[recordType].push_back({ destination, source, size });
		}
	}

	vector<long long int> locations;

	for (auto seed : seeds) {
		auto next = back_type(records, { "seed", "soil" }, seed);
		next = back_type(records, { "soil", "fertilizer" }, next);
		next = back_type(records, { "fertilizer", "water" }, next);
		next = back_type(records, { "water", "light" }, next);
		next = back_type(records, { "light", "temperature" }, next);
		next = back_type(records, { "temperature", "humidity" }, next);
		auto location = back_type(records, { "humidity", "location" }, next);

		locations.push_back(location);
	}

	println("{}", *ranges::min_element(locations));
}

long long int back_type(
	map<pair<string, string>,
	vector<tuple<long long int, long long int, long long int>>>& records
	, pair<string, string> pairType, long long int num) {
	for (auto [dest, source, size] : records[pairType]) {
		if (num >= source && num < source + size) {
			return dest + (num - source);
		}
	}

	return num;
}
*/
