/*
 * 031 - Maximum subarray sum (Kadane's algorithm)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Return the largest possible sum of a NON-EMPTY contiguous subarray.
 * Constraints: 1 <= n <= 10^5; |a[i]| <= 10^4 (we use long long anyway).
 * Examples:
 *   {-2, 1, -3, 4, -1, 2, 1, -5, 4} -> 6 (subarray {4, -1, 2, 1})
 *   {-3, -1, -2} -> -1
 *
 * Approach:
 *   Brute force: try every start and end - O(n^2) with a running sum (O(n^3) if you re-sum each time).
 *   Key question at each index i: what is the best sum of a subarray that ENDS at i?
 *   Either extend the best subarray ending at i-1 (bestEndingHere + a[i]) or start fresh at a[i]. Take the larger. A negative running sum is never worth carrying.
 *   The answer is the maximum of bestEndingHere over all i. Initialising from a[0] (not 0) makes all-negative arrays work.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 031_maximum_subarray_sum.cpp -o 031_maximum_subarray_sum
 *   ./031_maximum_subarray_sum      (Windows PowerShell: .\031_maximum_subarray_sum.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Precondition: a is non-empty.
long long maxSubarraySum(const std::vector<int>& a) {
    long long bestEndingHere = a[0];
    long long bestOverall = a[0];
    for (std::size_t i = 1; i < a.size(); ++i) {
        bestEndingHere = std::max<long long>(a[i], bestEndingHere + a[i]);
        bestOverall = std::max(bestOverall, bestEndingHere);
    }
    return bestOverall;
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
    auto bruteForce = [](const std::vector<int>& a) {
        long long best = a[0];
        for (std::size_t i = 0; i < a.size(); ++i) {
            long long sum = 0;
            for (std::size_t j = i; j < a.size(); ++j) {
                sum += a[j];
                best = std::max(best, sum);
            }
        }
        return best;
    };
    check(maxSubarraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6, "classic");
    check(maxSubarraySum({1}) == 1, "single positive");
    check(maxSubarraySum({-1}) == -1, "single negative");
    check(maxSubarraySum({-3, -1, -2}) == -1, "all negative");
    check(maxSubarraySum({1, 2, 3, 4}) == 10, "all positive: whole array");
    check(maxSubarraySum({5, -9, 6}) == 6, "restart after a bad prefix");
    check(maxSubarraySum({0, 0, 0}) == 0, "all zeros");
    const std::vector<std::vector<int>> cases = {
        {3, -4, 5, -1, 2, -6, 7}, {-5, -4, -3, -2, -1}, {2, -1, 2, -1, 2}, {8, -20, 5, 5}, {-1, 4, -1, 4, -1}};
    for (std::size_t c = 0; c < cases.size(); ++c) {
        check(maxSubarraySum(cases[c]) == bruteForce(cases[c]), "matches brute force, case " + std::to_string(c));
    }

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
