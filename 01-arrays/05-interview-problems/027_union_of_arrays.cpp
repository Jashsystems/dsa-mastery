/*
 * 027 - Union of two sorted arrays
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: Given two vectors sorted in non-decreasing order (duplicates allowed), return a sorted vector of the DISTINCT values that appear in at least one of them.
 * Constraints: 0 <= n, m <= 10^5; both inputs sorted.
 * Examples:
 *   {1,1,2,3,4,5}, {2,3,4,4,5,6} -> {1,2,3,4,5,6}
 *
 * Target complexity: time O(n + m), auxiliary space O(1) beyond the output
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 027_union_of_arrays.cpp -o 027_union_of_arrays
 *   ./027_union_of_arrays      (Windows PowerShell: .\027_union_of_arrays.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Category hint: two pointers over two sorted arrays (compare with 017) + skip repeated values.
std::vector<int> unionSorted(const std::vector<int>& a, const std::vector<int>& b) {
    (void)a;  // delete these two lines once you use the parameters
    (void)b;
    // TODO: your implementation
    return {-1};
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
    check(unionSorted({1, 1, 2, 3, 4, 5}, {2, 3, 4, 4, 5, 6}) == std::vector<int>({1, 2, 3, 4, 5, 6}), "overlapping with duplicates");
    check(unionSorted({}, {}).empty(), "both empty");
    check(unionSorted({1, 1, 2}, {}) == std::vector<int>({1, 2}), "second empty");
    check(unionSorted({}, {3, 3}) == std::vector<int>({3}), "first empty");
    check(unionSorted({1, 2}, {5, 6}) == std::vector<int>({1, 2, 5, 6}), "disjoint");
    check(unionSorted({4, 4, 4}, {4, 4}) == std::vector<int>({4}), "all identical");
    check(unionSorted({-3, -1, 0}, {-2, -1, 7}) == std::vector<int>({-3, -2, -1, 0, 7}), "negatives");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
