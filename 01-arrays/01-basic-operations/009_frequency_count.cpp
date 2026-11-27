/*
 * 009 - Frequency count
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Count how many times each distinct value occurs in a vector.
 * Constraints: 0 <= n <= 10^5. Version 1 requires 0 <= a[i] <= maxValue (small range). Version 2 accepts any ints.
 *
 * Approach:
 *   Version 1 (counting array): count[v] stores how often v appears; the value itself is the index. O(1) update.
 *   Version 2 (std::map): a sorted dictionary from value to count, for negative or huge values. O(log d) per update, d = distinct values.
 *   Both visit each element once; no nested loop comparing every pair (which would be O(n^2)).
 *
 * Time complexity : counting array O(n + maxValue); map O(n log d)
 * Auxiliary space : O(maxValue) / O(d)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 009_frequency_count.cpp -o 009_frequency_count
 *   ./009_frequency_count      (Windows PowerShell: .\009_frequency_count.exe)
 */
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::vector<int> count(size, 0)   a vector of `size` elements, all initialised to 0.
 *   std::map<int,int>                 key -> value dictionary, kept sorted by key.
 *   count[v] on a map                 if key v is missing it is created with value 0 first,
 *                                     so ++count[v] works for both new and existing keys.
 */

// Precondition: 0 <= every a[i] <= maxValue.
std::vector<int> frequencyArray(const std::vector<int>& a, int maxValue) {
    std::vector<int> count(maxValue + 1, 0);
    for (int value : a) {
        ++count[value];
    }
    return count;
}

std::map<int, int> frequencyMap(const std::vector<int>& a) {
    std::map<int, int> count;
    for (int value : a) {
        ++count[value];
    }
    return count;
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
    check(frequencyArray({1, 2, 2, 3, 3, 3}, 3) == std::vector<int>({0, 1, 2, 3}), "counting array basic");
    check(frequencyArray({}, 0) == std::vector<int>({0}), "counting array on empty input");
    check(frequencyArray({0, 0, 0}, 2) == std::vector<int>({3, 0, 0}), "all zeros");
    check(frequencyArray({4}, 4) == std::vector<int>({0, 0, 0, 0, 1}), "single element at upper bound");

    check(frequencyMap({}).empty(), "map on empty input");
    check(frequencyMap({-1, -1, 5}) == (std::map<int, int>{{-1, 2}, {5, 1}}), "map with negatives");
    check(frequencyMap({7, 7, 7, 7}) == (std::map<int, int>{{7, 4}}), "all identical");
    check(frequencyMap({INT_MIN, INT_MAX, INT_MAX}) == (std::map<int, int>{{INT_MIN, 1}, {INT_MAX, 2}}), "boundaries");

    for (const auto& entry : frequencyMap({3, 1, 3, 2, 3})) {   // entry.first = key, entry.second = count
        std::cout << entry.first << " appears " << entry.second << " time(s)\n";
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
