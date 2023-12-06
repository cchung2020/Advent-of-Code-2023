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

void day6a() {
    string line;

    getline(cin, line);
    vector<int> times = line
        | split(' ')
        | drop(1)
        | filter([](auto s) {return s.size() > 0; })
        | views::transform([](auto s) { return stoi(s | ranges::to<string>()); })
        | ranges::to<vector<int>>();

    getline(cin, line);
    vector<int> distances = line
        | split(' ')
        | drop(1)
        | filter([](auto s) {return s.size() > 0; })
        | views::transform([](auto s) { return stoi(s | ranges::to<string>()); })
        | ranges::to<vector<int>>();

    vector<int> higher_scores;

    for (auto [race, time] : times | enumerate) {
        int distance = distances[race];
        int wins = 0;

        for (int i = 0; i < time; i++) {
            int score = i * (time - i);
            if (score > distance) {
                wins++;
            }
        }
        higher_scores.push_back(wins);
    }

    int total = 1;
    for (auto n : higher_scores) {
        total *= n;
    }

    println("{}", total);
}
