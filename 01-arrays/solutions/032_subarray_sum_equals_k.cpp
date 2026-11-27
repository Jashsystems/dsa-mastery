/*
 * 032 - Subarray sum equals K
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Count the contiguous subarrays whose elements sum to exactly k. The array may contain NEGATIVE numbers and zeros.
 * Constraints: 0 <= n <= 2*10^5; |a[i]| <= 10^4; |k| <= 10^9. The answer fits in a 64-bit integer.
 * Examples:
 *   {1, 1, 1}, k = 2 -> 2
 *   {1, -1, 0}, k = 0 -> 3
 *
 * Approach:
 *   Let prefix[i] be the sum of the first i elements. Subarray (j, i] has sum prefix[i] - prefix[j].
 *   We need prefix[i] - prefix[j] == k, i.e. prefix[j] == prefix[i] - k for some EARLIER j.
 *   Keep a hash map from prefix value to how many times it has occurred; seed it with prefix 0 occurring once.
 *   For every i add map[prefix[i] - k] to the answer, then record prefix[i]. Works with negatives (a sliding window would not).
 *
 * Time complexity : O(n) average
 * Auxiliary space : O(n)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 032_subarray_sum_equals_k.cpp -o 032_subarray_sum_equals_k
 *   ./032_subarray_sum_equals_k      (Windows PowerShell: .\032_subarray_sum_equals_k.exe)
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

long long countSubarraysWithSum(const std::vector<int>& a, long long k) {
    std::unordered_map<long long, long long> seen;    // prefix sum -> how many times it occurred
    seen[0] = 1;                                       // the empty prefix
    long long prefix = 0;
    long long count = 0;
    for (int value : a) {
        prefix += value;
        const auto it = seen.find(prefix - k);
        if (it != seen.end()) count += it->second;
        ++seen[prefix];
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
    auto bruteForce = [](const std::vector<int>& a, long long k) {
        long long count = 0;
        for (std::size_t i = 0; i < a.size(); ++i) {
            long long sum = 0;
            for (std::size_t j = i; j < a.size(); ++j) {
                sum += a[j];
                if (sum == k) ++count;
            }
        }
        return count;
    };
    check(countSubarraysWithSum({1, 1, 1}, 2) == 2, "sample");
    check(countSubarraysWithSum({1, 2, 3}, 3) == 2, "[1,2] and [3]");
    check(countSubarraysWithSum({}, 0) == 0, "empty");
    check(countSubarraysWithSum({0, 0, 0}, 0) == 6, "all zeros: every subarray");
    check(countSubarraysWithSum({1, -1, 0}, 0) == 3, "negatives and zero");
    check(countSubarraysWithSum({3, 4, 7, 2, -3, 1, 4, 2}, 7) == 4, "mixed signs");
    check(countSubarraysWithSum({5}, 5) == 1, "single element match");
    check(countSubarraysWithSum({5}, 6) == 0, "single element miss");
    const std::vector<std::vector<int>> cases = {{2, -2, 2, -2, 2}, {-1, -1, 1, 1}, {4, 4, 4, 4}, {1, 2, -3, 3}};
    for (std::size_t c = 0; c < cases.size(); ++c) {
        for (int k = -4; k <= 8; ++k) {
            check(countSubarraysWithSum(cases[c], k) == bruteForce(cases[c], k), "brute force, case " + std::to_string(c) + " k=" + std::to_string(k));
        }
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
