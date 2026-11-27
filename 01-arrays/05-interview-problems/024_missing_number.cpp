/*
 * 024 - Missing number
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: A vector of n distinct integers all lie in the range [0, n]. Exactly one number from that range is missing; return it.
 * Constraints: 0 <= n <= 10^5; values distinct and within [0, n].
 * Examples:
 *   {3, 0, 1} -> 2
 *   {0, 1} -> 2
 *   {1} -> 0
 *
 * Approach:
 *   The numbers 0..n have a known sum: n(n+1)/2.
 *   Our vector holds all of them except one, so (expected sum) - (actual sum) is exactly the missing number.
 *   Use long long: n(n+1)/2 reaches about 5*10^9 for n = 10^5, which overflows int.
 *   Alternative with no overflow worry: XOR all indices and values (see 026).
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 024_missing_number.cpp -o 024_missing_number
 *   ./024_missing_number      (Windows PowerShell: .\024_missing_number.exe)
 */
#include <iostream>
#include <string>
#include <vector>

int missingNumber(const std::vector<int>& a) {
    const long long n = static_cast<long long>(a.size());
    const long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;
    for (int value : a) actualSum += value;
    return static_cast<int>(expectedSum - actualSum);
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
    check(missingNumber({}) == 0, "empty vector: range is just {0}");
    check(missingNumber({0}) == 1, "n = 1, missing 1");
    check(missingNumber({1}) == 0, "n = 1, missing 0");
    check(missingNumber({3, 0, 1}) == 2, "classic");
    check(missingNumber({0, 1}) == 2, "missing the maximum");
    check(missingNumber({1, 2, 3}) == 0, "missing zero");
    check(missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) == 8, "unsorted, larger");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
