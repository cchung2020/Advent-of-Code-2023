#include <print>
#include <chrono>
#include "solutions.hpp"

using std::chrono::duration_cast, std::chrono::milliseconds;

int main() {
	// auto start = std::chrono::system_clock::now();

	day3b();

	// auto end = std::chrono::system_clock::now();
	// println("\n{} elapsed", duration_cast<milliseconds>(end - start));
}
