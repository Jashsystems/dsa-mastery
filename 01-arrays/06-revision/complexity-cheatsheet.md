# Complexity Cheat Sheet

[← Module index](../README.md) · Full explanation: [array complexity guide](../00-foundations/array-complexity.md)

## 1. `std::vector` operations

| Operation | Time | Notes |
|---|---|---|
| `a[i]`, `a.at(i)`, `front()`, `back()` | O(1) | |
| `size()`, `empty()` | O(1) | |
| `push_back` | O(1) amortised | O(n) when it reallocates |
| `pop_back` | O(1) | |
| `insert` / `erase` at index i | O(n − i) | at the front: O(n) |
| `clear()` | O(n) | |
| `std::find` | O(n) | |
| `std::sort` | O(n log n) | |
| `std::reverse` | O(n) | |
| `lower_bound`, `upper_bound`, `binary_search` | O(log n) | **sorted** input only |
| `std::accumulate` | O(n) | |
| `unordered_map` insert / find | O(1) average | O(n) worst |
| `map` insert / find | O(log d) | |

## 2. Algorithms in this module

| Problem | File | Time | Aux. space | In place? |
|---|---|---|---|---|
| Traversal | [001](../01-basic-operations/001_array_traversal.cpp) | O(n) | O(1) | yes |
| Reverse | [006](../01-basic-operations/006_reverse_array.cpp) | O(n) | O(1) | yes |
| Check sorted | [007](../01-basic-operations/007_check_sorted.cpp) | O(n) | O(1) | yes |
| Sum | [008](../01-basic-operations/008_sum_of_elements.cpp) | O(n) | O(1) | yes |
| Frequency count | [009](../01-basic-operations/009_frequency_count.cpp) | O(n + M) / O(n log d) | O(M) / O(d) | no |
| Rotate by one | [010](../02-array-manipulation/010_left_rotate.cpp), 011 | O(n) | O(1) | yes |
| Rotate by k (reversal) | [012](../02-array-manipulation/012_rotate_by_k.cpp) | O(n) | O(1) | yes |
| Move zeroes | [013](../02-array-manipulation/013_move_zeroes.cpp) | O(n) | O(1) | yes |
| Remove duplicates (sorted) | [014](../02-array-manipulation/014_remove_duplicates.cpp) | O(n) | O(1) | yes |
| Remove element | 015 | O(n) | O(1) | yes |
| Insert at index | [016](../02-array-manipulation/016_insert_element.cpp) | O(n) | O(1) amortised | yes |
| Merge sorted arrays | [017](../02-array-manipulation/017_merge_sorted_arrays.cpp) | O(n + m) | O(n + m) output | no |
| Linear search | [018](../03-searching/018_linear_search.cpp) | O(n) | O(1) | yes |
| Binary search / first / last / bounds | [019](../03-searching/019_binary_search_intro.cpp)–023 | O(log n) | O(1) | yes |
| Missing number | [024](../05-interview-problems/024_missing_number.cpp) | O(n) | O(1) | yes |
| Max consecutive ones | 025 | O(n) | O(1) | yes |
| Single number (XOR) | [026](../05-interview-problems/026_single_number.cpp) | O(n) | O(1) | yes |
| Union / intersection (sorted) | 027, 028 | O(n + m) | O(1) beyond output | no (output) |
| Two Sum (hash map) | [029](../05-interview-problems/029_two_sum.cpp) | O(n) average | O(n) | no |
| Stock, one transaction | 030 | O(n) | O(1) | yes |
| Kadane | [031](../05-interview-problems/031_maximum_subarray_sum.cpp) | O(n) | O(1) | yes |
| Subarray sum = K (count) | 032 | O(n) average | O(n) | no |
| Longest subarray, sum K | 033 | O(n) average | O(n) | no |

## 3. Constraint → target complexity

| n | Target |
|---|---|
| ≤ 10 | O(n!) |
| ≤ 20 | O(2ⁿ) |
| ≤ 500 | O(n³) |
| ≤ 5 000 | O(n²) |
| ≤ 2 × 10⁵ | O(n log n) |
| ≤ 10⁶ – 10⁷ | O(n) |
| ≥ 10⁹ | O(log n) / O(1) |

## 4. Frequent brute force → optimised upgrades

| Brute force | Cost | Upgrade | Cost |
|---|---|---|---|
| all pairs | O(n²) | hash map / two pointers on sorted data | O(n) / O(n log n) |
| all subarrays with running sum | O(n²) | Kadane / prefix sums + hash / window | O(n) |
| re-sum each window | O(n·k) | sliding window | O(n) |
| linear scan of sorted data | O(n) | binary search | O(log n) |
| copy to a new array | O(n) space | in-place pointers | O(1) space |
| nested duplicate check | O(n²) | frequency table / sort | O(n) / O(n log n) |
