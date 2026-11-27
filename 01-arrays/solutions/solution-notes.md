# Reference Solutions - Notes

[← Module index](../README.md)

> **Spoiler zone.** Attempt each exercise yourself before opening the matching `.cpp` file here. The starter templates live next to the topic they belong to.

## What is (and is not) in this folder

| Problem | Reference solution | Status |
|---|---|---|
| 002 Find maximum (mentor Problem 001) | **none** | Assigned. Not provided. |
| 003 Find minimum | none yet | Withheld until 002 is signed off (it is a near-copy of 002). |
| 004 Second largest distinct (mentor Problem 002) | **none** | Assigned. Not provided. |
| 005 Second smallest distinct | none yet | Withheld until 004 is signed off. |
| 011, 015, 021, 023, 025, 027, 028, 030 | included below | Exercises not currently assigned |
| 032, 033 (challenges) | included below | Open only after using the [hints](challenge-hints.md) |

Each `.cpp` here has the same tests as the starter and passes them.

---

## [011 Right rotate by one](011_right_rotate.cpp)
* **Idea.** Mirror of 010: save the last element, shift everything right **starting from the back**, drop the saved value at index 0.
* **Dry run** `{1,2,3,4,5}`: last = 5 → `{1,2,3,4,4}` → `{1,2,3,3,4}` → `{1,2,2,3,4}` → `{1,1,2,3,4}` → a[0] = 5 → `{5,1,2,3,4}`.
* **Complexity.** O(n) time, O(1) space. **Pitfall.** Forward shifting copies a[0] across the whole array.

## [015 Remove element](015_remove_element.cpp)
* **Idea.** Slow/fast pointers: keep a[read] only if it differs from `value`.
* **Dry run** `{3,2,2,3}`, value 3: read 1 → a0 = 2; read 2 → a1 = 2; reads 0 and 3 skipped; return 2.
* **Complexity.** O(n), O(1). **Pitfall.** Treating it like 014 (compare with the previous kept element) instead of comparing with `value`.

## [021 Last occurrence](021_last_occurrence.cpp)
* **Idea.** Binary search; on a match record it and search the **right** half (`left = mid + 1`).
* **Dry run** `{1,2,2,2,3}`, target 2: mid 2 → ans 2; mid 3 → ans 3; mid 4 (3 > 2) → right = 3; stop; return 3.
* **Complexity.** O(log n), O(1). **Pitfall.** Returning at the first match.

## [023 Upper bound](023_upper_bound.cpp)
* **Idea.** Same template as lower bound, but "too small" now means `a[mid] <= target`.
* **Dry run** `{1,3,3,5}`, target 3: [0,4) mid 2 (3 ≤ 3) → left 3; mid 3 (5 > 3) → right 3; return 3.
* **Complexity.** O(log n), O(1). **Pitfall.** Keeping `<` from lower bound.

## [025 Max consecutive ones](025_max_consecutive_ones.cpp)
* **Idea.** Two variables: `currentRun` and `bestRun`; a 1 extends, a 0 resets.
* **Dry run** `{1,1,0,1,1,1}`: run 1,2, reset, 1,2,3 → best 3.
* **Complexity.** O(n), O(1). **Pitfall.** Updating `best` only when a 0 appears (misses a run at the end).

## [027 Union of sorted arrays](027_union_of_arrays.cpp)
* **Idea.** Merge with two pointers; append only if the value differs from the last appended one (duplicates are adjacent because inputs are sorted).
* **Dry run** `{1,1,2}` ∪ `{2,3}`: append 1; skip 1; append 2; skip the second 2; append 3 → `{1,2,3}`.
* **Complexity.** O(n + m), O(1) beyond output. **Pitfall.** Forgetting to apply the duplicate check in the leftover loops.

## [028 Intersection of sorted arrays](028_intersection_of_arrays.cpp)
* **Idea.** Advance the pointer at the smaller value (it can never match later elements of the other array); on equality, record it and advance both.
* **Dry run** `{1,2,2,3}` ∩ `{2,2,4}`: 1 < 2 skip; 2 = 2 record; 2 = 2 record; 3 < 4 skip → `{2,2}`.
* **Complexity.** O(n + m), O(1) beyond output. **Pitfall.** Advancing only one pointer on a match (duplicates would be paired repeatedly).

## [030 Best time to buy and sell stock](030_best_time_to_buy_sell_stock.cpp)
* **Brute force.** All (buy, sell) pairs, O(n²).
* **Idea.** The best profit when selling on day i uses the cheapest price *before* i. Keep that cheapest price while scanning.
* **Dry run** `{7,1,5,3,6,4}`: cheapest 7 → 1 (day 1); profits: 4 (day 2), 2, **5** (day 4), 3 → 5.
* **Complexity.** O(n), O(1). **Pitfall.** Taking max − min of the whole array (the minimum may come after the maximum).

## [032 Subarray sum equals K](032_subarray_sum_equals_k.cpp)  *(challenge)*
* **Brute force.** Every (start, end) pair with a running sum: O(n²).
* **Idea.** With `prefix[i]` = sum of the first i elements, subarray `(j, i]` has sum `prefix[i] − prefix[j]`. It equals k exactly when `prefix[j] = prefix[i] − k`. Scanning left to right, keep a hash map `prefix value → number of times seen`, seeded with `{0: 1}` for the empty prefix. For each i add `map[prefix[i] − k]` to the answer, then record `prefix[i]`. Works with negatives and zeros.
* **Dry run** `{1,1,1}`, k = 2: seen `{0:1}`; prefix 1: need −1 → +0; prefix 2: need 0 → +1; prefix 3: need 1 → +1; total **2**.
* **Complexity.** O(n) average, O(n) space. **Pitfalls.** Forgetting the `{0:1}` seed (misses subarrays starting at index 0); inserting the current prefix *before* the lookup (breaks k = 0); `int` prefix overflow.

## [033 Longest subarray with sum K](033_longest_subarray_sum_k.cpp)  *(challenge)*
* **Idea.** Same identity as 032, but to maximise the length `i − j` we want the **earliest** j, so store the *first index* of each prefix value (never overwrite) and seed `{0: −1}`.
* **Dry run** `{1,-1,5,-2,3}`, k = 3: prefixes 1, 0, 5, 3, 6. At prefix 3 (i = 3) we need 0, first seen at index −1 → length 4. At prefix 6 (i = 4) we need 3, first seen at index 3 → length 1. Answer **4**.
* **Complexity.** O(n) average, O(n) space. **Pitfalls.** Overwriting the stored index on a repeat (shortens answers); seeding with index 0 instead of −1.
* **Alternative.** If every element is non-negative, a [sliding window](../04-array-patterns/sliding-window.md) gives O(1) space; negatives break it.
