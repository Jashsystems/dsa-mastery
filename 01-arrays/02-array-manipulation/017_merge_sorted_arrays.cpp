/*
 * 017 - Merge two sorted arrays
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Given two vectors sorted in non-decreasing order, return one sorted vector containing all elements of both.
 * Constraints: 0 <= n, m <= 10^5; both inputs sorted; duplicates allowed (all kept).
 * Examples:
 *   {1, 3, 5}, {2, 3, 6} -> {1, 2, 3, 3, 5, 6}
 *
 * Approach:
 *   One pointer per array. At each step the smallest unused element overall is the smaller of a[i] and b[j].
 *   Take it, advance that pointer. Repeat while both arrays have elements left.
 *   When one array runs out, the rest of the other is already sorted - copy it over.
 *   Using <= when elements tie takes from `a` first, which keeps the merge stable.
 *
 * Time complexity : O(n + m)
 * Auxiliary space : O(n + m) for the output; O(1) extra beyond it
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 017_merge_sorted_arrays.cpp -o 017_merge_sorted_arrays
 *   ./017_merge_sorted_arrays      (Windows PowerShell: .\017_merge_sorted_arrays.exe)
 */
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   merged.reserve(k)   asks the vector to allocate room for k elements up front (avoids repeated
 *                       reallocation). It does NOT change size().
 */
std::vector<int> mergeSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> merged;
    merged.reserve(a.size() + b.size());
    std::size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            ++i;
        } else {
            merged.push_back(b[j]);
            ++j;
        }
    }
    while (i < a.size()) { merged.push_back(a[i]); ++i; }   // leftovers of a
    while (j < b.size()) { merged.push_back(b[j]); ++j; }   // leftovers of b
    return merged;
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
    auto expectedMerge = [](std::vector<int> a, const std::vector<int>& b) {
        a.insert(a.end(), b.begin(), b.end());
        std::sort(a.begin(), a.end());
        return a;
    };
    const std::vector<std::vector<int>> inputs = {
        {}, {1}, {1, 3, 5}, {2, 3, 6}, {-4, -4, 0}, {7, 7, 7}, {1, 2, 3, 4, 5, 6}, {10}};
    for (std::size_t x = 0; x < inputs.size(); ++x) {
        for (std::size_t y = 0; y < inputs.size(); ++y) {
            check(mergeSorted(inputs[x], inputs[y]) == expectedMerge(inputs[x], inputs[y]),
                  "pair (" + std::to_string(x) + ", " + std::to_string(y) + ")");
        }
    }
    check(mergeSorted({1, 3, 5}, {2, 3, 6}) == std::vector<int>({1, 2, 3, 3, 5, 6}), "documented example");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
