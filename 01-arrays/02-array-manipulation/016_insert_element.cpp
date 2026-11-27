/*
 * 016 - Insert an element at a given index
 * Type: WORKED EXAMPLE (complete solution + explanation)
 *
 * Problem: Insert `value` so that it ends up at index `position`, shifting later elements one step right. Return false (and change nothing) if position is not in [0, n].
 * Constraints: 0 <= n <= 10^5. Valid positions: 0 .. n (n means "append").
 * Examples:
 *   {1, 2, 4, 5}, position 2, value 3 -> {1, 2, 3, 4, 5}
 *
 * Approach:
 *   A vector has no gap to insert into, so we make room: push_back to grow by one slot.
 *   Shift elements [position, n-1] one step right, starting from the back so nothing is overwritten early.
 *   Write the new value at `position`. Insertion in the middle is O(n) because of the shifting - this is the real cost of arrays.
 *
 * Time complexity : O(n - position) shifts; O(n) worst case (insert at the front)
 * Auxiliary space : O(1) amortised (push_back may reallocate)
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 016_insert_element.cpp -o 016_insert_element
 *   ./016_insert_element      (Windows PowerShell: .\016_insert_element.exe)
 */
#include <iostream>
#include <string>
#include <vector>

/* NEW C++ / STL IDEAS USED HERE
 *   a.push_back(x)    appends x at the end; the vector grows by one (amortised O(1)).
 *   a.insert(a.begin() + pos, x)   library version of this whole function (used in the tests).
 */
bool insertAt(std::vector<int>& a, int position, int value) {
    const int n = static_cast<int>(a.size());
    if (position < 0 || position > n) return false;
    a.push_back(value);                           // make room; the new last slot is overwritten below
    for (int i = n; i > position; --i) {
        a[i] = a[i - 1];                          // shift right, from the back
    }
    a[position] = value;
    return true;
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
    const std::vector<int> base = {1, 2, 4, 5};
    for (int position = 0; position <= 4; ++position) {
        std::vector<int> mine = base;
        std::vector<int> expected = base;
        check(insertAt(mine, position, 99), "returns true at position " + std::to_string(position));
        expected.insert(expected.begin() + position, 99);
        check(mine == expected, "contents after inserting at " + std::to_string(position));
    }
    std::vector<int> empty;
    check(insertAt(empty, 0, 7) && empty == std::vector<int>({7}), "insert into empty vector");
    std::vector<int> a = {1, 2, 3};
    check(!insertAt(a, -1, 0), "negative position rejected");
    check(!insertAt(a, 4, 0), "position n+1 rejected");
    check(a == std::vector<int>({1, 2, 3}), "vector untouched after rejection");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}
