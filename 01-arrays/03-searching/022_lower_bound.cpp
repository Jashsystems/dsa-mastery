/*
 * 022 - Lower bound
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: In a SORTED vector, return the index of the first element that is >= target. Return n if every element is smaller.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing.
 * Examples:
 *   {1, 3, 3, 5}, target 3 -> 1
 *   {1, 3, 3, 5}, target 4 -> 3
 *   {1, 3, 3, 5}, target 9 -> 4
 *
 * Approach:
 *   Search the HALF-OPEN range [left, right), initially [0, n). The answer is always inside [left, right] (right = n is allowed as "none").
 *   If a[mid] < target, mid and everything before it are too small: left = mid + 1.
 *   Otherwise a[mid] >= target, so mid could be the answer: right = mid (keep it, do not skip it).
 *   When left == right the range has collapsed to the single answer position.
 *   This template is the most reusable form of binary search: first index where a condition becomes true.
 *
 * Time complexity : O(log n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 022_lower_bound.cpp -o 022_lower_bound
 *   ./022_lower_bound      (Windows PowerShell: .\022_lower_bound.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::lower_bound(a.begin(), a.end(), x)   library version; returns an iterator to the first
 *                                             element >= x (or a.end()). Requires a sorted range.
 *                                             Subtract a.begin() to get the index.
 */
int lowerBound(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size());       // note: n, not n - 1
    while (left < right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
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
    const std::vector<std::vector<int>> cases = {
        {}, {5}, {1, 2, 3, 4, 5}, {1, 1, 1, 1}, {1, 2, 2, 2, 3}, {-3, -3, 0, 0, 7}, {2, 4, 6, 8}};
    for (const std::vector<int>& a : cases) {
        for (int target = -5; target <= 9; ++target) {
            const int expected = static_cast<int>(std::lower_bound(a.begin(), a.end(), target) - a.begin());
            check(lowerBound(a, target) == expected, "target " + std::to_string(target) + " in size " + std::to_string(a.size()));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
