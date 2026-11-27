/*
 * 007 - Check whether an array is sorted
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Return true if a[0] <= a[1] <= ... <= a[n-1] (non-decreasing order).
 * Constraints: 0 <= n <= 10^5; any ints. Empty and single-element arrays count as sorted.
 *
 * Approach:
 *   An array is sorted exactly when EVERY adjacent pair is in order - no need to compare non-neighbours.
 *   Scan i = 1..n-1; the first pair with a[i-1] > a[i] proves "not sorted" and we stop early.
 *   If the scan finishes, no pair was out of order, so the array is sorted.
 *
 * Time complexity : O(n) worst case, O(1) best case (early exit)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 007_check_sorted.cpp -o 007_check_sorted
 *   ./007_check_sorted      (Windows PowerShell: .\007_check_sorted.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Why adjacent pairs suffice: "<=" is transitive. a[0]<=a[1] and a[1]<=a[2] imply a[0]<=a[2], etc.
bool isSortedNonDecreasing(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) return false;   // found an inversion
    }
    return true;                              // also reached for n = 0 and n = 1
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
    check(isSortedNonDecreasing({}), "empty");
    check(isSortedNonDecreasing({4}), "single");
    check(isSortedNonDecreasing({1, 2, 3, 4}), "strictly increasing");
    check(isSortedNonDecreasing({1, 2, 2, 3}), "duplicates allowed");
    check(isSortedNonDecreasing({6, 6, 6}), "all identical");
    check(isSortedNonDecreasing({-5, -1, 0, 3}), "negatives");
    check(!isSortedNonDecreasing({3, 2, 1}), "reverse sorted");
    check(!isSortedNonDecreasing({1, 3, 2}), "inversion at the end");
    check(!isSortedNonDecreasing({2, 1, 3, 4}), "inversion at the start");
    check(!isSortedNonDecreasing({1, 2, 3, 4, 3}), "last element too small");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
