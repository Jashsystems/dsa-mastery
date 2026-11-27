/*
 * 020 - First occurrence of a value (binary search)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: In a SORTED vector, return the index of the FIRST element equal to `target`, or -1.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing; duplicates allowed.
 * Examples:
 *   {1, 2, 2, 2, 3}, target 2 -> 1
 *
 * Approach:
 *   Run binary search, but a match is only a CANDIDATE: store it and keep searching the left half for an earlier one.
 *   When a[mid] == target: answer = mid; right = mid - 1.
 *   The loop ends when the range is empty; `answer` holds the leftmost match found (or -1).
 *
 * Time complexity : O(log n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 020_first_occurrence.cpp -o 020_first_occurrence
 *   ./020_first_occurrence      (Windows PowerShell: .\020_first_occurrence.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int firstOccurrence(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    int answer = -1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] == target) {
            answer = mid;          // candidate; an earlier one may exist
            right = mid - 1;
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
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
            int expected = -1;
            for (int i = 0; i < static_cast<int>(a.size()); ++i) {
                if (a[i] == target) { expected = i; break; }
            }
            check(firstOccurrence(a, target) == expected, "target " + std::to_string(target) + " in size " + std::to_string(a.size()));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
