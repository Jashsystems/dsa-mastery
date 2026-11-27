/*
 * 012 - Rotate an array by k positions (reversal algorithm)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Rotate a vector right (or left) by k positions in place, in O(n) time and O(1) extra space.
 * Constraints: 0 <= n <= 10^5; 0 <= k <= 10^9 (k may be larger than n).
 * Examples:
 *   {1,2,3,4,5}, k=2, right -> {4,5,1,2,3}
 *   {1,2,3,4,5}, k=2, left -> {3,4,5,1,2}
 *
 * Approach:
 *   Rotating by n positions changes nothing, so first reduce: k = k % n.
 *   Right rotation by k = reverse everything, then reverse the first k elements, then reverse the remaining n-k.
 *   Why it works: reversing everything sends the last k elements to the front but backwards; the two partial reversals put each block back in its original internal order.
 *   Left rotation by k = reverse the first k, reverse the rest, then reverse everything.
 *
 * Time complexity : O(n) - every element is touched a constant number of times
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 012_rotate_by_k.cpp -o 012_rotate_by_k
 *   ./012_rotate_by_k      (Windows PowerShell: .\012_rotate_by_k.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   a.begin() + shift   an ITERATOR k steps after the first element. Iterators are "positions";
 *                       std::reverse(first, last) reverses the half-open range [first, last).
 *   Half-open range     [first, last) includes first but excludes last, so reversing
 *                       [a.begin(), a.begin()+0) is a harmless no-op when shift == 0.
 */
void rotateRight(std::vector<int>& a, int k) {
    if (a.empty()) return;
    const int shift = k % static_cast<int>(a.size());
    std::reverse(a.begin(), a.end());
    std::reverse(a.begin(), a.begin() + shift);
    std::reverse(a.begin() + shift, a.end());
}

void rotateLeft(std::vector<int>& a, int k) {
    if (a.empty()) return;
    const int shift = k % static_cast<int>(a.size());
    std::reverse(a.begin(), a.begin() + shift);
    std::reverse(a.begin() + shift, a.end());
    std::reverse(a.begin(), a.end());
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
    // Expected result from the index formula: with a right rotation by k, element i lands at (i + k) % n.
    for (int n = 1; n <= 7; ++n) {
        for (int k = 0; k <= 2 * n + 1; ++k) {
            std::vector<int> original(n);
            for (int i = 0; i < n; ++i) original[i] = i * 10 + 3;

            std::vector<int> expectedRight(n), expectedLeft(n);
            for (int i = 0; i < n; ++i) {
                expectedRight[(i + k) % n] = original[i];
                expectedLeft[((i - k) % n + n) % n] = original[i];
            }
            std::vector<int> right = original, left = original;
            rotateRight(right, k);
            rotateLeft(left, k);
            const std::string tag = " (n=" + std::to_string(n) + ", k=" + std::to_string(k) + ")";
            check(right == expectedRight, "rotateRight" + tag);
            check(left == expectedLeft, "rotateLeft" + tag);
        }
    }
    std::vector<int> empty;
    rotateRight(empty, 5);
    rotateLeft(empty, 5);
    check(empty.empty(), "empty vector with k > 0");
    std::vector<int> big = {1, 2, 3};
    rotateRight(big, 1000000000);   // 10^9 % 3 == 1
    check(big == std::vector<int>({3, 1, 2}), "huge k");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
