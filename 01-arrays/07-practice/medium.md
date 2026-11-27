# Medium Practice Set

[← Easy](easy.md) · Next: [Hard](hard.md) · Timed sets: [timed assessments](timed-assessments.md)

Same rules as the [easy set](easy.md): no solutions provided; write your own tests; state brute force, target complexity and edge cases first. Pattern help: [pattern guide](../04-array-patterns/explanations.md).

| ID | Problem | Category |
|---|---|---|
| M1 | Sorted and rotated? | traversal / invariants |
| M2 | Three Sum | sort + two pointers |
| M3 | Stock buy/sell, unlimited transactions | greedy traversal |
| M4 | Duplicate and missing number | frequency / math |
| M5 | Maximum product subarray | Kadane variant |
| M6 | Longest subarray with sum ≤ K (positives) | sliding window |
| M7 | Product of array except self | prefix / suffix |
| M8 | Subarrays with sum divisible by K | prefix sums + counting |
| M9 | Search in a rotated sorted array | binary search |

Related module items: rotation [012](../02-array-manipulation/012_rotate_by_k.cpp), Two Sum [029](../05-interview-problems/029_two_sum.cpp), one-transaction stock [030](../05-interview-problems/030_best_time_to_buy_sell_stock.cpp), missing number [024](../05-interview-problems/024_missing_number.cpp), maximum subarray [031](../05-interview-problems/031_maximum_subarray_sum.cpp), longest subarray [033](../05-interview-problems/033_longest_subarray_sum_k.cpp).

---

## M1 - Sorted and rotated?
**Difficulty:** Medium · **Class:** B
**Problem.** Given an array of **distinct** integers, return true if it is an ascending sorted array rotated by some amount (including rotation by 0).
**Constraints.** 1 ≤ n ≤ 10⁵.
**Sample.** `{3, 4, 5, 1, 2}` → true; `{2, 1, 3, 4}` → false; `{1, 2, 3}` → true.
**Approach category.** Single pass counting "drops" in a *circular* sense; reason about how many drops a rotated sorted array can have.
```cpp
bool isSortedAndRotated(const std::vector<int>& a) {
    // TODO
}
```

## M2 - Three Sum
**Difficulty:** Medium · **Class:** B
**Problem.** Return all **unique** triplets `{x, y, z}` (as values) with `x + y + z = 0`. No duplicate triplets; order inside the output does not matter.
**Constraints.** 0 ≤ n ≤ 3000, |a[i]| ≤ 10⁵.
**Sample.** `{-1, 0, 1, 2, -1, -4}` → `{{-1,-1,2}, {-1,0,1}}`.
**Approach category.** Sort, fix one element, two pointers for the rest; handle duplicates. Brute force O(n³); target O(n²).
```cpp
std::vector<std::vector<int>> threeSum(std::vector<int> a) {
    // TODO
}
```

## M3 - Stock buy and sell, unlimited transactions
**Difficulty:** Medium · **Class:** B
**Problem.** `prices[i]` is the price on day i. You may buy and sell many times but hold at most one share at a time. Return the maximum total profit.
**Constraints.** 0 ≤ n ≤ 10⁵, 0 ≤ prices[i] ≤ 10⁴.
**Sample.** `{7, 1, 5, 3, 6, 4}` → `7` (buy 1 sell 5 = 4; buy 3 sell 6 = 3).
**Approach category.** One pass; think about what each day-to-day increase contributes.
```cpp
int maxProfitUnlimited(const std::vector<int>& prices) {
    // TODO
}
```

## M4 - Duplicate and missing number
**Difficulty:** Medium · **Class:** B
**Problem.** An array of n integers has values in `1..n`. Exactly one value appears twice and exactly one value in `1..n` is missing. Return both.
**Constraints.** 2 ≤ n ≤ 10⁵.
**Sample.** `{1, 2, 2, 4}` → duplicate `2`, missing `3`.
**Approach category.** Frequency counting first; then try to reach O(1) extra space (sums / sums of squares, or XOR splitting).
```cpp
// result.first = duplicate, result.second = missing
std::pair<int, int> findDuplicateAndMissing(const std::vector<int>& a) {
    // TODO
}
```

## M5 - Maximum product subarray
**Difficulty:** Medium · **Class:** B
**Problem.** Return the largest product of a non-empty contiguous subarray.
**Constraints.** 1 ≤ n ≤ 2·10⁴, −10 ≤ a[i] ≤ 10; the answer is guaranteed to fit in a 32-bit `int`.
**Sample.** `{2, 3, -2, 4}` → `6`; `{-2, 0, -1}` → `0`.
**Approach category.** Kadane-style, but a negative number can turn the smallest product into the largest: what must you keep track of?
```cpp
int maxProductSubarray(const std::vector<int>& a) {
    // TODO
}
```

## M6 - Longest subarray with sum ≤ K (positive values)
**Difficulty:** Medium · **Class:** B
**Problem.** All elements are positive. Return the length of the longest contiguous subarray whose sum is **at most** K (0 if none).
**Constraints.** 0 ≤ n ≤ 10⁵, 1 ≤ a[i] ≤ 10⁴, 1 ≤ K ≤ 10⁹.
**Sample.** `{2, 1, 3, 1, 1}`, K = 5 → `3`.
**Approach category.** Variable-size sliding window; explain why positivity makes shrinking safe.
```cpp
int longestSubarrayAtMost(const std::vector<int>& a, long long K) {
    // TODO
}
```

## M7 - Product of array except self
**Difficulty:** Medium · **Class:** B
**Problem.** Return `result` where `result[i]` is the product of all elements except `a[i]`. **Do not use division.**
**Constraints.** 2 ≤ n ≤ 10⁵; every prefix/suffix product fits in a 32-bit `int`.
**Sample.** `{1, 2, 3, 4}` → `{24, 12, 8, 6}`.
**Approach category.** Prefix products and suffix products; aim for O(n) time, O(1) extra space beyond the output.
```cpp
std::vector<int> productExceptSelf(const std::vector<int>& a) {
    // TODO
}
```

## M8 - Subarrays with sum divisible by K
**Difficulty:** Medium · **Class:** B
**Problem.** Count contiguous subarrays whose sum is divisible by K. The array may contain negatives.
**Constraints.** 1 ≤ n ≤ 3·10⁴, |a[i]| ≤ 10⁴, 2 ≤ K ≤ 10⁴.
**Sample.** `{4, 5, 0, -2, -3, 1}`, K = 5 → `7`.
**Approach category.** Prefix sums, remainders, frequency counting. Beware C++'s `%` on negative numbers.
```cpp
int subarraysDivByK(const std::vector<int>& a, int K) {
    // TODO
}
```

## M9 - Search in a rotated sorted array
**Difficulty:** Medium · **Class:** B
**Problem.** A sorted ascending array of **distinct** values was rotated at an unknown pivot. Return the index of `target`, or −1. Required: O(log n).
**Constraints.** 1 ≤ n ≤ 10⁵.
**Sample.** `{4, 5, 6, 7, 0, 1, 2}`: target 0 → `4`; target 3 → `-1`.
**Approach category.** Binary search; at each step one half is guaranteed to be sorted: which one, and how does that decide where to go?
```cpp
int searchRotated(const std::vector<int>& a, int target) {
    // TODO
}
```
