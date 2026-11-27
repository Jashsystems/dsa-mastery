/*
 * 011 - Right rotate by one position
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: Move every element one position to the right; the last element wraps around to the front.
 * Constraints: 0 <= n <= 10^5. Must be done in place (no second vector).
 * Examples:
 *   {1, 2, 3, 4, 5} -> {5, 1, 2, 3, 4}
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 011_right_rotate.cpp -o 011_right_rotate
 *   ./011_right_rotate      (Windows PowerShell: .\011_right_rotate.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Study 010_left_rotate.cpp first. Careful: the direction of the shifting loop matters here!
void rotateRightByOne(std::vector<int>& a) {
    (void)a;  // delete once you use `a`
    // TODO: your implementation
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
