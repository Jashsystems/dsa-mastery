# Searching - Explanations

[← Module index](../README.md) · Pattern background: [binary search in the pattern guide](../04-array-patterns/explanations.md#3-binary-search)

| File | Title | Type |
|---|---|---|
| [018](018_linear_search.cpp) | Linear search | Worked example |
| [019](019_binary_search_intro.cpp) | Binary search (introduction) | Worked example |
| [020](020_first_occurrence.cpp) | First occurrence | Worked example |
| [021](021_last_occurrence.cpp) | Last occurrence | Exercise |
| [022](022_lower_bound.cpp) | Lower bound | Worked example |
| [023](023_upper_bound.cpp) | Upper bound | Exercise |

---

## 018 - Linear search  *(Worked example)*

1. **Problem.** Return the index of the first occurrence of `target`, or −1.
2. **Input / output.** `{4,8,8,1}`, target 8 → `1`; target 5 → `-1`.
3. **Intuition.** With no structure to exploit, any element could be the target, so every element must be inspected in the worst case.
4. **Brute force.** This *is* the brute force and it is optimal for unsorted data.
5. **Optimised approach.** Early exit on the first match; nothing asymptotically better exists without preprocessing (sorting or hashing).
6. **Algorithm.** For `i = 0 … n-1`: if `a[i] == target` return `i`. After the loop return −1.
7. **Dry run.** `{4,8,8,1}`, target 8: i=0 → 4 ≠ 8; i=1 → 8 = 8, return 1.
8. **Code.** [018_linear_search.cpp](018_linear_search.cpp)
9. **Time.** O(n) worst, O(1) best.
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty vector; target absent; target repeated (first index returned); target at the last position.
12. **Common mistakes.** Returning 0 for "not found" (0 is a valid index); returning from inside the `else` branch.
13. **When to use.** Unsorted data searched once; tiny arrays; when sorting would cost more than one scan.
14. **Interview relevance.** Baseline you must beat; ask "is the array sorted?" before choosing.
15. **Revision question.** Why is sorting first (O(n log n)) a bad plan for a single search?

---

## 019 - Binary search (introduction)  *(Worked example)*

1. **Problem.** In a sorted vector, find an index of `target` or report −1.
2. **Input / output.** `{1,3,5,7,9}`, target 7 → `3`; target 4 → `-1`.
3. **Intuition.** Sorting turns one comparison with the middle element into information about half the array: if `a[mid] < target`, everything at or left of `mid` is too small. Halving repeatedly leaves one candidate after about log₂ n steps.
4. **Brute force.** Linear scan: O(n).
5. **Optimised approach.** Maintain the invariant "if target exists it lies in `a[left..right]`" and shrink the range each step.
6. **Algorithm.** `left = 0`, `right = n-1`. While `left <= right`: `mid = left + (right-left)/2`; equal → return mid; `a[mid] < target` → `left = mid+1`; else `right = mid-1`. Return −1.
7. **Dry run (found).** `{1,3,5,7,9}`, target 7: l=0, r=4, mid=2 (5 < 7) → l=3; mid=3 (7) → return 3.
   **Dry run (absent).** target 4: mid=2 (5 > 4) → r=1; mid=0 (1 < 4) → l=1; mid=1 (3 < 4) → l=2; now l > r → −1.
8. **Code.** [019_binary_search_intro.cpp](019_binary_search_intro.cpp)
9. **Time.** O(log n).
10. **Auxiliary space.** O(1) iteratively.
11. **Edge cases.** Empty (loop skipped); single element; target smaller than all / larger than all; duplicates (returns *an* index, not necessarily first).
12. **Common mistakes.** `while (left < right)` with `right = n-1` style bounds (skips the last candidate); `left = mid` or `right = mid` in this variant (infinite loop); `(left + right) / 2` overflow; running on unsorted data.
13. **When to use.** Sorted (or monotonic) data and a yes/no or order question.
14. **Interview relevance.** One of the most-asked topics; mistakes in boundaries are what interviewers look for.
15. **Revision question.** Why does `right = mid - 1` (not `right = mid`) guarantee termination here?

---

## 020 - First occurrence  *(Worked example)*

1. **Problem.** Index of the leftmost element equal to `target` in a sorted vector.
2. **Input / output.** `{1,2,2,2,3}`, target 2 → `1`.
3. **Intuition.** A match proves a candidate but does not prove it is the leftmost; so record it and keep searching strictly to the left.
4. **Brute force.** Linear scan: O(n).
5. **Optimised approach.** Binary search that continues after a match.
6. **Algorithm.** Standard loop; on `a[mid] == target`: `answer = mid; right = mid - 1`.
7. **Dry run.** `{1,2,2,2,3}`, target 2: l=0,r=4,mid=2 (2) → ans 2, r=1; mid=0 (1 < 2) → l=1; mid=1 (2) → ans 1, r=0; l > r → return 1.
8. **Code.** [020_first_occurrence.cpp](020_first_occurrence.cpp)
9. **Time.** O(log n) (a linear scan over equal elements would degrade to O(n)).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Absent target (−1); all elements equal; target at index 0 or n−1; empty.
12. **Common mistakes.** Returning at the first match (any occurrence, not the first); forgetting to initialise `answer = -1`.
13. **When to use.** Counting occurrences (`last − first + 1`), range queries on sorted data.
14. **Interview relevance.** Standard follow-up to plain binary search.
15. **Revision question.** How do you count how many times `target` occurs in O(log n)?

## 021 - Last occurrence  *(Exercise)*

* **Problem.** Index of the rightmost element equal to `target` in a sorted vector, or −1. `{1,2,2,2,3}`, target 2 → `3`.
* **Constraints.** 0 ≤ n ≤ 10⁵; must be O(log n).
* **Edge cases.** Absent; all equal; target at the ends; empty.
* **Revision question.** Which single line of your 020 code has to change, and which way does the search move after a match?

---

## 022 - Lower bound  *(Worked example)*

1. **Problem.** First index with `a[i] >= target` (n if none).
2. **Input / output.** `{1,3,3,5}`: target 3 → 1; target 4 → 3; target 9 → 4; target 0 → 0.
3. **Intuition.** The predicate `a[i] >= target` is false for a prefix and true for the rest (sorted data). Finding the first `true` is the universal binary-search template: shrink until the boundary is trapped.
4. **Brute force.** Scan for the first `a[i] >= target`: O(n).
5. **Optimised approach.** Half-open range `[left, right)` starting at `[0, n)`. The answer is always within `[left, right]`.
6. **Algorithm.** While `left < right`: `mid = left + (right-left)/2`; if `a[mid] < target` then `left = mid+1` else `right = mid`. Return `left`.
7. **Dry run.** `{1,3,3,5}`, target 3: [0,4) mid=2 (3, not < 3) → right=2; mid=1 (3) → right=1; mid=0 (1 < 3) → left=1; left = right = 1 → answer 1 ✓. Target 4: [0,4) mid=2 (3 < 4) → left=3; mid=3 (5, not < 4) → right=3 → answer 3 ✓.
8. **Code.** [022_lower_bound.cpp](022_lower_bound.cpp)
9. **Time.** O(log n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty (returns 0); target below all (0); above all (n); duplicates (leftmost).
12. **Common mistakes.** Initialising `right = n-1` with this template; using `<=` in the loop condition; returning `-1` for "none" (the convention is n).
13. **When to use.** "Insert position", "first element not less than", counting elements `< x`, and *binary search on answer* with a monotone yes/no test.
14. **Interview relevance.** Many hard problems reduce to this template; matches `std::lower_bound`.
15. **Revision question.** What does `lower_bound(x)` return if every element is smaller than `x`?

## 023 - Upper bound  *(Exercise)*

* **Problem.** First index with `a[i] > target` (n if none). `{1,3,3,5}`: target 3 → 3; target 5 → 4.
* **Constraints.** 0 ≤ n ≤ 10⁵; O(log n).
* **Edge cases.** Empty; target below all; above all; many duplicates of the target.
* **Revision question.** How do `upper_bound(x) − lower_bound(x)` and the count of `x` relate, and why?
