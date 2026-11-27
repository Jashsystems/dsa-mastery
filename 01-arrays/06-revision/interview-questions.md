# Interview Questions (Arrays)

[← Module index](../README.md) · Practice problems: [easy](../07-practice/easy.md) · [medium](../07-practice/medium.md) · [hard](../07-practice/hard.md)

Answer aloud first, then expand the answer. Coding prompts have no answers here: solve them, or find the related file in the module.

## Part A - Concept questions

<details><summary>1. Why is array access O(1)?</summary>
Elements are contiguous, so the address of `a[i]` is `base + i × sizeof(element)`: one multiplication and addition regardless of i.
</details>

<details><summary>2. Why is inserting in the middle of an array O(n)?</summary>
There is no free gap; all elements after the insertion point shift one position. At the front that is n elements.
</details>

<details><summary>3. Explain "amortised O(1)" for <code>push_back</code>.</summary>
Most appends write into spare capacity (O(1)). Occasionally the vector reallocates and copies all n elements (O(n)), but with geometric growth (e.g. doubling) the copies are rare enough that the average cost per append over many appends is constant.
</details>

<details><summary>4. Array vs vector: which would you use and why?</summary>
Vector by default: it knows its size, is resizable, copies and compares by value, and has the same contiguous O(1) indexing. A fixed `std::array` or C array only when the size is a small compile-time constant.
</details>

<details><summary>5. What is the difference between time complexity and auxiliary space?</summary>
Time counts steps as input grows; auxiliary space counts extra memory beyond the input. A reversal is O(n) time and O(1) auxiliary space; a hash-map Two Sum is O(n) time and O(n) auxiliary space.
</details>

<details><summary>6. When can you use binary search?</summary>
When the data (or the answer space) satisfies a monotone predicate: false … false true … true. Sorted arrays are the most common case.
</details>

<details><summary>7. Why do sliding windows fail with negative numbers?</summary>
Shrinking a window should never increase a sum and growing it never decrease it. With negatives both can happen, so the decision "shrink now" is no longer safe. Prefix sums with a lookup structure handle negatives.
</details>

<details><summary>8. What does "in place" mean?</summary>
Uses O(1) auxiliary space: the output is built in the input array with a constant number of extra variables.
</details>

<details><summary>9. Why is two-pointers with a nested <code>while</code> still O(n)?</summary>
Pointers only move forward; each index is passed at most once per pointer, so total movement is at most 2n.
</details>

<details><summary>10. How do you rotate an array by k in O(n) time and O(1) space?</summary>
Reduce `k %= n`, then reverse the whole array, the first k elements and the remaining n − k elements (for a right rotation).
</details>

<details><summary>11. Hash map Two Sum is O(n); why might it be O(n²) in the worst case?</summary>
Hash operations are O(1) on average; adversarial inputs that all collide make each operation O(n).
</details>

<details><summary>12. Why must you be careful with <code>size() - 1</code>?</summary>
`size()` is unsigned; for an empty container the subtraction wraps around to a huge value.
</details>

<details><summary>13. Best, average and worst case of linear search?</summary>
Best O(1) (first element), average about n/2 comparisons = O(n), worst O(n) (last element or absent).
</details>

<details><summary>14. What is a loop invariant and why state it?</summary>
A condition true before every iteration. It lets you prove correctness and reveals off-by-one errors: the body only needs to preserve it, and when the loop ends the invariant plus the exit condition imply the result.
</details>

## Part B - Coding prompts by topic (with typical follow-ups)

| Topic | Prompt | Expect to be asked |
|---|---|---|
| Traversal | Print / sum elements in forward and reverse order | overflow; empty input |
| Reversal | Reverse an array in place | now reverse only part of it; now recursively |
| Sortedness | Is the array sorted? | strictly sorted; sorted and rotated |
| Rotation | Rotate by k in place | O(1) space; left vs right |
| Two pointers | Move zeroes / remove duplicates | stability; at most two copies |
| Merging | Merge two sorted arrays | in place into the first array with spare room |
| Binary search | First / last occurrence | count occurrences; rotated sorted array |
| Bounds | Insert position in a sorted array | `lower_bound` semantics |
| Hashing | Two Sum | sorted input, O(1) space; return all pairs |
| Counting | Single number | two unique numbers; each appears three times |
| Kadane | Max subarray sum | return indices; circular array; max product |
| Prefix sums | Subarray sum equals k | negatives; count vs longest |
| Sliding window | Longest / shortest subarray with a condition | what breaks with negatives |
| Binary search on answer | Minimise the maximum … | monotonicity argument |

## Part C - How to behave in the interview

1. **Clarify** constraints and examples (size, negatives, duplicates, sorted, empty).
2. **Brute force first**, stated with its complexity.
3. **Find the bottleneck** (a repeated search, a recomputed sum) and name the pattern that removes it.
4. **Dry-run** on a small example before coding.
5. **Code cleanly** with meaningful names.
6. **Test** edge cases aloud: empty, single, duplicates, negatives, extremes.
7. **State** time and auxiliary space, and trade-offs.
