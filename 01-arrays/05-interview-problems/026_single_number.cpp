/*
 * 026 - Single number (XOR)
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Every element of the vector appears exactly twice except one, which appears once. Return that one.
 * Constraints: 1 <= n <= 10^5, n odd; guaranteed to follow the rule above.
 * Examples:
 *   {4, 1, 2, 1, 2} -> 4
 *   {7} -> 7
 *
 * Approach:
 *   XOR (^) compares two numbers bit by bit: equal bits give 0, different bits give 1.
 *   Three facts: x ^ x = 0, x ^ 0 = x, and XOR is commutative/associative (order does not matter).
 *   XOR-ing the whole array cancels every pair to 0, leaving only the single number.
 *   Without XOR you would need a frequency map (O(n) extra space) or sorting (O(n log n) time).
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 026_single_number.cpp -o 026_single_number
 *   ./026_single_number      (Windows PowerShell: .\026_single_number.exe)
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

int singleNumber(const std::vector<int>& a) {
    int result = 0;
    for (int value : a) {
        result ^= value;       // pairs cancel: (x ^ x) == 0
    }
    return result;
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
    check(singleNumber({7}) == 7, "single element");
    check(singleNumber({2, 2, 1}) == 1, "unique at the end");
    check(singleNumber({4, 1, 2, 1, 2}) == 4, "unique at the start");
    check(singleNumber({1, 5, 1}) == 5, "unique in the middle");
    check(singleNumber({-1, -1, -2}) == -2, "negatives");
    check(singleNumber({0, 3, 3}) == 0, "the single number is zero");
    check(singleNumber({INT_MAX, 8, INT_MAX}) == 8, "boundary value pair");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
