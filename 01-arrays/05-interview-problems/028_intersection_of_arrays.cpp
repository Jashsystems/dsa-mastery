/*
 * 028 - Intersection of two sorted arrays
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: Given two sorted vectors, return a sorted vector of their common elements. A value occurring x times in one and y times in the other appears min(x, y) times in the result.
 * Constraints: 0 <= n, m <= 10^5; both inputs sorted.
 * Examples:
 *   {1,2,2,3}, {2,2,4} -> {2,2}
 *   {1,1,1}, {1,1} -> {1,1}
 *
 * Target complexity: time O(n + m), auxiliary space O(1) beyond the output
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 028_intersection_of_arrays.cpp -o 028_intersection_of_arrays
 *   ./028_intersection_of_arrays      (Windows PowerShell: .\028_intersection_of_arrays.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Category hint: two pointers; decide what to do with each of the three outcomes a[i] <, ==, > b[j].
std::vector<int> intersectionSorted(const std::vector<int>& a, const std::vector<int>& b) {
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
