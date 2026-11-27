# Interview Problems - Explanations

[← Module index](../README.md) · Pattern background: [pattern guide](../04-array-patterns/explanations.md)

| File | Title | Type |
|---|---|---|
| [024](024_missing_number.cpp) | Missing number | Worked example |
| [025](025_max_consecutive_ones.cpp) | Max consecutive ones | Exercise |
| [026](026_single_number.cpp) | Single number (XOR) | Worked example |
| [027](027_union_of_arrays.cpp) | Union of sorted arrays | Exercise |
| [028](028_intersection_of_arrays.cpp) | Intersection of sorted arrays | Exercise |
| [029](029_two_sum.cpp) | Two Sum | Worked example |
| [030](030_best_time_to_buy_sell_stock.cpp) | Best time to buy and sell stock | Exercise |
| [031](031_maximum_subarray_sum.cpp) | Maximum subarray sum (Kadane) | Worked example |
| [032](032_subarray_sum_equals_k.cpp) | Subarray sum equals K | **Challenge** |
| [033](033_longest_subarray_sum_k.cpp) | Longest subarray with sum K | **Challenge** |

Reference solutions for the exercises and challenges are in [`../solutions/`](../solutions/solution-notes.md) (spoilers; attempt first). Challenge hints are in [challenge-hints.md](../solutions/challenge-hints.md).

---

## 024 - Missing number  *(Worked example)*

1. **Problem.** n distinct numbers drawn from `0..n`; exactly one is missing. Find it.
2. **Input / output.** `{3,0,1}` → `2`.
3. **Intuition.** We know exactly what the full collection `0..n` adds up to. The array is that collection minus one number, so the shortfall *is* the number.
4. **Brute force.** For each candidate `v` in `0..n`, scan the array for it: O(n²). Or sort and look for the first index where `a[i] != i`: O(n log n).
5. **Optimised approach.** Expected sum `n(n+1)/2` minus actual sum: O(n) time, O(1) space.
6. **Algorithm.** `expected = n*(n+1)/2` (as `long long`); `actual = sum of a`; return `expected - actual`.
7. **Dry run.** `{3,0,1}`: n = 3, expected = 6, actual = 4 → 6 − 4 = **2** ✓.
8. **Code.** [024_missing_number.cpp](024_missing_number.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty array (n = 0, range `{0}`, answer 0); missing 0; missing n; n large enough that `n(n+1)/2` overflows `int` (use `long long`).
12. **Common mistakes.** Assuming the range is `1..n`; `int` overflow; using the formula when the array may contain duplicates (the problem guarantees distinct).
13. **When to use.** "One number missing from a known complete range". For "one number repeated and one missing" a sum alone is not enough.
14. **Interview relevance.** Often followed by the XOR variant (see 026) or by "now two numbers are missing".
15. **Revision question.** Why does the XOR of `0..n` with all array elements also give the missing number?

## 025 - Max consecutive ones  *(Exercise)*

* **Problem.** Longest run of 1s in a 0/1 array. `{1,1,0,1,1,1}` → 3.
* **Constraints.** 0 ≤ n ≤ 10⁵, values 0 or 1.
* **Edge cases.** Empty; no ones; all ones; best run first/last; alternating.
* **Target.** O(n), O(1). Pattern: [running summary with two variables](../04-array-patterns/explanations.md#2-linear-traversal-and-running-summaries).
* **Revision question.** Which event resets your counter and which event updates your answer?

---

## 026 - Single number (XOR)  *(Worked example)*

1. **Problem.** Every value appears exactly twice except one; find it.
2. **Input / output.** `{4,1,2,1,2}` → `4`.
3. **Intuition.** We want an operation under which equal pairs *annihilate*. XOR does: `x ^ x = 0`, and `x ^ 0 = x`. It is also order-independent, so pairs cancel wherever they sit.
4. **Brute force.** For each element count its occurrences: O(n²); or a frequency map: O(n) time, O(n) space; or sort and compare neighbours: O(n log n).
5. **Optimised approach.** XOR all elements: O(n) time, O(1) space.
6. **Algorithm.** `result = 0`; for each value: `result ^= value`; return `result`.
7. **Dry run.** `{4,1,2,1,2}`: 0^4 = 4; 4^1 = 5; 5^2 = 7; 7^1 = 6; 6^2 = **4** ✓ (bits: 1 and 2 each entered and left).
8. **Code.** [026_single_number.cpp](026_single_number.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Single element; unique value is 0; negatives (XOR works on the bit pattern); extreme values.
12. **Common mistakes.** Applying it when other values may appear 3 times or an arbitrary number of times (the cancellation argument no longer holds); starting `result` with `a[0]` and then XOR-ing `a[0]` again.
13. **When to use.** "All but one appear twice (an even number of times)".
14. **Interview relevance.** Tests whether you know bit tricks and can exploit problem structure.
15. **Revision question.** What is `5 ^ 5 ^ 9`?

## 027 - Union of two sorted arrays  *(Exercise)*

* **Problem.** Sorted distinct values present in at least one of two sorted arrays. `{1,1,2,3,4,5}` ∪ `{2,3,4,4,5,6}` → `{1,2,3,4,5,6}`.
* **Constraints.** 0 ≤ n, m ≤ 10⁵; inputs sorted, duplicates allowed within each.
* **Edge cases.** One or both empty; disjoint arrays; all equal; duplicates spanning both arrays.
* **Target.** O(n + m), O(1) beyond the output. Pattern: two pointers on two arrays ([017](../02-array-manipulation/017_merge_sorted_arrays.cpp) is your model).
* **Revision question.** How do you guarantee each value appears once without a set?

## 028 - Intersection of two sorted arrays  *(Exercise)*

* **Problem.** Common elements with multiplicity `min(countA, countB)`. `{1,2,2,3}` ∩ `{2,2,4}` → `{2,2}`.
* **Constraints.** 0 ≤ n, m ≤ 10⁵; both sorted.
* **Edge cases.** Disjoint; one empty; identical; unequal multiplicities; negatives.
* **Target.** O(n + m), O(1) beyond the output.
* **Revision question.** What do you do with each of the three outcomes `a[i] < b[j]`, `a[i] == b[j]`, `a[i] > b[j]`, and why is each safe?

---

## 029 - Two Sum  *(Worked example)*

1. **Problem.** Find indices `i ≠ j` with `a[i] + a[j] == target`.
2. **Input / output.** `{2,7,11,15}`, target 9 → `{0, 1}`.
3. **Intuition.** For each element `x` the partner is *forced*: it must equal `target − x`. So the question "is there a partner?" becomes a **lookup**, and a hash table answers lookups in O(1).
4. **Brute force.** Try all pairs: O(n²) time, O(1) space. At n = 10⁵ that is about 5·10⁹ checks: too slow.
5. **Optimised approach.** One pass with a hash map from value to index of earlier elements.
6. **Algorithm.** For each `i`: `need = target − a[i]`; if `need` is in the map, return `{map[need], i}`; otherwise store `a[i] → i`.
7. **Dry run.** `{2,7,11,15}`, target 9: i=0: need 7, map empty → store {2:0}. i=1: need 2, found at index 0 → return **{0, 1}** ✓. (For `{3,2,4}`, target 6: i=0 need 3, store {3:0}; i=1 need 4, store {3:0, 2:1}; i=2 need 2 → found at 1 → {1,2}. The element 3 is never paired with itself because we look up *before* inserting.)
8. **Code.** [029_two_sum.cpp](029_two_sum.cpp)
9. **Time.** O(n) average (O(n²) worst case under pathological hash collisions).
10. **Auxiliary space.** O(n).
11. **Edge cases.** Empty/single element (no pair); duplicates forming the answer (`{3,3}`); negatives and zero; sums that overflow `int` (we use `long long`); no solution.
12. **Common mistakes.** Inserting before looking up (an element pairs with itself); returning values instead of indices; `unordered_map<int,int>` with a complement that leaves the `int` range; assuming the array is sorted.
13. **When to use.** Pair-with-a-property in unsorted data. If the array is sorted use [two pointers](../04-array-patterns/two-pointers.md) with O(1) space.
14. **Interview relevance.** Perhaps the most famous interview question; the hash-map idea reappears in subarray-sum problems.
15. **Revision question.** How would the solution change if the array were sorted and extra memory were not allowed?

## 030 - Best time to buy and sell stock  *(Exercise)*

* **Problem.** One buy day and a later sell day; maximise profit (0 if none). `{7,1,5,3,6,4}` → 5.
* **Constraints.** 0 ≤ n ≤ 10⁵; 0 ≤ prices[i] ≤ 10⁴.
* **Edge cases.** Empty; one day; strictly decreasing; all equal; lowest price occurring *after* an earlier higher peak.
* **Target.** O(n), O(1) (the brute force over all pairs is O(n²)). Pattern: one pass with a running summary.
* **Revision question.** What exactly does your running variable represent at the start of iteration `i`?

---

## 031 - Maximum subarray sum (Kadane)  *(Worked example)*

1. **Problem.** Largest sum of a non-empty contiguous subarray.
2. **Input / output.** `{-2,1,-3,4,-1,2,1,-5,4}` → `6` (`{4,-1,2,1}`).
3. **Intuition.** Look at subarrays by where they **end**. The best one ending at `i` either starts fresh at `a[i]` or extends the best one ending at `i−1`. A negative carried-over total can only hurt, so the choice is a simple `max`.
4. **Brute force.** For each start `i` and end `j` keep a running sum: O(n²) (re-summing each subarray from scratch would be O(n³)).
5. **Optimised approach.** Kadane: one pass, two numbers.
6. **Algorithm.** `bestEndingHere = bestOverall = a[0]`; for `i = 1…n-1`: `bestEndingHere = max(a[i], bestEndingHere + a[i])`; `bestOverall = max(bestOverall, bestEndingHere)`.
7. **Dry run.** Table in the [pattern guide §4](../04-array-patterns/explanations.md#4-kadanes-algorithm): best-ending-here goes −2, 1, −2, 4, 3, 5, 6, 1, 5; best overall finishes at **6**.
8. **Code.** [031_maximum_subarray_sum.cpp](031_maximum_subarray_sum.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** All negative (answer is the largest single element, which is why we start from `a[0]`, not 0); single element; all positive (whole array); zeros.
12. **Common mistakes.** Initialising both values to 0; resetting to 0 on a negative total (wrong when every element is negative); `int` overflow.
13. **When to use.** "Best contiguous segment" with negatives, where a sliding window fails.
14. **Interview relevance.** A top-five array question; follow-ups: return the indices, circular array, 2-D version, maximum product subarray.
15. **Revision question.** Why would "reset the running sum to 0 whenever it goes negative" return the wrong answer for `{-3,-1,-2}`?

---

## 032 - Subarray sum equals K  *(Challenge)*

* **Problem.** Count contiguous subarrays whose sum is exactly `k`. The array may contain negatives and zeros. `{1,1,1}`, k = 2 → 2.
* **Constraints.** 0 ≤ n ≤ 2·10⁵, |a[i]| ≤ 10⁴, |k| ≤ 10⁹; the answer fits in 64 bits.
* **Input/output format** and samples are in the source file's header comment.
* **Hints:** released progressively (see [challenge-hints.md](../solutions/challenge-hints.md)); try on paper first with `{1,-1,0}`, k = 0.

## 033 - Longest subarray with sum K  *(Challenge)*

* **Problem.** Length of the longest contiguous subarray with sum exactly `k` (0 if none); negatives allowed. `{1,-1,5,-2,3}`, k = 3 → 4.
* **Constraints.** 0 ≤ n ≤ 2·10⁵, |a[i]| ≤ 10⁴, |k| ≤ 10⁹.
* **Hints:** see [challenge-hints.md](../solutions/challenge-hints.md). Do 032 first.
