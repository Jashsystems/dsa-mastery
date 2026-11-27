/*
 * 018 - Linear search
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Return the index of the first occurrence of `target`, or -1 if it is absent.
 * Constraints: 0 <= n <= 10^5; array NOT necessarily sorted.
 * Examples:
 *   {4, 8, 8, 1}, target 8 -> 1
 *   {4, 8}, target 5 -> -1
 *
 * Approach:
 *   Check elements from the left until one matches; return its index immediately.
 *   If the loop ends, every element was checked and none matched.
 *   This is the only option for unsorted data without extra preprocessing.
 *
 * Time complexity : O(n) worst case, O(1) best case
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 018_linear_search.cpp -o 018_linear_search
 *   ./018_linear_search      (Windows PowerShell: .\018_linear_search.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::find(a.begin(), a.end(), x)   returns an ITERATOR to the first element equal to x, or
 *                                      a.end() if none. Subtracting a.begin() turns it into an index.
 */
int linearSearch(const std::vector<int>& a, int target) {
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        if (a[i] == target) return i;
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
    const std::vector<std::vector<int>> cases = {{}, {5}, {4, 8, 8, 1}, {-3, 0, 3}, {2, 2, 2}};
    for (const std::vector<int>& a : cases) {
        for (int target = -4; target <= 9; ++target) {
            const auto it = std::find(a.begin(), a.end(), target);
            const int expected = (it == a.end()) ? -1 : static_cast<int>(it - a.begin());
            check(linearSearch(a, target) == expected, "target " + std::to_string(target) + " in size " + std::to_string(a.size()));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
