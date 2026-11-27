# Two Pointers (including Slow and Fast Pointers)

[← Module index](../README.md) · [Pattern guide](explanations.md) · Next: [Sliding window](sliding-window.md)

**Idea:** use two indices instead of one nested loop. Each pointer only moves in one direction, so the total movement is O(n) rather than O(n²).

## 1. Opposite ends (converging pointers)

`left` starts at the first element, `right` at the last; they move toward each other.

```
[ 1  2  4  7  11  15 ]
  L                R      L and R close in; the middle is where they meet
```

**Works when** a comparison at (`left`, `right`) tells you which pointer can safely move: usually because the data is **sorted** or symmetric.

### Example A: reverse / palindrome
Swap or compare `a[left]` with `a[right]`, then move both inward ([006 reverse](../01-basic-operations/006_reverse_array.cpp)).

### Example B: pair with a given sum in a SORTED array
```cpp
int left = 0, right = n - 1;
while (left < right) {
    long long sum = static_cast<long long>(a[left]) + a[right];
    if (sum == target)      return {left, right};
    else if (sum < target)  ++left;     // need a bigger sum: only moving left rightwards can raise it
    else                    --right;    // need a smaller sum
}
```
**Why it is correct:** if `a[left] + a[right] < target`, then `a[left]` paired with *any* element at or before `right` is also too small (those are no larger than `a[right]`), so `left` cannot belong to any answer: discard it. The symmetric argument discards `right` when the sum is too large. Every step permanently eliminates one index.

**Dry run.** `a = {1,2,4,7,11,15}`, target 15:

| left | right | sum | action |
|---|---|---|---|
| 0 | 5 | 16 | too big → `right--` |
| 0 | 4 | 12 | too small → `left++` |
| 1 | 4 | 13 | too small → `left++` |
| 2 | 4 | 15 | match: indices 2 and 4 |

Time O(n), space O(1). On **unsorted** data this argument fails; use a hash map ([029 Two Sum](../05-interview-problems/029_two_sum.cpp)) or sort first.

## 2. Same-direction (slow and fast pointers)

Both pointers move left → right; `fast` scans, `slow` marks the boundary of the "answer built so far".

```
a: [ 0  1  0  3  12 ]
        S        F        S = write position, F = read position
```

Invariant to state out loud: *"`a[0..slow-1]` is the finished output for everything `fast` has already passed."*

Used in: [013 Move zeroes](../02-array-manipulation/013_move_zeroes.cpp), [014 Remove duplicates](../02-array-manipulation/014_remove_duplicates.cpp), [015 Remove element](../02-array-manipulation/015_remove_element.cpp).

**Template**
```cpp
int slow = 0;
for (int fast = 0; fast < n; ++fast) {
    if (/* a[fast] should be kept */) {
        a[slow] = a[fast];     // or swap, if the discarded items must be kept at the back
        ++slow;
    }
}
// slow = size of the kept prefix
```

**Different speeds ("tortoise and hare").** On linked lists and "index-jumping" arrays, `fast` moves two steps per `slow` step; the pointers meet if and only if there is a cycle. The same template with a different stepping rule finds a cycle's start or a middle element.

## 3. Two pointers on two arrays

One pointer per sorted array, always advancing the one at the smaller value: [017 Merge](../02-array-manipulation/017_merge_sorted_arrays.cpp), [027 Union](../05-interview-problems/027_union_of_arrays.cpp), [028 Intersection](../05-interview-problems/028_intersection_of_arrays.cpp).

## 4. Why the total cost is O(n) even with a `while` inside a `for`

Each pointer only moves forward, and each index is passed at most once by each pointer. Total pointer movement ≤ 2n, regardless of how the loops are nested. Ask: *"does any pointer ever move backwards?"* If not, it is linear.

## 5. Recognising the pattern

| Signal in the statement | Likely variant |
|---|---|
| "sorted array", "find a pair / triple" | opposite ends |
| "reverse", "palindrome", "symmetric" | opposite ends |
| "in place", "remove", "partition", "compact", "O(1) extra space" | slow & fast, same direction |
| "two sorted arrays" | one pointer per array |
| "detect cycle", "find the middle" | fast moves 2× |

## 6. Common mistakes

* Using opposite-end pointers on an **unsorted** array.
* `left <= right` vs `left < right`: decide whether a pointer may meet itself (pair problems: no).
* Moving the wrong pointer when the condition is symmetric.
* Forgetting to return or handle the final size (`slow`).
* Overwriting `a[slow]` before reading it (safe in the template only because `slow <= fast`).

## 7. When *not* to use it

When the answer needs information that sorting or monotonicity cannot rule out, e.g. subarray sums with **negative numbers**: use [prefix sums](prefix-sum.md) instead.

## 8. Revision questions

1. In the pair-sum example, why is it safe to discard `a[left]` when the sum is too small?
2. What invariant does `slow` maintain in Move zeroes?
3. Why is a nested `while` inside a `for` still O(n) when pointers only move forward?

<details><summary>Answers</summary>

1. Pairing it with any element at or before `right` gives an even smaller sum, so it cannot reach the target.
2. `a[0..slow-1]` holds exactly the non-zero elements seen so far, in their original order.
3. Total pointer movement is bounded by 2n: every index is passed at most once per pointer.

</details>
