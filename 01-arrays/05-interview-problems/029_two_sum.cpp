/*
 * 029 - Two Sum
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Return the indices of two DIFFERENT elements whose sum equals target. Return an empty vector if no such pair exists.
 * Constraints: 0 <= n <= 10^5; |a[i]| <= 10^9 (we still guard against int overflow); at most one answer needs to be returned; any valid pair is accepted.
 * Examples:
 *   {2, 7, 11, 15}, target 9 -> {0, 1}
 *   {3, 3}, target 6 -> {0, 1}
 *
 * Approach:
 *   Brute force: test every pair - O(n^2) time, O(1) space.
 *   Better: for each element x we need target - x. Remember every earlier value in a hash map (value -> index).
 *   One pass: for a[i], look up the complement target - a[i] among EARLIER elements; if present we have the pair, otherwise record a[i].
 *   Checking before inserting guarantees we never pair an element with itself.
 *
 * Time complexity : O(n) average (hash lookups are O(1) on average)
 * Auxiliary space : O(n) - the map
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 029_two_sum.cpp -o 029_two_sum
 *   ./029_two_sum      (Windows PowerShell: .\029_two_sum.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::unordered_map<K, V>   hash table: average O(1) insert and lookup (needs <unordered_map>).
 *   seen.find(key)             returns an iterator; it equals seen.end() when the key is absent.
 *   it->first / it->second     the key and the value stored at iterator `it`.
 *   auto                       lets the compiler deduce the (long) iterator type for us.
 *   return {x, y};             builds a std::vector<int> {x, y} for the return value.
 * We use long long keys because target - a[i] can leave the int range (e.g. -2 - INT_MAX).
 */
std::vector<int> twoSum(const std::vector<int>& a, int target) {
    std::unordered_map<long long, int> seen;               // value -> index where it was seen
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        const long long complement = static_cast<long long>(target) - a[i];
        const auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[a[i]] = i;
    }
    return {};
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
    auto isValidAnswer = [](const std::vector<int>& a, int target, const std::vector<int>& r) {
        if (r.size() != 2) return false;
        const int n = static_cast<int>(a.size());
        if (r[0] < 0 || r[1] < 0 || r[0] >= n || r[1] >= n || r[0] == r[1]) return false;
        return static_cast<long long>(a[r[0]]) + a[r[1]] == target;
    };
    check(isValidAnswer({2, 7, 11, 15}, 9, twoSum({2, 7, 11, 15}, 9)), "classic");
    check(isValidAnswer({3, 2, 4}, 6, twoSum({3, 2, 4}, 6)), "must not reuse the same element (3 + 3)");
    check(isValidAnswer({3, 3}, 6, twoSum({3, 3}, 6)), "equal values");
    check(isValidAnswer({-1, -2, -3, -4, -5}, -8, twoSum({-1, -2, -3, -4, -5}, -8)), "negatives");
    check(isValidAnswer({0, 4, 3, 0}, 0, twoSum({0, 4, 3, 0}, 0)), "two zeros");
    check(twoSum({1, 2, 3}, 7).empty(), "no pair");
    check(twoSum({5}, 10).empty(), "single element cannot pair with itself");
    check(twoSum({}, 0).empty(), "empty");
    check(twoSum({INT_MAX, INT_MAX}, -2).empty(), "int overflow would fake a match");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
