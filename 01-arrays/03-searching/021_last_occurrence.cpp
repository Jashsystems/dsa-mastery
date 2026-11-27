/*
 * 021 - Last occurrence of a value (binary search)
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: In a SORTED vector, return the index of the LAST element equal to `target`, or -1.
 * Constraints: 0 <= n <= 10^5; sorted non-decreasing; duplicates allowed. Required: O(log n).
 * Examples:
 *   {1, 2, 2, 2, 3}, target 2 -> 3
 *
 * Target complexity: time O(log n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 021_last_occurrence.cpp -o 021_last_occurrence
 *   ./021_last_occurrence      (Windows PowerShell: .\021_last_occurrence.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Study 020_first_occurrence.cpp. What must change when a match is found?
int lastOccurrence(const std::vector<int>& a, int target) {
    (void)a;       // delete these two lines once you use the parameters
    (void)target;
    // TODO: your implementation (binary search - a linear scan will not meet the target complexity)
    return -2;
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
