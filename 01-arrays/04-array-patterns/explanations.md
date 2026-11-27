# Array Patterns - Pattern Recognition Guide

[← Module index](../README.md) · Deep dives: [two pointers](two-pointers.md) · [sliding window](sliding-window.md) · [prefix sums](prefix-sum.md) · [frequency arrays](frequency-arrays.md)

A **pattern** is a reusable way of organising a traversal. Never memorise solutions: learn *what each pattern needs to be true*, then check those conditions against a new problem.

## 1. How to recognise a pattern from an unfamiliar problem

Ask these questions in order:

| # | Question | If yes, think of |
|---|---|---|
| 1 | Is the input **sorted** (or does the answer have a yes/no monotone test)? | [binary search](#3-binary-search), two pointers |
| 2 | Does the problem ask about **contiguous** subarrays? | sliding window, prefix sums, Kadane |
| 3 | Are all values **non-negative** and the condition about a window's sum/size? | [sliding window](sliding-window.md) |
| 4 | **Negative numbers** with subarray sums? | [prefix sums](prefix-sum.md), [Kadane](#4-kadanes-algorithm) |
| 5 | Is it about **pairs** `(i, j)`? | sorted → two pointers; unsorted → hash map |
| 6 | "In place", "O(1) space", "remove/partition"? | [slow & fast pointers](two-pointers.md#2-same-direction-slow-and-fast-pointers) |
| 7 | "How many times", duplicates, anagrams? | [frequency counting](frequency-arrays.md) |
| 8 | One pass keeping a summary of everything seen so far? | [running summary](#2-linear-traversal-and-running-summaries) |
| 9 | n ≤ 20 or so, "all subsets/orderings"? | brute-force enumeration (outside this module) |

**Then use the constraints** ([complexity guide](../00-foundations/array-complexity.md#7-why-input-constraints-matter)): n up to 10⁵ rules out any nested loop over all pairs.

### Pattern summary

| Pattern | Core condition | Typical cost | Files |
|---|---|---|---|
| Linear traversal + running summary | answer is a function of what has been seen | O(n), O(1) | 001, 007, 008, 025, 030 |
| Two variables | the answer needs the best **and** the runner-up / current **and** best | O(n), O(1) | 025, 030 and the assigned exercises |
| In-place modification | output fits in the input array, order rule known | O(n), O(1) | 006, 010–016 |
| Two pointers (opposite) | sorted or symmetric | O(n) | 006, two-pointers.md |
| Slow & fast pointers | filtering / compaction | O(n) | 013, 014, 015 |
| Sliding window | contiguous + monotone window property | O(n) | sliding-window.md |
| Prefix sums | static data, range sums | O(n) + O(1) per query | prefix-sum.md |
| Frequency counting | equality, counts, small value range | O(n) | 009 |
| Kadane | best subarray ending at i builds on i−1 | O(n), O(1) | 031 |
| Binary search | monotone predicate over indices or answers | O(log n) | 019–023 |

## 2. Linear traversal and running summaries

Many array problems are solved in **one pass** carrying a small amount of *state* that summarises the prefix seen so far.

Design recipe:

1. **State:** what is the smallest summary of the prefix that lets me process the next element? (a count, a best-so-far, a current run, …)
2. **Initialise** the state from the *data* (e.g. the first element) or from a value that is neutral for the operation: never from an arbitrary constant that real data could beat or tie.
3. **Update rule:** how does one new element change the state? Often it either improves the answer, extends the current candidate, or resets it.
4. **Answer:** read it from the state after the loop (or update it inside).

**Worked example: longest strictly increasing run.** State: `current` (length of the run ending here), `best`.

```cpp
int current = 1, best = 1;                    // a[0] is a run of length 1 (precondition: n >= 1)
for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1]) ++current;           // extends the run
    else current = 1;                         // breaks the run, a[i] starts a new one
    if (current > best) best = current;
}
```
Dry run `{1,3,5,4,7,8,9,2}`: current/best → (1,1), 3>1 (2,2), 5>3 (3,3), 4>5 no (1,3), 7>4 (2,3), 8>7 (3,3), 9>8 (4,4), 2>9 no (1,4). Answer 4 (`4,7,8,9`).

**Maintaining a running maximum / minimum.** The same recipe applies: the state is the extreme so far, the update compares each new element to it. **Maintaining two variables** (for example a best value together with a runner-up) means asking: *which comparisons change the first variable, which change only the second, and which change neither?* The assigned problems ([002](../01-basic-operations/002_find_maximum.cpp) and [004](../01-basic-operations/004_second_largest.cpp)) are yours to design with this recipe; this guide deliberately stops here.

Pitfalls: initialising with `0` or `INT_MIN` blindly; forgetting the empty-array case; updating state in the wrong order inside the loop.

## 3. Binary search

**Precondition:** the data (or the answer space) has a **monotone** property: a predicate that is `false … false true … true` across the range.

**Invariant thinking.** Decide what is *always true* about `[left, right)` (or `[left, right]`) and make each step shrink it while keeping that true. Three templates:

| Template | Range | Loop | Update | Result |
|---|---|---|---|---|
| Exact match ([019](../03-searching/019_binary_search_intro.cpp)) | `[left, right]` closed | `while (left <= right)` | `left = mid+1` / `right = mid-1` | index or −1 |
| First position where predicate is true ([022](../03-searching/022_lower_bound.cpp)) | `[left, right)` half-open | `while (left < right)` | true → `right = mid`, false → `left = mid+1` | `left` |
| Binary search **on the answer** | `[lo, hi)` over *possible answers* | same as above | predicate = "is answer x feasible?" | smallest feasible x |

**Worked example: binary search on the answer.** Smallest integer `x` with `x*x >= 30`.

```cpp
int lo = 0, hi = 30;                         // answer is somewhere in [0, 30]
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (static_cast<long long>(mid) * mid >= 30) hi = mid;   // feasible: answer is mid or smaller
    else lo = mid + 1;                                       // not feasible: answer is larger
}
// lo == 6
```
Dry run: [0,30) mid 15 (225 ≥ 30) → hi 15; mid 7 (49) → hi 7; mid 3 (9) → lo 4; mid 5 (25) → lo 6; mid 6 (36) → hi 6; lo = hi = 6 ✓.

**Recognise "binary search on the answer":** the statement asks to *minimise a maximum* or *maximise a minimum* ("smallest capacity such that …", "largest distance such that …") and checking one candidate answer takes O(n). See [hard.md](../07-practice/hard.md).

Pitfalls: `(left+right)/2` overflow; `right = mid` inside a `left <= right` loop (infinite); using it on unsorted data; wrong "none" value.

## 4. Kadane's algorithm

**Problem:** maximum sum of a non-empty contiguous subarray ([031](../05-interview-problems/031_maximum_subarray_sum.cpp)).

**Why it works.** Let `E[i]` = best sum of a subarray **ending exactly at i**. Such a subarray is either `{a[i]}` alone or a subarray ending at `i−1` extended by `a[i]`; extending only makes sense with the *best* one, so

```
E[i] = max(a[i], E[i-1] + a[i])        answer = max over all i of E[i]
```
Every subarray ends somewhere, so the best overall is the best `E[i]`. The key insight: a **negative** running total is dead weight; dropping it is never worse than carrying it.

Dry run on `{-2,1,-3,4,-1,2,1,-5,4}`:

| i | a[i] | E[i] | best |
|---|---|---|---|
| 0 | −2 | −2 | −2 |
| 1 | 1 | max(1, −1) = 1 | 1 |
| 2 | −3 | max(−3, −2) = −2 | 1 |
| 3 | 4 | max(4, 2) = 4 | 4 |
| 4 | −1 | 3 | 4 |
| 5 | 2 | 5 | 5 |
| 6 | 1 | 6 | 6 |
| 7 | −5 | 1 | 6 |
| 8 | 4 | 5 | 6 |

**Recognise it:** "maximum/minimum sum of a **contiguous** subarray", negatives present, O(n) required. It is dynamic programming with a one-number state. Variants: return the indices (remember where the current subarray started); minimum sum (flip signs); circular arrays (combine with the total sum).

Pitfalls: initialising the best with `0` (wrong for all-negative arrays); `int` overflow.

## 5. In-place modification

**Recipe.**

1. Decide the **final layout** (kept elements in front? zeros at the back?).
2. Choose a **write position** `w` and a **read position** `r` with `w <= r`, so writing never destroys unread data.
3. State the invariant: *"`a[0..w-1]` is correct for everything before `r`."*
4. For **shifting**, pick the direction that does not overwrite data you still need: shifting left → loop forwards; shifting right → loop backwards.
5. Return the new logical length if the tail is "garbage".

Examples: [006 reverse](../01-basic-operations/006_reverse_array.cpp), [010 left rotate](../02-array-manipulation/010_left_rotate.cpp), [012 rotate by k](../02-array-manipulation/012_rotate_by_k.cpp), [013 move zeroes](../02-array-manipulation/013_move_zeroes.cpp), [014 remove duplicates](../02-array-manipulation/014_remove_duplicates.cpp), [016 insert](../02-array-manipulation/016_insert_element.cpp).

## 6. Common errors across patterns

* Choosing a pattern before checking its precondition (sorted? non-negative? contiguous?).
* Not stating the invariant.
* Ignoring n = 0 and n = 1.
* Forgetting that a hash map costs O(n) memory.
* Memorising code instead of the *reason* it works.

## 7. Revision questions

1. Which two conditions must hold for a variable-size sliding window on sums?
2. A problem asks for the number of subarrays with sum k and the array has negatives. Which pattern family do you reject, and why?
3. State the predicate you would binary search on for "smallest x such that `x*x >= n`".
4. In Kadane's recurrence, why can you throw away a negative running total?

<details><summary>Answers</summary>

1. Contiguous subarray and monotone behaviour (non-negative elements).
2. Sliding window: with negatives the window sum is not monotone, so shrinking is unsafe.
3. `mid * mid >= n` (false for small mid, true afterwards).
4. Any subarray that continues past it would do at least as well starting fresh.

</details>
