/*
 * 021 - Last occurrence of a value (binary search)
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: In a SORTED vector, return the index of the LAST element equal to `target`, or -1.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing; duplicates allowed. Required: O(log n).
 * Examples:
 *   {1, 2, 2, 2, 3}, target 2 -> 3
 *
 * Approach:
 *   Binary search where a match is a candidate.
 *   On a match record mid and set left = mid + 1 to look for a later match.
 *   Return the last recorded candidate.
 *
 * Time complexity : O(log n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 021_last_occurrence.cpp -o 021_last_occurrence
 *   ./021_last_occurrence      (Windows PowerShell: .\021_last_occurrence.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Same as firstOccurrence, but after a match we look to the RIGHT for a later one.
int lastOccurrence(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    int answer = -1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] == target) {
            answer = mid;
            left = mid + 1;
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
            for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
                if (a[i] == target) { expected = i; break; }
            }
            check(lastOccurrence(a, target) == expected, "target " + std::to_string(target) + " in size " + std::to_string(a.size()));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
