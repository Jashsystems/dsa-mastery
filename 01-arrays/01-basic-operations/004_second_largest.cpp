/*
 * 004 - Second largest DISTINCT element (MENTOR PROBLEM 002)
 * Type: IMPLEMENTATION EXERCISE - CURRENTLY MENTOR-ASSIGNED (no solution provided)
 *
 * Problem: Find the second largest DISTINCT value. If the vector has fewer than 2 distinct values, there is no answer.
 * Constraints: 0 <= n <= 10^5 (empty vector is allowed here); full int range.
 * Examples:
 *   {1, 2, 3, 4} -> 3
 *   {10, 10, 9} -> 9 (duplicates of the maximum do not count)
 *   {5, 5, 5} -> no answer
 *   {7} -> no answer
 *
 * Target complexity: time O(n), ONE pass, auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 004_second_largest.cpp -o 004_second_largest
 *   ./004_second_largest      (Windows PowerShell: .\004_second_largest.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// Because every int is a legal answer, we cannot return a "special" int to mean "no answer".
// So: return true/false for "answer exists", and write the answer into `result`.
//   int& result  = a REFERENCE: assigning to `result` changes the caller's variable.
bool secondLargestDistinct(const std::vector<int>& a, int& result) {
    (void)a;  // delete once you use `a`
    // TODO: your implementation (one pass, no sorting, no std::set)
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
    check(secondLargestDistinct({1, 2, 3, 4}, r) && r == 3, "ascending");
    check(secondLargestDistinct({4, 3, 2, 1}, r) && r == 3, "descending");
    check(secondLargestDistinct({10, 10, 9}, r) && r == 9, "duplicated maximum");
    check(secondLargestDistinct({2, 3, 3}, r) && r == 2, "duplicate at the top, second last");
    check(secondLargestDistinct({3, 3, 2, 2, 1}, r) && r == 2, "several duplicates");
    check(secondLargestDistinct({-1, -2, -3}, r) && r == -2, "all negative");
    check(secondLargestDistinct({INT_MAX, INT_MIN}, r) && r == INT_MIN, "boundary values");
    check(secondLargestDistinct({1, 2}, r) && r == 1, "exactly two distinct");
    check(!secondLargestDistinct({5, 5, 5}, r), "all identical -> no answer");
    check(!secondLargestDistinct({7}, r), "single element -> no answer");
    check(!secondLargestDistinct({}, r), "empty -> no answer");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
