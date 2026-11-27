# Array Traversal

[← Memory layout](array-memory-layout.md) · Next: [Complexity](array-complexity.md) · Code: [001_array_traversal.cpp](../01-basic-operations/001_array_traversal.cpp)

Traversal means visiting elements in some systematic order. Almost every array algorithm is a traversal plus a rule for what to remember.

## 1. Forward index loop

```cpp
const int n = static_cast<int>(a.size());
for (int i = 0; i < n; ++i) {
    // use i and a[i]
}
```

Use it when the **position** matters (comparing neighbours, writing back, two pointers).

## 2. Range-based `for`

```cpp
for (int value : a) { /* read-only use of value */ }
```

* `value` is a **copy**. Changing it does not change the vector.
* To modify in place use a reference: `for (int& value : a) value *= 2;`.
* Cannot tell you the index and cannot skip elements easily.

## 3. Backward loop

```cpp
for (int i = n - 1; i >= 0; --i) { /* ... */ }
```

The loop variable **must be signed**. Useful for shifting right ([011](../02-array-manipulation/011_right_rotate.cpp)) and last-occurrence searches.

## 4. Iterators (first look)

An **iterator** is a "position in a container". `a.begin()` is the first element's position; `a.end()` is one past the last (a valid position that holds no element).

```cpp
for (auto it = a.begin(); it != a.end(); ++it) {
    int value = *it;   // * reads the element the iterator points at
}
```

Library algorithms take ranges `[begin, end)`: `std::reverse(a.begin(), a.end())`. Subtracting two iterators gives a distance, hence an index: `it - a.begin()`.

## 5. Traversal shapes you will meet

| Shape | Picture | Typical use |
|---|---|---|
| One pass, left → right | `→ → → →` | sum, max, count, Kadane, prefix sums |
| Neighbour pairs | `(i-1, i)` | sortedness, runs, differences |
| Two ends inward | `→ ... ←` | reverse, palindromes, two-sum on sorted data |
| Two pointers, same direction | `slow → fast →` | in-place filtering ([013](../02-array-manipulation/013_move_zeroes.cpp), [014](../02-array-manipulation/014_remove_duplicates.cpp)) |
| Window moving right | `[ l … r ] →` | [sliding window](../04-array-patterns/sliding-window.md) |
| Repeated halving | `mid` jumps | [binary search](../03-searching/019_binary_search_intro.cpp) |
| Nested loops over pairs | `i`, `j > i` | brute-force pair/subarray checks, O(n²) |

## 6. Loop invariants (thinking tool)

An **invariant** is a statement that is true before every iteration. Writing it down is how you prove an array algorithm correct and how you avoid off-by-one errors.

Example from [013 Move zeroes](../02-array-manipulation/013_move_zeroes.cpp):
*"`a[0..write-1]` holds exactly the non-zero elements seen so far, in original order."* The loop body only has to preserve that sentence.

## 7. Modifying while traversing

* Overwriting `a[i]` is safe if you no longer need its old value.
* Calling `push_back`, `insert`, or `erase` **inside** a range-for over the same vector is undefined behaviour (iterators are invalidated).
* Shifting loops must choose a direction that never overwrites unread data (left-shift: forward; right-shift: backward).

## 8. Common mistakes

* `i <= n` instead of `i < n` (reads `a[n]`).
* `for (size_t i = a.size() - 1; i >= 0; --i)` (infinite loop).
* Expecting `for (int v : a) v = 0;` to clear the vector.

## 9. Revision questions

1. Which loop style do you need to compare `a[i-1]` and `a[i]`?
2. What does `a.end()` point to?

<details><summary>Answers</summary>

1. An index loop starting at `i = 1`.
2. One position past the last element; dereferencing it is invalid.

</details>
