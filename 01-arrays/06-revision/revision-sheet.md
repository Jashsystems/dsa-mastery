# Arrays Revision Sheet

[← Module index](../README.md) · Lookup tables: [complexity cheat sheet](complexity-cheatsheet.md) · [Common mistakes](common-mistakes.md)

One page to re-read before practice sessions and interviews. Everything here is explained in the linked material.

## 1. Always ask first

1. Size limits → allowed complexity ([guide](../00-foundations/array-complexity.md#7-why-input-constraints-matter)).
2. Empty? Single element? Negatives? Duplicates? Sorted? Overflow?
3. In place / extra space allowed?
4. What is returned: value, index, count, modified array?

## 2. Pattern → trigger → template

| Pattern | Trigger words | Skeleton |
|---|---|---|
| Running summary | "one pass", max/min/count so far | initialise state from data → update per element → read answer |
| Two pointers (ends) | sorted, pair, symmetric | `while (l < r)` move the pointer the comparison rules out |
| Slow/fast | in place, remove, partition | `if (keep) a[slow++] = a[fast]` |
| Sliding window | contiguous, window sum/size, non-negative | `add a[r]; while (invalid) remove a[l++]; update` |
| Prefix sums | many range sums, subarray sums | `prefix[i+1] = prefix[i] + a[i]`; range `[l,r]` = `prefix[r+1] - prefix[l]` |
| Frequency | count, duplicates, anagram | `++count[value]` |
| Kadane | max contiguous sum | `E = max(a[i], E + a[i]); best = max(best, E)` |
| Binary search | sorted / monotone predicate | `while (l < r) { m = l + (r-l)/2; pred(m) ? r = m : l = m + 1; }` |
| Hash map lookup | "find the partner", unsorted pairs | look up `target - x` **before** inserting `x` |
| XOR | "all twice except one" | `result ^= a[i]` |

## 3. Binary search cheat lines

| Want | Predicate / rule | Result |
|---|---|---|
| any index of target | closed range `[l, r]`, `mid == target` | index or −1 |
| first index with `a[i] >= x` (lower bound) | `a[mid] < x → l = mid+1` else `r = mid` | `l` (n if none) |
| first index with `a[i] > x` (upper bound) | `a[mid] <= x → l = mid+1` else `r = mid` | `l` |
| count of x | `upper − lower` | |
| first / last occurrence | continue left / right after a match | |
| smallest feasible answer | feasibility test is monotone | `l` |

## 4. Shifting directions

* Shift **left** (delete, left rotate): loop **forwards**.
* Shift **right** (insert, right rotate): loop **backwards**.
* Rotate right by k: reverse all, reverse `[0,k)`, reverse `[k,n)`; first `k %= n`.

## 5. Types and overflow

* Sums, products, prefix sums: `long long`.
* `a.size()` is unsigned: cast to `int` before arithmetic or comparing with negatives.
* Sentinel values (`INT_MIN`, `-1`) are only safe if they cannot be real answers.

## 6. Before you say "done"

* Dry-run the smallest example, then n = 0 and n = 1.
* Say the complexity (time **and** auxiliary space) and why.
* Name one alternative (brute force) and when it would be fine.
