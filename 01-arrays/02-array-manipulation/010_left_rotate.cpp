/*
 * 010 - Left rotate by one position
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Move every element one position to the left; the first element wraps around to the end.
 * Constraints: 0 <= n <= 10^5. Must be done in place.
 * Examples:
 *   {1, 2, 3, 4, 5} -> {2, 3, 4, 5, 1}
 *
 * Approach:
 *   Save a[0] in a temporary variable - it is about to be overwritten.
 *   Shift: a[i-1] = a[i] for i = 1..n-1 (left to right, so nothing is overwritten before it is copied).
 *   Place the saved value into the last slot.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 010_left_rotate.cpp -o 010_left_rotate
 *   ./010_left_rotate      (Windows PowerShell: .\010_left_rotate.exe)
 */
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   a.back()          reference to the LAST element (same as a[a.size()-1]); undefined if empty.
 *   std::size_t       the unsigned type returned by size(); fine as a loop variable when we only
 *                     compare it with size() and never subtract from it.
 */
void leftRotateByOne(std::vector<int>& a) {
    if (a.size() < 2) return;               // nothing to do for empty / single-element vectors
    const int first = a[0];
    for (std::size_t i = 1; i < a.size(); ++i) {
        a[i - 1] = a[i];
    }
    a.back() = first;
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
    std::vector<int> a;
    leftRotateByOne(a);
    check(a.empty(), "empty stays empty");
    a = {9};
    leftRotateByOne(a);
    check(a == std::vector<int>({9}), "single element");
    a = {1, 2, 3, 4, 5};
    leftRotateByOne(a);
    check(a == std::vector<int>({2, 3, 4, 5, 1}), "basic");
    a = {1, 1, 2};
    leftRotateByOne(a);
    check(a == std::vector<int>({1, 2, 1}), "duplicates");
    a = {-1, 0};
    leftRotateByOne(a);
    check(a == std::vector<int>({0, -1}), "two elements");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
