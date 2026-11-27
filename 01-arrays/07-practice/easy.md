# Easy Practice Set

[← Module index](../README.md) · Next: [Medium](medium.md) · Timed sets: [timed assessments](timed-assessments.md)

**How to use.** Each problem is an *implementation exercise* (class B): you get the statement, constraints, a sample and a starter stub. **No solutions are provided here.** Copy the stub into a new `.cpp` file, write your own tests in the style used by the module files (the `check` helper), and compile with `g++ -std=c++17 -Wall -Wextra -Wpedantic`.

The stubs contain only `// TODO` (add a placeholder `return` while you work so the file compiles). Before coding: state the brute force, the target complexity and the edge cases. After coding: dry-run on the sample, then on empty/single-element input.

| ID | Problem | Category | Prerequisite reading |
|---|---|---|---|
| E1 | Alternating index sum | traversal | [array traversal](../00-foundations/array-traversal.md) |
| E2 | Range of an array 🔒 | running summary | wait for mentor sign-off on 002 and 004 |
| E3 | Reverse a subarray | two pointers (ends) | [006](../01-basic-operations/006_reverse_array.cpp) |
| E4 | Count adjacent inversions | traversal / sortedness | [007](../01-basic-operations/007_check_sorted.cpp) |
| E5 | Unique elements, first occurrences kept | frequency / hashing | [009](../01-basic-operations/009_frequency_count.cpp) |
| E6 | Move negatives to the end | slow & fast pointers | [013](../02-array-manipulation/013_move_zeroes.cpp) |
| E7 | Digit frequencies | counting array | [frequency arrays](../04-array-patterns/frequency-arrays.md) |
| E8 | First repeated element | frequency / seen table | [frequency arrays](../04-array-patterns/frequency-arrays.md) |

The module exercises [011](../02-array-manipulation/011_right_rotate.cpp), [015](../02-array-manipulation/015_remove_element.cpp), [021](../03-searching/021_last_occurrence.cpp), [023](../03-searching/023_upper_bound.cpp), [025](../05-interview-problems/025_max_consecutive_ones.cpp), [027](../05-interview-problems/027_union_of_arrays.cpp), [028](../05-interview-problems/028_intersection_of_arrays.cpp) and [030](../05-interview-problems/030_best_time_to_buy_sell_stock.cpp) are also easy-level practice with built-in tests. The mentor-assigned [002](../01-basic-operations/002_find_maximum.cpp) and [004](../01-basic-operations/004_second_largest.cpp) are the first two pieces of independent practice.

---

## E1 - Alternating index sum
**Difficulty:** Easy · **Class:** B
**Problem.** Return (sum of elements at even indices) − (sum of elements at odd indices), indices counted from 0.
**Constraints.** 0 ≤ n ≤ 10⁵, |a[i]| ≤ 10⁹ (use 64-bit).
**Sample.** `{5, 3, 8, 1}` → `(5 + 8) − (3 + 1) = 9`.
**Approach category.** Linear traversal with an accumulator; think about the type of the accumulator.
```cpp
long long alternatingIndexSum(const std::vector<int>& a) {
    // TODO
}
```

## E2 - Range of an array 🔒
**Difficulty:** Easy · **Class:** B · **Locked:** start only after your mentor signs off Problems 001–002 ([002](../01-basic-operations/002_find_maximum.cpp), [004](../01-basic-operations/004_second_largest.cpp)).
**Problem.** Return `max − min` of a non-empty array. Do it in a **single pass** without calling `std::minmax_element`.
**Constraints.** 1 ≤ n ≤ 10⁵, full `int` range (the difference can exceed `int`).
**Sample.** `{3, 9, 2}` → `7`; `{5}` → `0`.
**Approach category.** Running summary with two variables.
```cpp
long long arrayRange(const std::vector<int>& a) {
    // TODO
}
```

## E3 - Reverse a subarray
**Difficulty:** Easy · **Class:** B
**Problem.** Reverse the elements of `a[l..r]` (inclusive) in place; the rest is unchanged.
**Constraints.** 0 ≤ l ≤ r < n ≤ 10⁵ (the caller guarantees valid indices).
**Sample.** `{1, 2, 3, 4, 5}`, l = 1, r = 3 → `{1, 4, 3, 2, 5}`.
**Approach category.** Two pointers from both ends.
```cpp
void reverseRange(std::vector<int>& a, int l, int r) {
    // TODO
}
```

## E4 - Count adjacent inversions
**Difficulty:** Easy · **Class:** B
**Problem.** Count indices `i` with `a[i] > a[i+1]`. The array is sorted (non-decreasing) exactly when the count is 0.
**Constraints.** 0 ≤ n ≤ 10⁵.
**Sample.** `{1, 3, 2, 4, 0}` → `2` (3 > 2 and 4 > 0); `{1, 1, 2}` → `0`.
**Approach category.** Traversal over neighbouring pairs; be careful with the loop bounds.
```cpp
int countAdjacentInversions(const std::vector<int>& a) {
    // TODO
}
```

## E5 - Unique elements, first occurrences kept
**Difficulty:** Easy · **Class:** B
**Problem.** Return the array with every repeated value removed, keeping only the **first** occurrence of each and preserving the original order. The input is **not** sorted.
**Constraints.** 0 ≤ n ≤ 10⁵, |a[i]| ≤ 10⁹.
**Sample.** `{4, 2, 4, 1, 2}` → `{4, 2, 1}`.
**Approach category.** Frequency/"seen" table (which structure suits values up to 10⁹?). Brute force is O(n²); aim for O(n) average.
```cpp
std::vector<int> uniqueKeepFirst(const std::vector<int>& a) {
    // TODO
}
```

## E6 - Move negatives to the end
**Difficulty:** Easy · **Class:** B
**Problem.** Rearrange in place so that all non-negative elements come first **in their original relative order**, followed by the negative elements (their order does not matter). Return `p`, the number of non-negative elements.
**Constraints.** 0 ≤ n ≤ 10⁵; O(1) extra space.
**Sample.** `{3, -1, 2, -5, 4}` → `p = 3`, first three elements `{3, 2, 4}`, last two are `-1` and `-5` in either order.
**Approach category.** Slow and fast pointers (compare with Move zeroes).
```cpp
int moveNegativesToEnd(std::vector<int>& a) {
    // TODO
}
```

## E7 - Digit frequencies
**Difficulty:** Easy · **Class:** B
**Problem.** Every element is a single digit 0–9. Return a vector of size 10 where entry `d` is the number of times `d` occurs.
**Constraints.** 0 ≤ n ≤ 10⁵, 0 ≤ a[i] ≤ 9.
**Sample.** `{1, 2, 2, 9, 1, 1}` → `{0, 3, 2, 0, 0, 0, 0, 0, 0, 1}`.
**Approach category.** Counting array.
```cpp
std::vector<int> digitFrequencies(const std::vector<int>& a) {
    // TODO
}
```

## E8 - First repeated element
**Difficulty:** Easy · **Class:** B
**Problem.** Return the value whose **second occurrence** appears earliest in the array (scanning left to right). Return −1 if all values are distinct.
**Constraints.** 0 ≤ n ≤ 10⁵, 1 ≤ a[i] ≤ 10⁵.
**Sample.** `{2, 5, 1, 2, 3, 5}` → `2` (the repeat of 2 is at index 3, the repeat of 5 at index 5); `{1, 2, 3}` → `-1`.
**Approach category.** Seen table while scanning once.
```cpp
int firstRepeated(const std::vector<int>& a) {
    // TODO
}
```
