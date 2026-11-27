/*
 * 033 - Longest subarray with sum K
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Return the LENGTH of the longest contiguous subarray whose sum is exactly k, or 0 if none exists. The array may contain negative numbers and zeros.
 * Constraints: 0 <= n <= 2*10^5; |a[i]| <= 10^4; |k| <= 10^9.
 * Examples:
 *   {1, -1, 5, -2, 3}, k = 3 -> 4
 *   {-2, -1, 2, 1}, k = 1 -> 2
 *   {1, 2, 3}, k = 7 -> 0
 *
 * Approach:
 *   Same prefix-sum identity as 032: subarray (j, i] has sum k when prefix[j] == prefix[i] - k.
 *   To maximise the length i - j we want the SMALLEST (earliest) j, so store only the FIRST index at which each prefix value occurs.
 *   Seed with prefix 0 at index -1. Never overwrite an existing entry.
 *   For non-negative arrays a sliding window also works in O(1) space; negatives break it.
 *
 * Time complexity : O(n) average
 * Auxiliary space : O(n)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 033_longest_subarray_sum_k.cpp -o 033_longest_subarray_sum_k
 *   ./033_longest_subarray_sum_k      (Windows PowerShell: .\033_longest_subarray_sum_k.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int longestSubarrayWithSum(const std::vector<int>& a, long long k) {
    std::unordered_map<long long, int> firstIndex;    // prefix sum -> earliest index where it occurred
    firstIndex[0] = -1;                                // empty prefix sits "before" index 0
    long long prefix = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        prefix += a[i];
        const auto it = firstIndex.find(prefix - k);
        if (it != firstIndex.end()) best = std::max(best, i - it->second);
        if (firstIndex.find(prefix) == firstIndex.end()) firstIndex[prefix] = i;   // keep the earliest
    }
    return best;
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
    auto bruteForce = [](const std::vector<int>& a, long long k) {
        int best = 0;
        for (std::size_t i = 0; i < a.size(); ++i) {
            long long sum = 0;
            for (std::size_t j = i; j < a.size(); ++j) {
                sum += a[j];
                if (sum == k) best = std::max(best, static_cast<int>(j - i + 1));
            }
        }
        return best;
    };
    check(longestSubarrayWithSum({1, -1, 5, -2, 3}, 3) == 4, "sample");
    check(longestSubarrayWithSum({-2, -1, 2, 1}, 1) == 2, "negatives");
    check(longestSubarrayWithSum({1, 2, 3}, 6) == 3, "whole array");
    check(longestSubarrayWithSum({1, 2, 3}, 7) == 0, "no subarray");
    check(longestSubarrayWithSum({}, 0) == 0, "empty");
    check(longestSubarrayWithSum({0, 0, 0}, 0) == 3, "all zeros");
    check(longestSubarrayWithSum({5}, 5) == 1, "single match");
    const std::vector<std::vector<int>> cases = {{2, -2, 2, -2, 2}, {-1, -1, 1, 1}, {4, 4, 4, 4}, {1, 2, -3, 3}, {0, 1, 0, 1, 0}};
    for (std::size_t c = 0; c < cases.size(); ++c) {
        for (int k = -4; k <= 8; ++k) {
            check(longestSubarrayWithSum(cases[c], k) == bruteForce(cases[c], k), "brute force, case " + std::to_string(c) + " k=" + std::to_string(k));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
