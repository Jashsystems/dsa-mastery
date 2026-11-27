# Prefix Sums

[← Sliding window](sliding-window.md) · [Pattern guide](explanations.md) · Next: [Frequency arrays](frequency-arrays.md)

**Idea:** pay O(n) once to precompute running totals, then answer "sum of any range" in O(1).

## 1. Definition

`prefix[i]` = sum of the **first i elements** (so `prefix[0] = 0`, an empty prefix).

```
a:       [  3   1   4   1   5 ]
index:      0   1   2   3   4
prefix: [0   3   4   8   9  14 ]
index:   0   1   2   3   4   5          prefix has n + 1 entries
```

```cpp
std::vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
```

## 2. Range sum query

Sum of `a[l..r]` (inclusive) = `prefix[r + 1] - prefix[l]`.

Why: `prefix[r+1]` contains everything up to index r; subtracting `prefix[l]` removes everything before l.

**Example.** Sum of indices 1..3 (`1 + 4 + 1`): `prefix[4] - prefix[1] = 9 - 3 = 6` ✓.

| Approach | Preprocessing | Per query | q queries |
|---|---|---|---|
| Loop over the range | none | O(n) | O(n·q) |
| Prefix sums | O(n) | O(1) | O(n + q) |

The extra `0` in `prefix[0]` is what makes queries starting at index 0 need no special case.

## 3. Difference arrays (the inverse trick)

To add `v` to **every** element of `a[l..r]` many times, record only the endpoints, then take one prefix sum at the end.

```
n = 5, add 5 to indices 1..3:
diff[1] += 5;  diff[4] -= 5;           (diff has size n + 1)
diff:   [0, 5, 0, 0, -5, 0]
prefix: [0, 5, 5, 5,  0]  → the first five values are the final increments
```
Each update is O(1); the final rebuild is O(n).

## 4. Where prefix sums appear

* Repeated range-sum queries.
* Equal-sum splits (left sum vs right sum around an index): `left = prefix[i]`, `right = total - prefix[i+1]`.
* Subarray-sum questions in general: *a subarray's sum is the difference of two prefix values*, so a question about subarrays can be rephrased as a question about **pairs of prefix values**. Hash maps then answer such pair questions in O(1) each. See the challenges [032](../05-interview-problems/032_subarray_sum_equals_k.cpp) and [033](../05-interview-problems/033_longest_subarray_sum_k.cpp) (hints are released gradually).
* Variants: prefix XOR, prefix product, prefix maximum/minimum, 2-D prefix sums on grids.

## 5. Prefix sums vs sliding window

| | Sliding window | Prefix sums |
|---|---|---|
| Negative numbers | breaks (non-monotone sums) | works |
| Extra memory | O(1) | O(n) |
| Arbitrary range queries | no | yes |
| Typical question | longest/shortest window with sum condition (non-negative) | range queries, subarrays with negatives |

## 6. Recognising the pattern

| Signal | Reaction |
|---|---|
| "sum of elements between i and j", many queries | prefix sums |
| "subarray sum equals / divisible by …" with possible negatives | prefix values + a lookup structure |
| "add v to a range" repeated | difference array |
| array is **static** between queries | precompute |

## 7. Common mistakes

* Off-by-one: with an `n + 1`-sized prefix, the inclusive range `[l, r]` is `prefix[r+1] - prefix[l]`.
* Using `int` prefix values (they can reach n × max|a|; use `long long`).
* Recomputing the prefix after every point update (prefix sums suit *static* arrays; for updates use a Fenwick tree later in the curriculum).
* Forgetting the empty prefix `prefix[0] = 0`.

## 8. Revision questions

1. For `a = {2, 7, 1, 8}` write `prefix` and compute the sum of `a[1..2]`.
2. What is the time to answer q range-sum queries after preprocessing?
3. Why must `prefix` have n + 1 entries?

<details><summary>Answers</summary>

1. `prefix = {0, 2, 9, 10, 18}`; sum of `a[1..2]` = `prefix[3] - prefix[1] = 10 - 2 = 8` (7 + 1).
2. O(n) preprocessing + O(1) per query = O(n + q).
3. So that the sum of a range starting at index 0 can be written uniformly as `prefix[r+1] - prefix[0]`.

</details>
