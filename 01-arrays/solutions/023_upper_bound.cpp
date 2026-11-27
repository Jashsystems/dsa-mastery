/*
 * 023 - Upper bound
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: In a SORTED vector, return the index of the first element that is STRICTLY GREATER than target. Return n if none.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing. Required: O(log n).
 * Examples:
 *   {1, 3, 3, 5}, target 3 -> 3
 *   {1, 3, 3, 5}, target 5 -> 4
 *
 * Approach:
 *   Same half-open template as lower bound.
 *   Move left past every element <= target.
 *   The collapsed position is the first element > target.
 *
 * Time complexity : O(log n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 023_upper_bound.cpp -o 023_upper_bound
 *   ./023_upper_bound      (Windows PowerShell: .\023_upper_bound.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// "first index where a[i] > target": elements <= target are too small to be the answer.
int upperBound(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size());
    while (left < right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] <= target) left = mid + 1;
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
            const int expected = static_cast<int>(std::upper_bound(a.begin(), a.end(), target) - a.begin());
            check(upperBound(a, target) == expected, "target " + std::to_string(target) + " in size " + std::to_string(a.size()));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
