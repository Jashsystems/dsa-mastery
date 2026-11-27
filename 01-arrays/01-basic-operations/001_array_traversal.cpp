/*
 * 001 - Array traversal
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Visit every element of a vector exactly once - forwards, with a range-based for loop, and backwards.
 * Constraints: 0 <= n <= 10^5; any int values.
 *
 * Approach:
 *   Index loop: a[0], a[1], ..., a[n-1]. Every other array algorithm is a variation of this loop.
 *   Range-for loop: lets the compiler handle the index when you only need the values.
 *   Reverse loop: start at the last index and count down while i >= 0.
 *
 * Time complexity : O(n)
 * Auxiliary space : O(1) besides the output string
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 001_array_traversal.cpp -o 001_array_traversal
 *   ./001_array_traversal      (Windows PowerShell: .\001_array_traversal.exe)
 */
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   std::vector<int>          a resizable array of ints.
 *   a.size()                  number of elements. Its type is an UNSIGNED integer (std::size_t).
 *                             Comparing it with a signed int triggers warnings (and bugs), so we
 *                             convert once: const int n = static_cast<int>(a.size());
 *   const std::vector<int>& a "a" is a reference (no copy is made) and const means this function
 *                             promises not to change it. Use this form for read-only parameters.
 *   a[i]                      element at index i; valid indices are 0 .. size()-1 (not checked!).
 */

// Index loop: use when you need the position i (most algorithms do).
std::string toStringByIndex(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    std::string result = "[";
    for (int i = 0; i < n; ++i) {
        if (i > 0) result += ", ";
        result += std::to_string(a[i]);
    }
    return result + "]";
}

// Range-based for: "for each value in a". `value` is a COPY of the current element.
std::string toStringRangeFor(const std::vector<int>& a) {
    std::string result = "[";
    bool isFirst = true;
    for (int value : a) {
        if (!isFirst) result += ", ";
        result += std::to_string(value);
        isFirst = false;
    }
    return result + "]";
}

// Backward traversal: start at the last valid index. For an empty vector the loop never runs.
std::string toStringReversed(const std::vector<int>& a) {
    std::string result = "[";
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        result += std::to_string(a[i]);
        if (i > 0) result += ", ";
    }
    return result + "]";
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
    const std::vector<int> empty;
    const std::vector<int> single = {5};
    const std::vector<int> normal = {1, 2, 3};
    const std::vector<int> mixed = {-4, 0, 7, 7};

    check(toStringByIndex(empty) == "[]", "index: empty");
    check(toStringByIndex(single) == "[5]", "index: single");
    check(toStringByIndex(normal) == "[1, 2, 3]", "index: normal");
    check(toStringByIndex(mixed) == "[-4, 0, 7, 7]", "index: negatives and duplicates");
    check(toStringRangeFor(empty) == "[]", "range-for: empty");
    check(toStringRangeFor(mixed) == "[-4, 0, 7, 7]", "range-for: mixed");
    check(toStringReversed(empty) == "[]", "reversed: empty");
    check(toStringReversed(single) == "[5]", "reversed: single");
    check(toStringReversed(normal) == "[3, 2, 1]", "reversed: normal");

    std::cout << "forward : " << toStringByIndex(normal) << '\n';
    std::cout << "backward: " << toStringReversed(normal) << '\n';

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
