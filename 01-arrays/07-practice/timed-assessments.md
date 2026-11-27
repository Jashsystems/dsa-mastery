# Timed Assessments

[← Hard](hard.md) · [Self-assessment](../06-revision/self-assessment.md) · Sets: [easy](easy.md) · [medium](medium.md) · [hard](hard.md)

Timed sets simulate interview pressure. Work alone, in one sitting, with a timer.

## Rules

1. Only the problem statements are open. No notes, no solutions, no search.
2. Compile with `g++ -std=c++17 -Wall -Wextra -Wpedantic`; write at least four tests per problem (empty/single, duplicates, negatives, extremes).
3. Talk or write your reasoning: brute force, optimised idea, complexity, edge cases, before coding.
4. When time is up, stop. Then review.
5. Do **not** attempt problems marked 🔒 or the mentor-assigned [002](../01-basic-operations/002_find_maximum.cpp) / [004](../01-basic-operations/004_second_largest.cpp) in a timed set until they are signed off.

## Sets

| Set | Time | Problems | Focus | Unlock after |
|---|---|---|---|---|
| T1 Foundations | 45 min | [E1](easy.md#e1---alternating-index-sum), [E3](easy.md#e3---reverse-a-subarray), [E5](easy.md#e5---unique-elements-first-occurrences-kept), [E7](easy.md#e7---digit-frequencies) | traversal, two pointers, counting | modules 00–01 |
| T2 In-place & pointers | 60 min | [E4](easy.md#e4---count-adjacent-inversions), [E6](easy.md#e6---move-negatives-to-the-end), [M1](medium.md#m1---sorted-and-rotated), [M3](medium.md#m3---stock-buy-and-sell-unlimited-transactions) | in-place, invariants | module 02 |
| T3 Searching | 60 min | [E8](easy.md#e8---first-repeated-element), [M9](medium.md#m9---search-in-a-rotated-sorted-array), module exercises [021](../03-searching/021_last_occurrence.cpp) and [023](../03-searching/023_upper_bound.cpp) | binary search | module 03 |
| T4 Windows, prefix, Kadane | 75 min | [M5](medium.md#m5---maximum-product-subarray), [M6](medium.md#m6---longest-subarray-with-sum--k-positive-values), [M7](medium.md#m7---product-of-array-except-self), [M8](medium.md#m8---subarrays-with-sum-divisible-by-k) | patterns | modules 04–05 |
| T5 Interview simulation | 90 min | one problem each from [M2](medium.md#m2---three-sum), [M4](medium.md#m4---duplicate-and-missing-number) and one of [H1](hard.md#h1---trapping-rain-water), [H2](hard.md#h2---longest-subarray-with-at-most-k-distinct-values) | mixed, under pressure | T1–T4 passed |
| T6 Hard mock | 120 min | two of [H3](hard.md#h3---subarrays-with-exactly-k-distinct-values), [H4](hard.md#h4---split-array-minimise-the-largest-sum), [H5](hard.md#h5---first-missing-positive), [H6](hard.md#h6---two-non-overlapping-subarrays-of-given-lengths), [H7](hard.md#h7---minimum-days-to-make-m-bouquets), [H8](hard.md#h8---maximum-subarray-sum-with-one-optional-deletion) | top-tier difficulty | T5 passed |

(🔒 E2 joins T1 once Problems 001–002 are signed off.)

## Scoring (per problem, 10 points)

| Criterion | Points |
|---|---|
| Stated a correct brute force with complexity | 1 |
| Identified the right pattern and why | 2 |
| Correct algorithm | 3 |
| Clean, compilable code, no warnings | 1 |
| Edge cases tested and passing | 2 |
| Stated final time and auxiliary space correctly | 1 |

**Passing.** 7 / 10 on every problem in T1–T4; 6 / 10 average in T5–T6. Anything below: review the linked pattern guide, redo the problem after 48 hours, and log it below.

## Review checklist (after every set)

* Which problems did I finish within the time? Which did I not and why (pattern not recognised? bug? slow typing)?
* Did I state brute force first?
* Did my first dry run catch bugs before compiling?
* Which edge case did I forget?
* What one sentence summarises the idea of each problem?

## Session log template

```
Date:            ____
Set:             T_
Time used:       ____ / ____ min
Problem scores:  ____ , ____ , ____ , ____
Patterns I missed:
Bugs I introduced:
Re-do on (date): ____
```
