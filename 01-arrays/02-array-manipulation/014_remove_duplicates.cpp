/*
 * 014 - Remove duplicates from a sorted array (in place)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Given a SORTED vector, keep one copy of each value in the first k positions and return k. The contents after position k do not matter.
 * Constraints: 0 <= n <= 10^5; array sorted in non-decreasing order.
 * Examples:
 *   {1, 1, 2, 2, 2, 3} -> k = 3, first three elements {1, 2, 3}
 *
 * Approach:
 *   Because the array is sorted, equal values are adjacent, so a value is new exactly when it differs from the last value we kept.
 *   Slow pointer `write` marks the end of the unique prefix; fast pointer `read` scans ahead.
 *   If a[read] != a[write-1], copy it to a[write] and advance write. Return write.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 014_remove_duplicates.cpp -o 014_remove_duplicates
 *   ./014_remove_duplicates      (Windows PowerShell: .\014_remove_duplicates.exe)
 */
#include <iostream>
#include <string>
#include <vector>

int removeDuplicatesSorted(std::vector<int>& a) {
    if (a.empty()) return 0;
    const int n = static_cast<int>(a.size());
    int write = 1;                               // a[0] is always unique; a[0..write-1] is the unique prefix
    for (int read = 1; read < n; ++read) {
        if (a[read] != a[write - 1]) {           // differs from the last kept value => new value
            a[write] = a[read];
            ++write;
        }
    }
    return write;
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
    auto run = [](std::vector<int> v, const std::vector<int>& expectedPrefix, const std::string& label) {
        const int k = removeDuplicatesSorted(v);
        check(k == static_cast<int>(expectedPrefix.size()), label + " (length)");
        check(std::vector<int>(v.begin(), v.begin() + k) == expectedPrefix, label + " (prefix)");
    };
    run({}, {}, "empty");
    run({4}, {4}, "single");
    run({1, 1, 2, 2, 2, 3}, {1, 2, 3}, "classic");
    run({7, 7, 7, 7}, {7}, "all identical");
    run({1, 2, 3, 4}, {1, 2, 3, 4}, "no duplicates");
    run({-3, -3, -1, 0, 0, 5}, {-3, -1, 0, 5}, "negatives and zero");
    run({1, 2, 2}, {1, 2}, "duplicate at the end");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
