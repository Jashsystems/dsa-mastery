/*
 * 027 - Union of two sorted arrays
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Given two vectors sorted in non-decreasing order (duplicates allowed), return a sorted vector of the DISTINCT values that appear in at least one of them.
 * Constraints: 0 <= n, m <= 10^5; both inputs sorted.
 * Examples:
 *   {1,1,2,3,4,5}, {2,3,4,4,5,6} -> {1,2,3,4,5,6}
 *
 * Approach:
 *   Two-pointer merge.
 *   Append the smaller current element unless it equals the last appended value.
 *   Drain whichever array is left.
 *
 * Time complexity : O(n + m)
 * Auxiliary space : O(1) beyond the output
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 027_union_of_arrays.cpp -o 027_union_of_arrays
 *   ./027_union_of_arrays      (Windows PowerShell: .\027_union_of_arrays.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Merge like 017, but only append a value if it differs from the last value appended.
std::vector<int> unionSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    std::size_t i = 0, j = 0;
    auto appendIfNew = [&result](int value) {
        if (result.empty() || result.back() != value) result.push_back(value);
    };
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) appendIfNew(a[i++]);
        else appendIfNew(b[j++]);
    }
    while (i < a.size()) appendIfNew(a[i++]);
    while (j < b.size()) appendIfNew(b[j++]);
    return result;
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
