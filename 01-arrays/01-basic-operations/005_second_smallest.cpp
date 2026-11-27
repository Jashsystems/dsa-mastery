/*
 * 005 - Second smallest DISTINCT element
 * Type: IMPLEMENTATION EXERCISE - CURRENTLY MENTOR-ASSIGNED (no solution provided)
 *
 * Problem: Find the second smallest DISTINCT value, or report that none exists.
 * Constraints: 0 <= n <= 10^5; full int range.
 * Examples:
 *   {4, 1, 3, 1} -> 3
 *   {2, 2} -> no answer
 *
 * Target complexity: time O(n), one pass, auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 005_second_smallest.cpp -o 005_second_smallest
 *   ./005_second_smallest      (Windows PowerShell: .\005_second_smallest.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// Do this AFTER your mentor signs off 004. Same contract as secondLargestDistinct.
bool secondSmallestDistinct(const std::vector<int>& a, int& result) {
    (void)a;  // delete once you use `a`
    // TODO: your implementation
    result = 0;
    return false;
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
    int r = -999;
    check(secondSmallestDistinct({4, 1, 3, 1}, r) && r == 3, "duplicated minimum");
    check(secondSmallestDistinct({1, 2, 3, 4}, r) && r == 2, "ascending");
    check(secondSmallestDistinct({4, 3, 2, 1}, r) && r == 2, "descending");
    check(secondSmallestDistinct({-1, -2, -3}, r) && r == -2, "all negative");
    check(secondSmallestDistinct({INT_MAX, INT_MIN}, r) && r == INT_MAX, "boundary values");
    check(secondSmallestDistinct({1, 1, 2}, r) && r == 2, "second value at the end");
    check(!secondSmallestDistinct({2, 2}, r), "all identical");
    check(!secondSmallestDistinct({9}, r), "single element");
    check(!secondSmallestDistinct({}, r), "empty");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
