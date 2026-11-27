/*
 * 008 - Sum of elements
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Return the sum of all elements of a vector.
 * Constraints: 0 <= n <= 10^5; |a[i]| <= 2^31 - 1, so the sum can exceed the range of int.
 *
 * Approach:
 *   Keep a running total, add each element once.
 *   Use long long for the total: 10^5 values near 2*10^9 sum to about 2*10^14, far beyond int (about 2.1*10^9).
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 008_sum_of_elements.cpp -o 008_sum_of_elements
 *   ./008_sum_of_elements      (Windows PowerShell: .\008_sum_of_elements.exe)
 */
#include <climits>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   long long          64-bit integer. Always use it for sums/products that could pass ~2*10^9.
 *   std::accumulate(a.begin(), a.end(), 0LL)
 *                      library "add everything up" (needs <numeric>). The 0LL start value is a
 *                      long long, which makes the whole sum long long. (A plain 0 would be an int
 *                      and could overflow.) Used in the tests to cross-check.
 */
long long sumOfElements(const std::vector<int>& a) {
    long long total = 0;
    for (int value : a) {
        total += value;      // value is promoted to long long before the addition
    }
    return total;
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
    check(sumOfElements({}) == 0, "empty");
    check(sumOfElements({5}) == 5, "single");
    check(sumOfElements({1, 2, 3, 4}) == 10, "positives");
    check(sumOfElements({-1, -2, -3}) == -6, "negatives");
    check(sumOfElements({5, -5, 7, -7}) == 0, "cancels to zero");
    check(sumOfElements({INT_MAX, INT_MAX}) == 2LL * INT_MAX, "would overflow an int");
    check(sumOfElements({INT_MIN, INT_MIN}) == 2LL * INT_MIN, "negative overflow check");
    const std::vector<int> v = {9, -4, 12, 0, 3};
    check(sumOfElements(v) == std::accumulate(v.begin(), v.end(), 0LL), "matches std::accumulate");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
