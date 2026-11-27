# Hard Practice Set (Challenge Problems)

[← Medium](medium.md) · Next: [Timed assessments](timed-assessments.md)

These are **challenge problems (class C)**: statement, constraints and a sample only. There are **no starter stubs, no solutions and no hints here**; hints are released one at a time by your mentor. Attempt each for a fixed time-box (45–60 minutes) before asking for the first hint, and write down your brute force and its complexity first.

Prerequisites: everything in [medium](medium.md), plus the [pattern guide](../04-array-patterns/explanations.md).

| ID | Problem | Theme |
|---|---|---|
| H1 | Trapping rain water | complex two-pointer |
| H2 | Longest subarray with at most K distinct values | advanced sliding window |
| H3 | Subarrays with exactly K distinct values | advanced sliding window |
| H4 | Split array into M parts, minimise the largest sum | binary search on the answer |
| H5 | First missing positive | multiple constraints (O(n) time, O(1) space) |
| H6 | Two non-overlapping subarrays of fixed lengths | multiple constraints / prefix sums |
| H7 | Minimum days to make M bouquets | binary search on the answer |
| H8 | Maximum subarray sum with one optional deletion | advanced subarray |

---

## H1 - Trapping rain water
**Difficulty:** Hard
**Problem.** `height[i]` is the height of a bar of width 1. After rain, how many units of water are trapped between the bars?
**Constraints.** 0 ≤ n ≤ 2·10⁵, 0 ≤ height[i] ≤ 10⁵. Aim for O(n) time; then try O(1) extra space.
**Sample.** `{0,1,0,2,1,0,1,3,2,1,2,1}` → `6`.

## H2 - Longest subarray with at most K distinct values
**Difficulty:** Hard
**Problem.** Return the length of the longest contiguous subarray containing at most K distinct values.
**Constraints.** 0 ≤ n ≤ 2·10⁵, 1 ≤ K ≤ n (or K ≥ 1 for n = 0), 1 ≤ a[i] ≤ 10⁹.
**Sample.** `{1,2,1,2,3}`, K = 2 → `4` (the subarray `{1,2,1,2}`).

## H3 - Subarrays with exactly K distinct values
**Difficulty:** Hard
**Problem.** Count the contiguous subarrays containing **exactly** K distinct values.
**Constraints.** 1 ≤ n ≤ 2·10⁴, 1 ≤ K ≤ n, 1 ≤ a[i] ≤ n. The answer fits in 64 bits.
**Sample.** `{1,2,1,2,3}`, K = 2 → `7`.

## H4 - Split array, minimise the largest sum
**Difficulty:** Hard
**Problem.** Split the array into exactly M non-empty **contiguous** parts so that the largest part-sum is as small as possible. Return that smallest possible largest sum.
**Constraints.** 1 ≤ M ≤ n ≤ 1000 (stretch goal: n ≤ 10⁵), 0 ≤ a[i] ≤ 10⁶.
**Sample.** `{7,2,5,10,8}`, M = 2 → `18` (split `{7,2,5}` and `{10,8}`).

## H5 - First missing positive
**Difficulty:** Hard
**Problem.** Return the smallest positive integer (≥ 1) that does **not** appear in the array. Required: O(n) time and O(1) auxiliary space (you may modify the array).
**Constraints.** 0 ≤ n ≤ 10⁵, |a[i]| ≤ 2³¹ − 1.
**Sample.** `{3,4,-1,1}` → `2`; `{1,2,0}` → `3`; `{7,8,9,11,12}` → `1`.

## H6 - Two non-overlapping subarrays of given lengths
**Difficulty:** Hard
**Problem.** Given lengths L and M, choose a subarray of length L and a subarray of length M that do **not overlap** (in either order). Maximise the sum of all chosen elements.
**Constraints.** 2 ≤ L + M ≤ n ≤ 1000 (target O(n) for n up to 10⁵), 0 ≤ a[i] ≤ 1000.
**Sample.** `{0,6,5,2,2,5,1,9,4}`, L = 1, M = 2 → `20` (the single element 9 and the pair 6,5).

## H7 - Minimum days to make M bouquets
**Difficulty:** Hard
**Problem.** `bloomDay[i]` is the day flower i blooms. A bouquet needs K **adjacent** bloomed flowers, and each flower can be used in one bouquet. Return the minimum number of days after which M bouquets can be made, or −1 if impossible.
**Constraints.** 1 ≤ n ≤ 10⁵, 1 ≤ bloomDay[i] ≤ 10⁹, 1 ≤ M ≤ 10⁶, 1 ≤ K ≤ n.
**Sample.** `bloomDay = {1,10,3,10,2}`, M = 3, K = 1 → `3`; M = 3, K = 2 → `-1`; `{7,7,7,7,12,7,7}`, M = 2, K = 3 → `12`.

## H8 - Maximum subarray sum with one optional deletion
**Difficulty:** Hard
**Problem.** Choose a non-empty contiguous subarray and optionally delete **at most one** element from it (the remaining subarray must still be non-empty). Return the maximum possible sum.
**Constraints.** 1 ≤ n ≤ 10⁵, |a[i]| ≤ 10⁴.
**Sample.** `{1,-2,0,3}` → `4` (delete −2); `{1,-2,-2,3}` → `3`; `{-1,-1,-1,-1}` → `-1`.
