/*
 * 002 - Find the maximum element (MENTOR PROBLEM 001)
 * Type: IMPLEMENTATION EXERCISE - CURRENTLY MENTOR-ASSIGNED (no solution provided)
 *
 * Problem: Return the largest value in a non-empty vector of ints.
 * Constraints: 1 <= n <= 10^5 (the vector is NEVER empty); -2^31 <= a[i] <= 2^31 - 1.
 * Examples:
 *   {3, 9, 2} -> 9
 *   {-3, -1, -7} -> -1
 *   {4, 4, 4} -> 4
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 002_find_maximum.cpp -o 002_find_maximum
 *   ./002_find_maximum      (Windows PowerShell: .\002_find_maximum.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// Precondition: a is non-empty (constraint above), so a[0] always exists.
// Rule for this assignment: write the loop yourself - do NOT call std::max_element.
int findMaximum(const std::vector<int>& a) {
    (void)a;  // silences "unused parameter"; delete this line once you use `a`
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
    check(findMaximum({3, 9, 2}) == 9, "max in the middle");
    check(findMaximum({42}) == 42, "single element");
    check(findMaximum({-3, -1, -7}) == -1, "all negative");
    check(findMaximum({4, 4, 4}) == 4, "all identical");
    check(findMaximum({1, 2, 3, 4, 5}) == 5, "already sorted ascending");
    check(findMaximum({5, 4, 3, 2, 1}) == 5, "sorted descending");
    check(findMaximum({9, 1, 9, 2}) == 9, "maximum repeated");
    check(findMaximum({INT_MIN, INT_MAX, 0}) == INT_MAX, "boundary values");
    check(findMaximum({INT_MIN, INT_MIN}) == INT_MIN, "only INT_MIN");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
