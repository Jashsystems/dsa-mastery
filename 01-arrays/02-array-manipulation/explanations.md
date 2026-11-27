# Array Manipulation - Explanations

[← Module index](../README.md) · Previous: [basic operations](../01-basic-operations/explanations.md) · Pattern background: [two pointers](../04-array-patterns/two-pointers.md)

| File | Title | Type |
|---|---|---|
| [010](010_left_rotate.cpp) | Left rotate by one | Worked example |
| [011](011_right_rotate.cpp) | Right rotate by one | Exercise |
| [012](012_rotate_by_k.cpp) | Rotate by k (reversal algorithm) | Worked example |
| [013](013_move_zeroes.cpp) | Move zeroes | Worked example |
| [014](014_remove_duplicates.cpp) | Remove duplicates (sorted) | Worked example |
| [015](015_remove_element.cpp) | Remove element | Exercise |
| [016](016_insert_element.cpp) | Insert element | Worked example |
| [017](017_merge_sorted_arrays.cpp) | Merge sorted arrays | Worked example |

---

## 010 - Left rotate by one  *(Worked example)*

1. **Problem.** Shift every element one place left; the first element goes to the end.
2. **Input / output.** `{1,2,3,4,5}` → `{2,3,4,5,1}`.
3. **Intuition.** Every element except the first has a simple destination (`i → i-1`). Only `a[0]` has nowhere to go, so we park it in a variable and place it last.
4. **Brute force.** Build a new vector with the rotated order: O(n) time, O(n) space.
5. **Optimised approach.** In place with one temporary variable: O(n), O(1).
6. **Algorithm.** `first = a[0]`; for `i = 1 … n-1`: `a[i-1] = a[i]`; `a[n-1] = first`.
7. **Dry run.** `{1,2,3,4,5}`, first = 1: i=1 → `{2,2,3,4,5}`; i=2 → `{2,3,3,4,5}`; i=3 → `{2,3,4,4,5}`; i=4 → `{2,3,4,5,5}`; last = 1 → `{2,3,4,5,1}`.
8. **Code.** [010_left_rotate.cpp](010_left_rotate.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty and single-element vectors return unchanged.
12. **Common mistakes.** Forgetting to save `a[0]` before it is overwritten; shifting in the wrong direction.
13. **When to use.** Rotation by exactly one step (repeating it k times costs O(n·k), see 012).
14. **Interview relevance.** Introduces the "shift without losing data" idea used by insert and delete.
15. **Revision question.** Why must the shifting loop run left-to-right for a left rotation?

## 011 - Right rotate by one  *(Exercise)*

* **Problem.** Shift every element one place right; the last element goes to the front. `{1,2,3,4,5}` → `{5,1,2,3,4}`.
* **Constraints.** 0 ≤ n ≤ 10⁵, in place.
* **Edge cases.** Empty, single element, two elements, duplicates.
* **Target.** O(n) time, O(1) space.
* **Revision question.** Which loop direction avoids overwriting unread data, and why is it the opposite of 010?

---

## 012 - Rotate by k (reversal algorithm)  *(Worked example)*

1. **Problem.** Rotate right (or left) by k positions in place.
2. **Input / output.** `{1,2,3,4,5}`, k = 2, right → `{4,5,1,2,3}`; left → `{3,4,5,1,2}`.
3. **Intuition.** A right rotation by k moves the last k elements, as a block, to the front. Reversing the whole array does bring that block to the front but flips it; reversing each of the two blocks afterwards restores their internal order. Reversal is its own inverse, so three reversals compose into a rotation.
4. **Brute force.** Repeat the one-step rotation k times: O(n·k). Or copy into a new vector using `(i + k) % n`: O(n) time but O(n) space.
5. **Optimised approach.** Three in-place reversals: O(n) time, O(1) space.
6. **Algorithm.** `k = k % n`. Right: reverse `[0,n)`, reverse `[0,k)`, reverse `[k,n)`. Left: reverse `[0,k)`, reverse `[k,n)`, reverse `[0,n)`.
7. **Dry run.** `{1,2,3,4,5}`, k = 2, right. Reverse all → `{5,4,3,2,1}`; reverse first 2 → `{4,5,3,2,1}`; reverse last 3 → `{4,5,1,2,3}` ✓.
8. **Code.** [012_rotate_by_k.cpp](012_rotate_by_k.cpp)
9. **Time.** O(n): each element is moved at most twice.
10. **Auxiliary space.** O(1).
11. **Edge cases.** n = 0 (guard before `% n`); k = 0; k = n; k > n (reduce with `%`); n = 1.
12. **Common mistakes.** Forgetting `k % n` (reversing past the end); dividing by zero when n = 0; mixing up the order of the three reversals for left vs right.
13. **When to use.** Any cyclic shift where O(1) extra space is demanded.
14. **Interview relevance.** A classic (the "rotate array" problem); interviewers often ask for the O(1)-space version after you give the copy-based one.
15. **Revision question.** Why is rotating by k = n the same as doing nothing, and how does `k % n` exploit that?

---

## 013 - Move zeroes  *(Worked example)*

1. **Problem.** Move all zeros to the end, preserving the order of non-zero elements.
2. **Input / output.** `{0,1,0,3,12}` → `{1,3,12,0,0}`.
3. **Intuition.** Treat it as *compacting*: build the non-zero elements into the front of the array in order, and the zeros end up behind them.
4. **Brute force.** Copy non-zeros into a new vector, then pad with zeros: O(n) time, O(n) space. (Or repeatedly bubble each zero to the end: O(n²).)
5. **Optimised approach.** Two pointers moving the same direction. `read` scans; `write` is the next slot for a non-zero.
6. **Algorithm.** `write = 0`; for each `read`: if `a[read] != 0`, swap `a[write]` and `a[read]`, then `++write`.
7. **Dry run.** `{0,1,0,3,12}`: read 1 (value 1): swap(a0,a1) → `{1,0,0,3,12}`, write=1. read 3: swap(a1,a3) → `{1,3,0,0,12}`, write=2. read 4: swap(a2,a4) → `{1,3,12,0,0}`, write=3 ✓.
8. **Code.** [013_move_zeroes.cpp](013_move_zeroes.cpp)
9. **Time.** O(n), one pass.
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty; all zeros; no zeros; zeros already at the end.
12. **Common mistakes.** Swapping zeros with zeros and losing stability; advancing `write` on every iteration; assuming `std::sort` could do it (it would reorder non-zeros).
13. **When to use.** "Partition by a condition while keeping order" - see [slow & fast pointers](../04-array-patterns/two-pointers.md#2-same-direction-slow-and-fast-pointers).
14. **Interview relevance.** Very common easy problem testing the same-direction two-pointer idea.
15. **Revision question.** State the loop invariant that makes the final state correct.

---

## 014 - Remove duplicates from a sorted array  *(Worked example)*

1. **Problem.** Keep one copy of each value in the first k positions; return k.
2. **Input / output.** `{1,1,2,2,2,3}` → k = 3, prefix `{1,2,3}`.
3. **Intuition.** In a sorted array equal values are adjacent, so a value is "new" exactly when it differs from the last value kept.
4. **Brute force.** Insert into a `std::set` and copy back: O(n log n), O(n) space; or erase duplicates one by one with `erase` (O(n²)).
5. **Optimised approach.** Slow pointer `write` (end of unique prefix) and fast pointer `read`.
6. **Algorithm.** `write = 1`; for `read = 1 … n-1`: if `a[read] != a[write-1]` then `a[write++] = a[read]`. Return `write`.
7. **Dry run.** `{1,1,2,2,2,3}`: read 1 (1 = a0) skip; read 2 (2 ≠ 1) → a1 = 2, write 2; read 3, 4 (2 = a1) skip; read 5 (3 ≠ 2) → a2 = 3, write 3. Array `{1,2,3,2,2,3}`, return 3.
8. **Code.** [014_remove_duplicates.cpp](014_remove_duplicates.cpp)
9. **Time.** O(n).
10. **Auxiliary space.** O(1).
11. **Edge cases.** Empty (return 0); all identical (return 1); no duplicates.
12. **Common mistakes.** Comparing `a[read]` with `a[read-1]` after already overwriting; starting `write` at 0; applying the algorithm to an *unsorted* array.
13. **When to use.** Sorted input + "unique" or "at most once". For unsorted input sort first, or use a set.
14. **Interview relevance.** Standard; variants allow at most 2 copies (compare with `a[write-2]`).
15. **Revision question.** What changes if each value may appear at most twice?

## 015 - Remove element  *(Exercise)*

* **Problem.** Remove all occurrences of `value` in place, keeping the order of the others; return the new length k (first k slots hold the kept elements). `{3,2,2,3}`, value 3 → k = 2, `{2,2}`.
* **Constraints.** 0 ≤ n ≤ 10⁵, array not necessarily sorted.
* **Edge cases.** Empty; value absent; everything removed; negative value; single element.
* **Target.** O(n) time, O(1) space. Compare with 013 and 014.
* **Revision question.** How does the loop invariant differ from 014's?

---

## 016 - Insert an element at an index  *(Worked example)*

1. **Problem.** Insert `value` so it sits at `position`; later elements move right.
2. **Input / output.** `{1,2,4,5}`, position 2, value 3 → `{1,2,3,4,5}`.
3. **Intuition.** Arrays have no gaps: to open a slot at `position` every element from there on must move one step right.
4. **Brute force.** Build a new vector copying prefix, value, suffix: O(n) time and space.
5. **Optimised approach.** Grow by one with `push_back`, then shift in place from the back.
6. **Algorithm.** Reject `position < 0` or `> n`. `push_back(value)`. For `i = n … position+1`: `a[i] = a[i-1]`. `a[position] = value`.
7. **Dry run.** `{1,2,4,5}`, pos 2, val 3, n = 4. After push_back `{1,2,4,5,3}`; i=4: a4 = a3 → `{1,2,4,5,5}`; i=3: a3 = a2 → `{1,2,4,4,5}`; loop ends (i = 2 is not > 2); a2 = 3 → `{1,2,3,4,5}`.
8. **Code.** [016_insert_element.cpp](016_insert_element.cpp)
9. **Time.** O(n − position); O(n) worst case.
10. **Auxiliary space.** O(1) amortised.
11. **Edge cases.** `position = 0` (full shift); `position = n` (plain append, no shift); empty vector; invalid positions.
12. **Common mistakes.** Shifting left-to-right (smears one value across the array); allowing `position > n`.
13. **When to use.** Rarely in hot loops: each middle insert is O(n). Prefer building the array in order or using another structure when inserts are frequent.
14. **Interview relevance.** Tests whether you understand the real cost of array insertion.
15. **Revision question.** What is the total cost of inserting n elements one by one at the front of an empty vector?

---

## 017 - Merge two sorted arrays  *(Worked example)*

1. **Problem.** Combine two sorted vectors into one sorted vector.
2. **Input / output.** `{1,3,5}` + `{2,3,6}` → `{1,2,3,3,5,6}`.
3. **Intuition.** The smallest remaining element overall is always the smaller of the two *fronts*. Taking it never prevents a better choice later.
4. **Brute force.** Concatenate and `sort`: O((n+m) log(n+m)); it ignores that the inputs are already sorted.
5. **Optimised approach.** Two pointers, one per input: O(n + m).
6. **Algorithm.** While both have elements: push the smaller front (`<=` favours the first array, keeping the merge stable) and advance it. Then copy the leftover tail of whichever array remains.
7. **Dry run.** `a={1,3,5}`, `b={2,3,6}`: 1 vs 2 → 1; 3 vs 2 → 2; 3 vs 3 → a's 3; 5 vs 3 → b's 3; 5 vs 6 → 5; `a` exhausted, copy 6 → `{1,2,3,3,5,6}` ✓.
8. **Code.** [017_merge_sorted_arrays.cpp](017_merge_sorted_arrays.cpp)
9. **Time.** O(n + m).
10. **Auxiliary space.** O(n + m) for the output; O(1) beyond it.
11. **Edge cases.** One or both empty; all elements equal; one array entirely smaller than the other.
12. **Common mistakes.** Forgetting the leftover loops; using `<` and breaking stability; reading `a[i]` when `i == a.size()`.
13. **When to use.** Merge sort's combine step; combining sorted logs; [union](../05-interview-problems/027_union_of_arrays.cpp) and [intersection](../05-interview-problems/028_intersection_of_arrays.cpp) are variations.
14. **Interview relevance.** Appears directly and as a sub-step of many problems.
15. **Revision question.** Why is the two-pointer merge correct even though we never compare an element with the ones after the fronts?
