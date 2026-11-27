/*
 * 013 - Move zeroes to the end
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Move all 0s to the end of the vector while keeping the relative order of the non-zero elements. In place.
 * Constraints: 0 <= n <= 10^5; any ints.
 * Examples:
 *   {0, 1, 0, 3, 12} -> {1, 3, 12, 0, 0}
 *
 * Approach:
 *   Two pointers moving in the same direction: `read` scans every element, `write` marks where the next non-zero belongs.
 *   Invariant: a[0..write-1] contains exactly the non-zero elements seen so far, in order; everything between write and read is zero.
 *   When a[read] != 0, swap it into position `write` and advance write. (If write == read the swap is a harmless self-swap.)
 *
 * Time complexity : O(n) - single pass
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 013_move_zeroes.cpp -o 013_move_zeroes
 *   ./013_move_zeroes      (Windows PowerShell: .\013_move_zeroes.exe)
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void moveZeroes(std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    int write = 0;                               // next slot for a non-zero element
    for (int read = 0; read < n; ++read) {
        if (a[read] != 0) {
            std::swap(a[write], a[read]);
            ++write;
        }
    }
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
    std::vector<int> a;
    moveZeroes(a);
    check(a.empty(), "empty");
    a = {0};
    moveZeroes(a);
    check(a == std::vector<int>({0}), "single zero");
    a = {5};
    moveZeroes(a);
    check(a == std::vector<int>({5}), "single non-zero");
    a = {0, 1, 0, 3, 12};
    moveZeroes(a);
    check(a == std::vector<int>({1, 3, 12, 0, 0}), "classic example");
    a = {0, 0, 0};
    moveZeroes(a);
    check(a == std::vector<int>({0, 0, 0}), "all zeros");
    a = {1, 2, 3};
    moveZeroes(a);
    check(a == std::vector<int>({1, 2, 3}), "no zeros");
    a = {1, 2, 0, 0};
    moveZeroes(a);
    check(a == std::vector<int>({1, 2, 0, 0}), "zeros already at the end");
    a = {0, 0, -1, 2};
    moveZeroes(a);
    check(a == std::vector<int>({-1, 2, 0, 0}), "zeros at the front, negatives");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
