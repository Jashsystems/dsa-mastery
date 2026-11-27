# Complexity Analysis for Array Algorithms

[← Traversal](array-traversal.md) · Next: [C++ arrays vs vectors](cpp-arrays-vs-vectors.md) · Quick lookup table: [complexity cheat sheet](../06-revision/complexity-cheatsheet.md)

Complexity answers: **how does the work grow as the input size n grows?** It is not a stopwatch; it is a growth rate, so it predicts whether an algorithm survives a larger input.

## 1. Big-O in four rules

1. Count **basic steps** (comparisons, assignments, array reads) as a function of n.
2. Keep only the **fastest-growing term**: `3n² + 5n + 20` → `O(n²)`.
3. Drop **constant factors**: `2n` and `n/2` are both `O(n)`.
4. Different inputs → different variables: merging arrays of sizes n and m is `O(n + m)`, not `O(n)`.

Big-O is normally quoted for the **worst case** (an upper bound) unless stated otherwise.

## 2. The growth classes, with array examples

| Class | Name | Array example in this module |
|---|---|---|
| O(1) | constant | `a[i]`, `push_back` (amortised), `pop_back`, swapping two elements |
| O(log n) | logarithmic | [binary search](../03-searching/019_binary_search_intro.cpp), [lower bound](../03-searching/022_lower_bound.cpp) |
| O(n) | linear | [sum](../01-basic-operations/008_sum_of_elements.cpp), [linear search](../03-searching/018_linear_search.cpp), [Kadane](../05-interview-problems/031_maximum_subarray_sum.cpp), [merge](../02-array-manipulation/017_merge_sorted_arrays.cpp) |
| O(n log n) | linearithmic | `std::sort`, merge sort, "sort then scan" solutions |
| O(n²) | quadratic | check all pairs ([Two Sum brute force](../05-interview-problems/029_two_sum.cpp)), all subarrays with a running sum |
| O(n³) | cubic | all subarrays **re-summing each one** (three nested loops) |
| O(2ⁿ) | exponential | generating every subset of the array |
| O(n!) | factorial | generating every permutation of the array |

### Why O(log n)?
Each binary-search step discards half of the candidates: n → n/2 → n/4 → … → 1 takes ⌈log₂ n⌉ steps. For n = 10⁶ that is only about 20 steps.

### Why O(n²) for "all pairs"?
```cpp
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) { ... }   // (n-1) + (n-2) + ... + 1 = n(n-1)/2 steps
```
`n(n−1)/2` is still `O(n²)`; the ½ is a constant. Three nested loops of this shape give `O(n³)`.

## 3. How fast do they grow?

| n | log₂ n | n log₂ n | n² | n³ | 2ⁿ | n! |
|---|---|---|---|---|---|---|
| 10 | 3 | 33 | 100 | 1 000 | 1 024 | 3.6 × 10⁶ |
| 20 | 4 | 86 | 400 | 8 000 | 10⁶ | 2.4 × 10¹⁸ |
| 100 | 7 | 664 | 10⁴ | 10⁶ | 1.3 × 10³⁰ | 9 × 10¹⁵⁷ |
| 10³ | 10 | 10⁴ | 10⁶ | 10⁹ | – | – |
| 10⁵ | 17 | 1.7 × 10⁶ | 10¹⁰ | 10¹⁵ | – | – |
| 10⁶ | 20 | 2 × 10⁷ | 10¹² | – | – | – |

("–" = astronomically large.)

## 4. Best, average and worst case

The same algorithm can behave differently on different inputs of the **same size**.

| Algorithm | Best | Average | Worst | Note |
|---|---|---|---|---|
| Linear search | O(1) target is first | O(n) (about n/2 steps) | O(n) target last or absent | |
| Binary search | O(1) hit at first mid | O(log n) | O(log n) | needs sorted input |
| Check sorted ([007](../01-basic-operations/007_check_sorted.cpp)) | O(1) first pair bad | O(n) | O(n) all pairs fine | early exit |
| Insertion sort | O(n) already sorted | O(n²) | O(n²) reverse sorted | |
| Quicksort | O(n log n) | O(n log n) | O(n²) bad pivots | `std::sort` (introsort) guarantees O(n log n) worst |
| Hash-map lookup | O(1) | O(1) | O(n) many collisions | why Two Sum is "O(n) average" |

* **Worst case** is what interviewers usually want.
* **Average case** assumes a distribution of inputs (state the assumption).
* **Amortised** cost averages over a *sequence* of operations: `push_back` is O(n) occasionally but O(1) amortised.

## 5. Auxiliary space and in-place algorithms

* **Space complexity** counts memory *beyond the input*; this extra part is the **auxiliary space**. (Some authors include the input; this module always states auxiliary space.)
* An algorithm is **in place** if its auxiliary space is O(1) (a few variables), even though it may overwrite the input.

| Algorithm | Auxiliary space | In place? |
|---|---|---|
| [Reverse](../01-basic-operations/006_reverse_array.cpp), [move zeroes](../02-array-manipulation/013_move_zeroes.cpp), [rotate by k](../02-array-manipulation/012_rotate_by_k.cpp) | O(1) | yes |
| [Merge two sorted arrays](../02-array-manipulation/017_merge_sorted_arrays.cpp) | O(n + m) output | no (needs a result array) |
| [Two Sum with hash map](../05-interview-problems/029_two_sum.cpp) | O(n) | no, but time drops from O(n²) to O(n) |
| Binary search (iterative) | O(1) | yes |
| Recursive binary search | O(log n) (call stack) | no, though only slightly |
| Merge sort | O(n) | no |

**Time–space trade-off:** many interview solutions spend O(n) memory (a hash map, a prefix array) to remove a loop.

## 6. Counting nested loops

| Code shape | Complexity | Reason |
|---|---|---|
| loop inside loop, both 0..n | O(n²) | n × n |
| `j` starts at `i+1` | O(n²) | n(n−1)/2 |
| outer loop n, inner loop fixed 10 | O(n) | 10n |
| `while (n > 1) n /= 2;` | O(log n) | halves each time |
| `for i in 0..n: for (j = 1; j < n; j *= 2)` | O(n log n) | n × log n |
| two sequential loops | O(n) | n + n |
| **two pointers** with an inner `while` that only moves forward | O(n) | each index is passed at most once overall (amortised), see [two pointers](../04-array-patterns/two-pointers.md) |

Do not just count loop keywords: count **how many times the innermost statement runs in total**.

## 7. Why input constraints matter

A modern judge executes roughly **10⁸ simple operations per second** (use this as a rule of thumb, not a guarantee). If the problem says n ≤ N, pick an algorithm whose step count at n = N is at most about 10⁸ – 10⁹.

| Constraint on n | Acceptable complexity | Typical technique |
|---|---|---|
| n ≤ 10 | O(n!) | try all permutations |
| n ≤ 20 | O(2ⁿ) | try all subsets |
| n ≤ 500 | O(n³) | triple loops |
| n ≤ 5 000 | O(n²) | pair loops, simple DP |
| n ≤ 10⁵ – 2 × 10⁵ | O(n log n) | sorting, binary search, heaps |
| n ≤ 10⁶ – 10⁷ | O(n) | one pass, two pointers, prefix sums, hashing |
| n up to 10⁹ or more | O(log n) or O(1) | binary search on answer, math |

**Worked check.** Problem: n ≤ 10⁵, find a subarray with sum k. The O(n²) brute force needs about 10¹⁰ / 2 = 5 × 10⁹ steps: too slow. The O(n) prefix-sum + hash map solution needs about 10⁵: instant. The constraint told you the brute force would not pass *before* you wrote any code.

Values matter as well: a sum of 10⁵ numbers each up to 10⁹ reaches 10¹⁴ and needs `long long`.

## 8. Common mistakes

* Reporting O(n) for a loop that calls `v.insert(v.begin(), x)` inside (each call is O(n), so total O(n²)).
* Forgetting that `std::sort`, `std::reverse`, `std::find` inside a loop multiply the cost.
* Quoting best-case complexity as if it were typical.
* Ignoring auxiliary space: "O(1)" must mean no extra array that grows with n.
* Saying O(2n) or O(n + 5): simplify.

## 9. Revision questions

1. What is the complexity of calling `std::find` once for each of the n elements of the array?
2. A solution is O(n²) and n = 2 × 10⁵. Will it pass?
3. Why is Two Sum with a hash map described as "O(n) average", not "O(n) worst"?
4. Is merging two sorted arrays into a new array in place?

<details><summary>Answers</summary>

1. O(n) per call × n calls = O(n²).
2. No: about 4 × 10¹⁰ steps, far above 10⁸ – 10⁹.
3. Hash operations are O(1) on average but can degrade to O(n) per lookup under many collisions.
4. No: it allocates an output array of size n + m.

</details>
