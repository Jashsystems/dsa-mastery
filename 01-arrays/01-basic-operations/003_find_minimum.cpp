/*
 * 003 - Find the minimum element
 * Type: IMPLEMENTATION EXERCISE - CURRENTLY MENTOR-ASSIGNED (no solution provided)
 *
 * Problem: Return the smallest value in a non-empty vector of ints.
 * Constraints: 1 <= n <= 10^5 (never empty); full int range.
 * Examples:
 *   {3, 9, 2} -> 2
 *   {-3, -1, -7} -> -7
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 003_find_minimum.cpp -o 003_find_minimum
 *   ./003_find_minimum      (Windows PowerShell: .\003_find_minimum.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// Do this AFTER your mentor signs off 002. Same rule: no std::min_element.
int findMinimum(const std::vector<int>& a) {
    (void)a;  // delete this line once you use `a`
    // TODO: your implementation
    return 0;
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
    check(findMinimum({3, 9, 2}) == 2, "min at the end");
    check(findMinimum({42}) == 42, "single element");
    check(findMinimum({-3, -1, -7}) == -7, "all negative");
    check(findMinimum({4, 4, 4}) == 4, "all identical");
    check(findMinimum({1, 2, 3, 4, 5}) == 1, "sorted ascending");
    check(findMinimum({5, 4, 3, 2, 1}) == 1, "sorted descending");
    check(findMinimum({INT_MIN, INT_MAX, 7}) == INT_MIN, "boundary values");
    check(findMinimum({INT_MAX, INT_MAX}) == INT_MAX, "only INT_MAX");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
