/*
 * 025 - Maximum consecutive ones
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: Given a vector containing only 0s and 1s, return the length of the longest run of consecutive 1s.
 * Constraints: 0 <= n <= 10^5; each element is 0 or 1.
 * Examples:
 *   {1, 1, 0, 1, 1, 1} -> 3
 *   {0, 0} -> 0
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 025_max_consecutive_ones.cpp -o 025_max_consecutive_ones
 *   ./025_max_consecutive_ones      (Windows PowerShell: .\025_max_consecutive_ones.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Category hint: linear traversal maintaining two variables (what are they?).
int maxConsecutiveOnes(const std::vector<int>& a) {
    (void)a;  // delete once you use `a`
    // TODO: your implementation
    return -1;
}

// ---- test helper (no need to modify) ----
int failures = 0;
void check(bool condition, const std::string& label) {
    if (!condition) {
        std::cout << "FAIL: " << label << '\n';
        ++failures;
    }
}

int main() {
    check(maxConsecutiveOnes({}) == 0, "empty");
    check(maxConsecutiveOnes({0, 0}) == 0, "no ones");
    check(maxConsecutiveOnes({1}) == 1, "single one");
    check(maxConsecutiveOnes({1, 1, 1}) == 3, "all ones");
    check(maxConsecutiveOnes({1, 1, 0, 1, 1, 1}) == 3, "best run is last");
    check(maxConsecutiveOnes({1, 1, 1, 0, 1}) == 3, "best run is first");
    check(maxConsecutiveOnes({1, 0, 1, 0, 1}) == 1, "alternating");
    check(maxConsecutiveOnes({0, 1, 1, 0}) == 2, "run in the middle");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
