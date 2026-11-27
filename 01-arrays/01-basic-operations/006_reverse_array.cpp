/*
 * 006 - Reverse an array in place
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Reverse the order of the elements of a vector without creating a second vector.
 * Constraints: 0 <= n <= 10^5; any ints.
 *
 * Approach:
 *   Two indices: left starts at the first element, right at the last.
 *   Swap a[left] and a[right], then move both inward. Stop when they meet or cross.
 *   The middle element of an odd-length array stays where it is.
 *
 * Time complexity : O(n) - n/2 swaps
 * Auxiliary space : O(1) - in place
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 006_reverse_array.cpp -o 006_reverse_array
 *   ./006_reverse_array      (Windows PowerShell: .\006_reverse_array.exe)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::vector<int>& a   NON-const reference: the function modifies the caller's vector.
 *   std::swap(x, y)       exchanges two values (needs <utility>).
 *   std::reverse(a.begin(), a.end())  library version of this exact function (needs <algorithm>);
 *                         a.begin()/a.end() mark "the first element" and "one past the last".
 *                         We use it ONLY in the tests, to cross-check our own implementation.
 */
void reverseArray(std::vector<int>& a) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;   // -1 for an empty vector, so the loop is skipped
    while (left < right) {
        std::swap(a[left], a[right]);
        ++left;
        --right;
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
    const std::vector<std::vector<int>> cases = {
        {}, {1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {-5, 0, 5, 5, -5}, {7, 7, 7}, {1, 2, 3, 4, 5, 6, 7, 8}};
    for (const std::vector<int>& original : cases) {
        std::vector<int> mine = original;
        std::vector<int> expected = original;
        reverseArray(mine);
        std::reverse(expected.begin(), expected.end());
        check(mine == expected, "reverse of size " + std::to_string(original.size()));
    }
    std::vector<int> demo = {1, 2, 3, 4, 5};
    reverseArray(demo);
    std::cout << "reversed demo: " << demo[0] << ' ' << demo[1] << ' ' << demo[2] << ' ' << demo[3] << ' ' << demo[4] << '\n';

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
