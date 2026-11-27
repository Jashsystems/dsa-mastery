/*
 * 028 - Intersection of two sorted arrays
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Given two sorted vectors, return a sorted vector of their common elements. A value occurring x times in one and y times in the other appears min(x, y) times in the result.
 * Constraints: 0 <= n, m <= 10^5; both inputs sorted.
 * Examples:
 *   {1,2,2,3}, {2,2,4} -> {2,2}
 *   {1,1,1}, {1,1} -> {1,1}
 *
 * Approach:
 *   Advance the pointer at the smaller value (it cannot match anything further in the other array).
 *   On equality record it and advance both.
 *   Stop when either array ends.
 *
 * Time complexity : O(n + m)
 * Auxiliary space : O(1) beyond the output
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 028_intersection_of_arrays.cpp -o 028_intersection_of_arrays
 *   ./028_intersection_of_arrays      (Windows PowerShell: .\028_intersection_of_arrays.exe)
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> intersectionSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    std::size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ++i;                       // a[i] is too small to appear in b
        } else if (a[i] > b[j]) {
            ++j;
        } else {
            result.push_back(a[i]);    // match: consume one copy from each side
            ++i;
            ++j;
        }
    }
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
    check(intersectionSorted({1, 2, 2, 3}, {2, 2, 4}) == std::vector<int>({2, 2}), "multiplicity");
    check(intersectionSorted({1, 2, 3}, {4, 5}).empty(), "disjoint");
    check(intersectionSorted({1, 1, 1}, {1, 1}) == std::vector<int>({1, 1}), "min of counts");
    check(intersectionSorted({}, {1, 2}).empty(), "first empty");
    check(intersectionSorted({1, 2}, {}).empty(), "second empty");
    check(intersectionSorted({-2, -1, 0}, {-1, 0, 0, 3}) == std::vector<int>({-1, 0}), "negatives");
    check(intersectionSorted({5, 5}, {5, 5}) == std::vector<int>({5, 5}), "identical arrays");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
