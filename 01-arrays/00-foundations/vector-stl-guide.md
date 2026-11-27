# `std::vector` and the STL Algorithms You Need

[← C arrays vs vectors](cpp-arrays-vs-vectors.md) · Back to [module index](../README.md)

The **STL** (Standard Template Library) is C++'s built-in toolbox of containers (like `vector`) and algorithms (like `sort`). This guide introduces only what the Arrays module uses. Each item points to the file where it first appears.

> **Assignment rule:** while Problems 001 and 002 (find maximum, second largest distinct) are assigned, write those loops yourself. Do not use `std::max_element`, `std::min_element`, or `std::sort` to solve them.

## 1. Headers

| Include | Provides |
|---|---|
| `<vector>` | `std::vector` |
| `<algorithm>` | `sort`, `reverse`, `find`, `lower_bound`, `upper_bound`, `binary_search`, `max`, `min`, `swap` (swap also in `<utility>`) |
| `<numeric>` | `accumulate` |
| `<map>`, `<unordered_map>` | dictionaries |
| `<climits>` | `INT_MAX`, `INT_MIN` |

`#include <bits/stdc++.h>` pulls in everything at once (GCC only). It is convenient for contests; this module uses explicit headers so you learn where things live.

## 2. Vector essentials

| Code | Meaning | Cost | First used |
|---|---|---|---|
| `std::vector<int> a;` | empty vector | O(1) | [001](../01-basic-operations/001_array_traversal.cpp) |
| `std::vector<int> a(n, x);` | n copies of x | O(n) | [009](../01-basic-operations/009_frequency_count.cpp) |
| `a.size()` | element count (**unsigned**) | O(1) | 001 |
| `a.empty()` | `size() == 0` | O(1) | |
| `a[i]` | element i, **no bounds check** | O(1) | 001 |
| `a.at(i)` | element i, throws `std::out_of_range` if invalid | O(1) | |
| `a.front()`, `a.back()` | first / last element (undefined if empty) | O(1) | [010](../02-array-manipulation/010_left_rotate.cpp) |
| `a.push_back(x)` | append | O(1) amortised | [016](../02-array-manipulation/016_insert_element.cpp) |
| `a.pop_back()` | remove last (undefined if empty) | O(1) | |
| `a.insert(a.begin() + i, x)` | insert before index i | O(n) | 016 (tests) |
| `a.erase(a.begin() + i)` | remove index i | O(n) | |
| `a.clear()` | remove all elements | O(n) | |
| `a.reserve(k)` | pre-allocate room for k elements | O(k) | [017](../02-array-manipulation/017_merge_sorted_arrays.cpp) |
| `a == b` | element-wise equality | O(n) | all tests |

## 3. References in function parameters

`const std::vector<int>& a` means "a is another name for the caller's vector (no copy); I will not modify it". Without `&` the whole vector is copied. Without `const` the function may modify the caller's data. See [C++ arrays vs vectors §4](cpp-arrays-vs-vectors.md).

## 4. Iterators and ranges

* `a.begin()`: position of the first element. `a.end()`: position **one past** the last.
* `a.begin() + k`: position of index k.
* `it - a.begin()`: converts a position into an index.
* A range `[first, last)` is **half-open**: includes `first`, excludes `last`.

Most STL algorithms take a range, e.g. `std::sort(a.begin(), a.end())`.

## 5. Algorithms

| Call | Does | Requirement | Cost | Used in |
|---|---|---|---|---|
| `std::swap(x, y)` | exchange two values | – | O(1) | [006](../01-basic-operations/006_reverse_array.cpp), [013](../02-array-manipulation/013_move_zeroes.cpp) |
| `std::reverse(first, last)` | reverse the range in place | – | O(n) | [012](../02-array-manipulation/012_rotate_by_k.cpp) |
| `std::sort(first, last)` | ascending sort | – | O(n log n) | [017](../02-array-manipulation/017_merge_sorted_arrays.cpp) (tests) |
| `std::sort(first, last, std::greater<int>())` | descending sort | `<functional>` | O(n log n) | |
| `std::find(first, last, x)` | iterator to first x, or `last` | – | O(n) | [018](../03-searching/018_linear_search.cpp) |
| `std::lower_bound(first, last, x)` | first element **>= x** | **sorted** | O(log n) | [022](../03-searching/022_lower_bound.cpp) |
| `std::upper_bound(first, last, x)` | first element **> x** | **sorted** | O(log n) | [023](../03-searching/023_upper_bound.cpp) |
| `std::binary_search(first, last, x)` | bool: is x present? | **sorted** | O(log n) | [019](../03-searching/019_binary_search_intro.cpp) (tests) |
| `std::accumulate(first, last, init)` | sum starting from `init` | `<numeric>`; use `0LL` for long long | O(n) | [008](../01-basic-operations/008_sum_of_elements.cpp) |
| `std::max(x, y)`, `std::min(x, y)` | larger / smaller of two values | same type for both | O(1) | [031](../05-interview-problems/031_maximum_subarray_sum.cpp) |

Both `lower_bound` and `upper_bound` on the range `[1, 3, 3, 5]`:

```
index:         0  1  2  3        x = 3
a:           [ 1, 3, 3, 5 ]
lower_bound(3) ──► index 1   (first >= 3)
upper_bound(3) ──────────► index 3   (first > 3)
count of 3s = upper - lower = 2
```

## 6. Lambdas (just enough)

A **lambda** is a small unnamed function written inline. The tests in this module use them; you do not need to write them yet.

```cpp
auto isPositive = [](int x) { return x > 0; };   // [] = captures nothing
```

## 7. Dictionaries

| Type | Order | Lookup | Use when |
|---|---|---|---|
| `std::map<K,V>` | sorted by key | O(log d) | you need keys in order, or keys are not hashable |
| `std::unordered_map<K,V>` | arbitrary | O(1) average | you only need fast lookup ([029](../05-interview-problems/029_two_sum.cpp)) |

`m[key]` creates the key with a default value (0 for numbers) if missing; `m.find(key)` does **not** create it and returns `m.end()` if absent.

## 8. Common mistakes

* Calling `lower_bound` / `binary_search` on an **unsorted** vector (result is meaningless).
* `a.size() - 1` when `a` is empty (wraps around).
* Using `a.back()` or `a.front()` on an empty vector.
* Using `accumulate(..., 0)` over large values: the `0` makes the sum an `int`.
* Erasing or inserting inside a range-for over the same vector.
* Forgetting that `m[key]` on a map inserts the key.

## 9. Revision questions

1. What does `std::lower_bound(a.begin(), a.end(), 7) - a.begin()` return?
2. Why does `std::accumulate(a.begin(), a.end(), 0)` risk overflow?
3. What is the difference between `a[i]` and `a.at(i)`?

<details><summary>Answers</summary>

1. The index of the first element ≥ 7 in a sorted vector (`a.size()` if there is none).
2. The initial value `0` is an `int`, so the running total is an `int`; use `0LL`.
3. `a[i]` is unchecked (undefined behaviour out of range); `a.at(i)` throws an exception.

</details>
