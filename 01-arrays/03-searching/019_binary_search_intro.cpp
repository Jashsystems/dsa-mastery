/*
 * 019 - Binary search (introduction)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: In a SORTED vector, return an index of `target`, or -1 if absent.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing. With duplicates, ANY matching index is acceptable.
 * Examples:
 *   {1, 3, 5, 7, 9}, target 7 -> 3
 *   {1, 3, 5, 7, 9}, target 4 -> -1
 *
 * Approach:
 *   Invariant: if target exists, it lies inside a[left..right].
 *   Look at the middle. If it equals target we are done. If a[mid] < target, everything at or before mid is too small: left = mid + 1. Otherwise right = mid - 1.
 *   Each step halves the candidate range, so at most about log2(n) + 1 steps. When left > right the range is empty: target is absent.
 *   mid = left + (right - left) / 2 avoids the overflow that (left + right) / 2 can cause for very large indices.
 *
 * Time complexity : O(log n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 019_binary_search_intro.cpp -o 019_binary_search_intro
 *   ./019_binary_search_intro      (Windows PowerShell: .\019_binary_search_intro.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int binarySearch(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;     // discard the left half including mid
        else right = mid - 1;                     // discard the right half including mid
    }
    return -1;
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
        {}, {5}, {1, 3, 5, 7, 9}, {1, 3, 5, 7, 9, 11}, {2, 2, 2, 2}, {-8, -3, 0, 4, 4, 10}};
    for (const std::vector<int>& a : cases) {
        for (int target = -10; target <= 12; ++target) {
            const int index = binarySearch(a, target);
            const bool exists = std::binary_search(a.begin(), a.end(), target);
            const std::string tag = "target " + std::to_string(target) + " in size " + std::to_string(a.size());
            if (exists) {
                check(index >= 0 && index < static_cast<int>(a.size()) && a[index] == target, "found " + tag);
            } else {
                check(index == -1, "absent " + tag);
            }
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
