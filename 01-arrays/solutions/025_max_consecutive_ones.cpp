/*
 * 025 - Maximum consecutive ones
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Given a vector containing only 0s and 1s, return the length of the longest run of consecutive 1s.
 * Constraints: 0 <= n <= 10^5; each element is 0 or 1.
 * Examples:
 *   {1, 1, 0, 1, 1, 1} -> 3
 *   {0, 0} -> 0
 *
 * Approach:
 *   Track the length of the current run and the best run seen.
 *   A 1 extends the run; a 0 resets it.
 *   Update the best whenever the current run exceeds it.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 025_max_consecutive_ones.cpp -o 025_max_consecutive_ones
 *   ./025_max_consecutive_ones      (Windows PowerShell: .\025_max_consecutive_ones.exe)
 */
#include <iostream>
#include <string>
#include <vector>

int maxConsecutiveOnes(const std::vector<int>& a) {
    int currentRun = 0;
    int bestRun = 0;
    for (int value : a) {
        if (value == 1) {
            ++currentRun;
            if (currentRun > bestRun) bestRun = currentRun;
        } else {
            currentRun = 0;       // a 0 breaks the run
        }
    }
    return bestRun;
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
