# Sliding Window

[← Two pointers](two-pointers.md) · [Pattern guide](explanations.md) · Next: [Prefix sums](prefix-sum.md)

**Idea:** a *window* `[left, right]` over a contiguous part of the array. Instead of recomputing the window's value from scratch, **update it** when the window moves: add the entering element, remove the leaving one.

## 1. Fixed-size window

**Problem.** Maximum sum of any `k` consecutive elements.

```cpp
long long windowSum = 0;
for (int i = 0; i < k; ++i) windowSum += a[i];      // first window
long long best = windowSum;
for (int i = k; i < n; ++i) {
    windowSum += a[i] - a[i - k];                   // add entering, remove leaving
    best = std::max(best, windowSum);
}
```
(Precondition: `1 <= k <= n`.)

**Dry run.** `a = {2,1,5,1,3,2}`, k = 3:

| window | sum |
|---|---|
| [2,1,5] | 8 |
| [1,5,1] | 8 + 1 − 2 = 7 |
| [5,1,3] | 7 + 3 − 1 = 9 |
| [1,3,2] | 9 + 2 − 5 = 6 |

Best = 9. Brute force (re-summing each window) is O(n·k); the sliding window is **O(n)**.

## 2. Variable-size window

The window grows on the right and shrinks on the left depending on a condition.

**Problem.** Length of the shortest subarray whose sum is **≥ target** (all elements positive).

```cpp
int left = 0, best = INT_MAX;
long long sum = 0;
for (int right = 0; right < n; ++right) {
    sum += a[right];                         // expand
    while (sum >= target) {                  // window is valid: try to shrink
        best = std::min(best, right - left + 1);
        sum -= a[left];
        ++left;
    }
}
// best == INT_MAX means no valid window
```

**Dry run.** `a = {2,3,1,2,4,3}`, target 7:

| right | sum after adding | shrinking steps | best |
|---|---|---|---|
| 0 | 2 | – | ∞ |
| 1 | 5 | – | ∞ |
| 2 | 6 | – | ∞ |
| 3 | 8 | len 4 → drop 2 → sum 6 | 4 |
| 4 | 10 | len 4, drop 3 → 7: len 3, drop 1 → 6 | 3 |
| 5 | 9 | len 3, drop 2 → 7: len 2 (`[4,3]`), drop 4 → 3 | **2** |

Answer 2. Each index enters the window once and leaves at most once: **O(n)** total although there is a `while` inside the `for`.

## 3. Why shrinking is correct (the monotonicity requirement)

With **non-negative** elements, adding an element never decreases the sum and removing one never increases it. So once `[left, right]` is valid, no longer window starting at `left` can be *shorter*, and `left` can be advanced safely. That monotone behaviour is what the shrink step relies on.

**With negative numbers it breaks:** removing a negative element *increases* the sum, so "shrink while valid" can skip the best answer. Use [prefix sums](prefix-sum.md) for those problems.

## 4. General template

```
left = 0
for right in 0..n-1:
    add a[right] to the window state
    while the window violates the rule:       # (or: while it is valid, for "shortest" problems)
        remove a[left] from the window state
        left++
    update the answer using the window [left, right]
```

The **window state** can be a sum, a count of zeros, a frequency table (distinct elements), etc.

## 5. Recognising the pattern

| Signal | Why a window |
|---|---|
| "contiguous subarray / substring" | a window is contiguous by definition |
| "longest / shortest / count of subarrays with property P" | optimise over windows |
| P is maintainable incrementally (sum ≤ S, at most k zeros, at most k distinct) | O(1) update per move |
| elements non-negative (for sum conditions) | monotonicity |
| "window of size k" | fixed window |

## 6. Common mistakes

* Using a variable window with negative numbers.
* Off-by-one in length: it is `right - left + 1`.
* Forgetting to handle "no valid window" (best stays at its initial value).
* Re-summing the window inside the loop (turns O(n) into O(n·k)).
* `int` overflow of the running sum.
* Not moving `left` enough (`if` instead of `while`).

## 7. Related problems

[Max consecutive ones](../05-interview-problems/025_max_consecutive_ones.cpp) (a special case); more in the [practice sets](../07-practice/medium.md) and [hard](../07-practice/hard.md) (at most k distinct values, exactly k distinct).

## 8. Revision questions

1. Why does a fixed window update in O(1)?
2. Why is the `while` inside the `for` still O(n)?
3. Give an array for which the variable-window shortest-subarray method gives a wrong answer.

<details><summary>Answers</summary>

1. Add the entering element and subtract the leaving one; no recomputation.
2. `left` only moves forward and at most n times in total.
3. `{1, -1, 2}` with target 2. The correct answer is 1 (the subarray `{2}`), but the window only reaches a valid state at `right = 2` with sum 2 and length 3; shrinking by one drops the sum to 1 (< 2), so it reports 3. Negative numbers destroy the monotonicity the shrink step needs.

</details>
