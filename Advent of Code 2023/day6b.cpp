#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <ranges>

using namespace std;
using namespace views;
using i64 = long long int;

void day6b() {
    string line;

    getline(cin, line);
    i64 time = stoll(line
        | split(' ')
        | drop(1)
        | filter([](auto s) { return s.size() > 0; })
        | join
        | ranges::to<string>());

    getline(cin, line);
    i64 distance = stoll(line
        | split(' ')
        | drop(1)
        | filter([](auto s) { return s.size() > 0; })
        | join
        | ranges::to<string>());

    int lower = 0 , upper = time;
    
    while (lower != upper && lower + 1 != upper) {
        i64 num = (lower + upper) / 2;

        if (num * (time - num) <= distance) {
            lower = num;
        }
        else {
            upper = num;
        }
    }

    println("{}", time-(lower+upper));
}
