/*
 * 015 - Remove all occurrences of a value (in place)
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: Remove every element equal to `value` from the vector IN PLACE, keeping the remaining elements in their original relative order. Return the new length k; the first k positions must hold the kept elements.
 * Constraints: 0 <= n <= 10^5; the array is NOT necessarily sorted.
 * Examples:
 *   {3, 2, 2, 3}, value 3 -> k = 2, first two elements {2, 2}
 *   {0,1,2,2,3,0,4,2}, value 2 -> k = 5, {0,1,3,0,4}
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 015_remove_element.cpp -o 015_remove_element
 *   ./015_remove_element      (Windows PowerShell: .\015_remove_element.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Pattern hint (category only): "in-place filtering with a slow and a fast pointer". Compare with 013/014.
int removeElement(std::vector<int>& a, int value) {
    (void)a;      // delete these two lines once you use the parameters
    (void)value;
    // TODO: your implementation
    return -1;
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
    auto run = [](std::vector<int> v, int value, const std::vector<int>& expectedPrefix, const std::string& label) {
        const int k = removeElement(v, value);
        check(k == static_cast<int>(expectedPrefix.size()), label + " (length)");
        if (k == static_cast<int>(expectedPrefix.size())) {
            check(std::vector<int>(v.begin(), v.begin() + k) == expectedPrefix, label + " (prefix, order preserved)");
        }
    };
    run({}, 5, {}, "empty");
    run({3, 2, 2, 3}, 3, {2, 2}, "ends removed");
    run({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 3, 0, 4}, "scattered");
    run({1, 2, 3}, 4, {1, 2, 3}, "value absent");
    run({6, 6, 6}, 6, {}, "everything removed");
    run({-1, 5, -1}, -1, {5}, "negative value");
    run({9}, 9, {}, "single removed");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
