/*
 * 015 - Remove all occurrences of a value (in place)
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Remove every element equal to `value` from the vector IN PLACE, keeping the remaining elements in their original relative order. Return the new length k; the first k positions must hold the kept elements.
 * Constraints: 0 <= n <= 10^5; the array is NOT necessarily sorted.
 * Examples:
 *   {3, 2, 2, 3}, value 3 -> k = 2, first two elements {2, 2}
 *   {0,1,2,2,3,0,4,2}, value 2 -> k = 5, {0,1,3,0,4}
 *
 * Approach:
 *   Slow pointer = where the next kept element goes; fast pointer = scanner.
 *   Keep a[read] only if it differs from value.
 *   Return the slow pointer: it equals the number of kept elements.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 015_remove_element.cpp -o 015_remove_element
 *   ./015_remove_element      (Windows PowerShell: .\015_remove_element.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// `write` is the end of the kept prefix; `read` scans. Copy a[read] only when it must be kept.
int removeElement(std::vector<int>& a, int value) {
    const int n = static_cast<int>(a.size());
    int write = 0;
    for (int read = 0; read < n; ++read) {
        if (a[read] != value) {
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
    auto run = [](std::vector<int> v, int value, const std::vector<int>& expectedPrefix, const std::string& label) {
        const int k = removeElement(v, value);
        check(k == static_cast<int>(expectedPrefix.size()), label + " (length)");
        if (k == static_cast<int>(expectedPrefix.size())) {
            check(std::vector<int>(v.begin(), v.begin() + k) == expectedPrefix, label + " (prefix, order preserved)");
        }
    };
    run({}, 5, {}, "empty");
    run({3, 2, 2, 3}, 3, {2, 2}, "ends removed");
    run({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 3, 0, 4}, "scattered");
    run({1, 2, 3}, 4, {1, 2, 3}, "value absent");
    run({6, 6, 6}, 6, {}, "everything removed");
    run({-1, 5, -1}, -1, {5}, "negative value");
    run({9}, 9, {}, "single removed");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
