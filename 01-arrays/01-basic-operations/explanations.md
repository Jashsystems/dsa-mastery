# Basic Operations - Explanations

[← Module index](../README.md) · Prerequisites: [foundations](../00-foundations/array-fundamentals.md)

Each **worked example** below follows the same 15 points. **Exercises** get a shorter entry (statement, I/O, edge cases, target, revision question) so you can attempt them first; their reference solutions, when released, live in [`../solutions/`](../solutions/solution-notes.md).

| File | Title | Type |
|---|---|---|
| [001](001_array_traversal.cpp) | Array traversal | Worked example |
| [002](002_find_maximum.cpp) | Find the maximum - **mentor Problem 001** | Exercise (assigned, no solution) |
| [003](003_find_minimum.cpp) | Find the minimum | Exercise (after 002 is signed off) |
| [004](004_second_largest.cpp) | Second largest distinct - **mentor Problem 002** | Exercise (assigned, no solution) |
| [005](005_second_smallest.cpp) | Second smallest distinct | Exercise (after 004 is signed off) |
| [006](006_reverse_array.cpp) | Reverse an array | Worked example |
| [007](007_check_sorted.cpp) | Check sorted | Worked example |
| [008](008_sum_of_elements.cpp) | Sum of elements | Worked example |
| [009](009_frequency_count.cpp) | Frequency count | Worked example |

---

## 001 - Array traversal  *(Worked example)*

1. **Problem.** Visit each element of a vector once and build a text form `[a, b, c]` forwards, with a range-for loop, and backwards.
2. **Input / output.** `{1, 2, 3}` → `"[1, 2, 3]"` and `"[3, 2, 1]"`.
3. **Intuition.** Every array algorithm is "visit the elements in some order, remember something". Learning to write that visit loop correctly (no off-by-one, safe on empty input) is the foundation of everything that follows.
4. **Brute force.** There is none: any algorithm that needs to look at every element needs at least n steps, so a plain scan is already optimal.
5. **Optimised approach.** Same scan; the only choices are loop style (index vs range-for vs reverse).
6. **Algorithm.** Index loop: `i = 0 … n-1`. Range-for: let C++ iterate. Reverse: `i = n-1 … 0` using a signed `int`.
7. **Dry run.** `a = {1,2,3}`, n = 3. Forward: i=0 → "1", i=1 → ", 2", i=2 → ", 3". Backward: i=2 → "3, ", i=1 → "2, ", i=0 → "1". The loop condition fails when i = −1.
8. **Code.** [001_array_traversal.cpp](001_array_traversal.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1) besides the output string.
11. **Edge cases.** Empty vector (loops never run, result `[]`); single element (no comma).
12. **Common mistakes.** `i <= n`; unsigned loop variable counting down; forgetting that range-for copies each element.
13. **When to use.** Index loop when you need positions; range-for for read-only passes; reverse loop when later elements must be handled first.
14. **Interview relevance.** Interviewers expect flawless loop bounds; most "easy" bugs are boundary bugs.
15. **Revision question.** Why does `for (size_t i = a.size()-1; i >= 0; --i)` never terminate?

---

## 002 - Find the maximum element  *(Exercise - mentor Problem 001)*

* **Status:** ASSIGNED. Not solved here and intentionally not explained: the solution is yours to find.
* **Problem.** Return the largest value of a non-empty vector. **Input:** `{3, 9, 2}`. **Output:** `9`.
* **Constraints.** 1 ≤ n ≤ 10⁵, full `int` range, never empty.
* **Edge cases to design for.** Single element; all negative values; all identical; maximum appears more than once; `INT_MIN` / `INT_MAX` present. *Ask yourself:* what should your "best so far" start as, and why is `0` a dangerous answer?
* **Target.** O(n) time, O(1) auxiliary space, your own loop (no `std::max_element`).
* **Revision question (answer it in your own words after solving).** How many comparisons does your solution make for n elements, and could any algorithm use fewer?

## 003 - Find the minimum element  *(Exercise)*

* **Do after 002.** Problem: smallest value of a non-empty vector, e.g. `{3, 9, 2}` → `2`. Same constraints and target as 002 (O(n), O(1)).
* **Edge cases.** Single element, all negative, all identical, boundary values.
* **Revision question.** What exactly changes between your solution to 002 and this one?

## 004 - Second largest distinct element  *(Exercise - mentor Problem 002)*

* **Status:** ASSIGNED. No solution or approach is given.
* **Problem.** Return the second largest **distinct** value; report "no answer" if fewer than 2 distinct values exist. **Examples:** `{1,2,3,4}` → 3; `{10,10,9}` → 9; `{5,5,5}` → none.
* **Constraints.** 0 ≤ n ≤ 10⁵ (empty allowed), full `int` range.
* **Edge cases to design for.** Empty; single element; all identical; duplicates of the maximum; `INT_MIN` as a legitimate answer (so a sentinel such as `INT_MIN` cannot mean "none"); exactly two distinct values.
* **Target.** One pass, O(n) time, O(1) space, no sorting, no `std::set`.
* **Revision question.** In your solution, which situations make the "second" variable change, and which leave it alone?

## 005 - Second smallest distinct element  *(Exercise)*

* **Do after 004.** Same contract as 004 mirrored for the smallest values; e.g. `{4,1,3,1}` → 3; `{2,2}` → none.
* **Target.** One pass, O(n), O(1).
* **Revision question.** Which parts of your 004 solution did you reuse unchanged, and which comparisons flipped?

---

## 006 - Reverse an array in place  *(Worked example)*

1. **Problem.** Reverse the vector without allocating a second one.
2. **Input / output.** `{1,2,3,4,5}` → `{5,4,3,2,1}`.
3. **Intuition.** Element `i` must end up at position `n-1-i`. Swapping the two ends, then the next two inward, places every element exactly once, and the pairs never interfere with each other.
4. **Brute force.** Copy the elements into a new vector in reverse order: O(n) time but O(n) extra space.
5. **Optimised approach.** Two pointers from both ends swapping in place: O(n) time, **O(1)** space.
6. **Algorithm.** `left = 0`, `right = n-1`; while `left < right`: swap `a[left]`, `a[right]`; `++left`, `--right`.
7. **Dry run.** `{1,2,3,4,5}`: (l=0,r=4) swap → `{5,2,3,4,1}`; (1,3) swap → `{5,4,3,2,1}`; (2,2) stop. The middle element 3 stays put.
8. **Code.** [006_reverse_array.cpp](006_reverse_array.cpp)
9. **Time.** O(n) (n/2 swaps).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty (`right = -1`, loop skipped); single element; even vs odd length.
12. **Common mistakes.** Looping `i` over the whole array (reverses twice = unchanged); `left <= right` (harmless self-swap, but a sign of unclear thinking); using `size_t` for `right`.
13. **When to use.** Whenever a problem is symmetric about the centre (palindromes, reversal-based rotation).
14. **Interview relevance.** Warm-up for two pointers; reversal is the building block of the [rotate by k](../02-array-manipulation/012_rotate_by_k.cpp) trick.
15. **Revision question.** Why do we stop when `left >= right` rather than running to the end?

---

## 007 - Check whether an array is sorted  *(Worked example)*

1. **Problem.** True if `a[0] ≤ a[1] ≤ … ≤ a[n-1]`.
2. **Input / output.** `{1,2,2,5}` → true; `{1,3,2}` → false.
3. **Intuition.** Sortedness is a *local* property: if each neighbouring pair is ordered, transitivity of `≤` makes the whole array ordered. One bad neighbouring pair is a proof of "not sorted".
4. **Brute force.** Compare every pair `(i, j)` with `i < j`: O(n²).
5. **Optimised approach.** Compare only neighbours: O(n), with early exit.
6. **Algorithm.** For `i = 1 … n-1`: if `a[i-1] > a[i]` return false. After the loop return true.
7. **Dry run.** `{1,3,3,2}`: i=1: 1>3? no. i=2: 3>3? no. i=3: 3>2? yes → return false.
8. **Code.** [007_check_sorted.cpp](007_check_sorted.cpp)
9. **Time.** O(n) worst case; O(1) best case.
10. **Auxiliary space.** O(1).
11. **Edge cases.** n = 0 and n = 1 are sorted; equal neighbours are allowed (non-decreasing), but if the problem says "strictly increasing" use `>=`.
12. **Common mistakes.** Starting at `i = 0` (reads `a[-1]`); using `>=` when duplicates are allowed; returning true/false inside the loop for the wrong branch.
13. **When to use.** Validating a precondition (before binary search), or detecting the first "violation".
14. **Interview relevance.** Variants: strictly sorted, sorted descending, sorted *and rotated*, "fix with one swap".
15. **Revision question.** How would the loop change for "strictly decreasing"?

---

## 008 - Sum of elements  *(Worked example)*

1. **Problem.** Return the sum of all elements.
2. **Input / output.** `{4, -1, 6}` → `9`; `{INT_MAX, INT_MAX}` → `4294967294`.
3. **Intuition.** A running total absorbs each element once. The real lesson is the **type** of the total.
4. **Brute force.** None needed; one pass is optimal.
5. **Optimised approach.** Same pass, with a `long long` accumulator so the sum can exceed `int`.
6. **Algorithm.** `total = 0`; for each value: `total += value`; return `total`.
7. **Dry run.** `{4,-1,6}`: total 0 → 4 → 3 → 9.
8. **Code.** [008_sum_of_elements.cpp](008_sum_of_elements.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty (0); extremes whose sum overflows `int`; negatives cancelling to zero.
12. **Common mistakes.** `int total`; `std::accumulate(..., 0)` (an `int` start value makes the whole sum `int`); `long long total = a[0] + a[1]` evaluated in `int` first.
13. **When to use.** Totals, averages, and as a building block ([prefix sums](../04-array-patterns/prefix-sum.md), [missing number](../05-interview-problems/024_missing_number.cpp)).
14. **Interview relevance.** Overflow awareness is a standard follow-up question.
15. **Revision question.** Up to what n can n values of size 10⁹ be summed safely in a 32-bit `int`?

---

## 009 - Frequency count  *(Worked example)*

1. **Problem.** Count how many times each distinct value occurs.
2. **Input / output.** `{2,0,2,1,2}` → count of 0 is 1, of 1 is 1, of 2 is 3.
3. **Intuition.** Rather than comparing elements to each other, use the value as an *address*: a counter per possible value, updated in O(1).
4. **Brute force.** For each element, scan the whole array and count equal ones: O(n²).
5. **Optimised approach.** One pass with a counting array (values in a small range `0..maxValue`) or a `std::map` (any values).
6. **Algorithm.** Create counters initialised to 0; for each value: `++count[value]`.
7. **Dry run.** `{2,0,2,1,2}`, maxValue 2, `count = [0,0,0]`: 2 → `[0,0,1]`; 0 → `[1,0,1]`; 2 → `[1,0,2]`; 1 → `[1,1,2]`; 2 → `[1,1,3]`.
8. **Code.** [009_frequency_count.cpp](009_frequency_count.cpp)
9. **Time.** Counting array O(n + maxValue); map O(n log d).
10. **Auxiliary space.** O(maxValue) or O(d), d = number of distinct values.
11. **Edge cases.** Empty input; negatives (rule out the counting array); huge values (rule out the counting array); all identical.
12. **Common mistakes.** Index out of range when a value exceeds `maxValue`; sizing the counter `maxValue` instead of `maxValue + 1`; using a counting array for values up to 10⁹.
13. **When to use.** Duplicates, anagrams, "most frequent", "does every value appear twice" - see [frequency arrays](../04-array-patterns/frequency-arrays.md).
14. **Interview relevance.** Appears inside dozens of problems; knowing when a counting array beats a map shows judgement.
15. **Revision question.** What constraint on the values decides between a counting array and a `std::map`?
