/*
 * 011 - Right rotate by one position
 * Type: REFERENCE SOLUTION - spoiler, attempt the exercise first
 *
 * Problem: Move every element one position to the right; the last element wraps around to the front.
 * Constraints: 0 <= n <= 10^5. Must be done in place (no second vector).
 * Examples:
 *   {1, 2, 3, 4, 5} -> {5, 1, 2, 3, 4}
 *
 * Approach:
 *   Save the last element.
 *   Shift every element one step right, starting from the back so nothing is lost.
 *   Write the saved value at index 0.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 011_right_rotate.cpp -o 011_right_rotate
 *   ./011_right_rotate      (Windows PowerShell: .\011_right_rotate.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Mirror image of the left rotation: save the LAST element, shift right-to-left, put it in front.
// The shifting loop must run from the back; going forwards would overwrite a[i+1] before it is copied.
void rotateRightByOne(std::vector<int>& a) {
    if (a.size() < 2) return;
    const int last = a.back();
    for (int i = static_cast<int>(a.size()) - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = last;
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
    rotateRightByOne(a);
    check(a.empty(), "empty stays empty");
    a = {9};
    rotateRightByOne(a);
    check(a == std::vector<int>({9}), "single element");
    a = {1, 2, 3, 4, 5};
    rotateRightByOne(a);
    check(a == std::vector<int>({5, 1, 2, 3, 4}), "basic");
    a = {1, 1, 2};
    rotateRightByOne(a);
    check(a == std::vector<int>({2, 1, 1}), "duplicates");
    a = {-1, 0};
    rotateRightByOne(a);
    check(a == std::vector<int>({0, -1}), "two elements");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
