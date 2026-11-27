# Common Mistakes (Arrays)

[← Module index](../README.md) · See also: [revision sheet](revision-sheet.md)

Use this as a pre-submission checklist. Each row: the mistake, why it fails, the fix.

## 1. Indexing and loops

| Mistake | Why it fails | Fix |
|---|---|---|
| `for (i = 0; i <= n; ++i)` | reads `a[n]` (out of range) | `i < n` |
| `a.size() - 1` on an empty vector | unsigned wrap-around → huge value | `static_cast<int>(a.size()) - 1` |
| `for (size_t i = n-1; i >= 0; --i)` | `i >= 0` is always true for unsigned | use `int i` |
| Comparing `a[i]` and `a[i+1]` up to `i < n` | reads `a[n]` | loop to `i < n - 1` or start at 1 and use `a[i-1]` |
| Assuming n ≥ 1 | crash on empty input | test n = 0 and n = 1 |
| Range `[l, r]` length computed as `r - l` | off by one | `r - l + 1` (closed) or `r - l` (half-open) |

## 2. Types

| Mistake | Fix |
|---|---|
| `int sum` over large values | `long long` |
| `std::accumulate(..., 0)` | `0LL` |
| `a[0] + a[1]` computed in `int` then stored in `long long` | cast one operand first: `static_cast<long long>(a[0]) + a[1]` |
| `INT_MIN` as "no answer" when it is a valid answer | separate `bool` flag |
| `(left + right) / 2` | `left + (right - left) / 2` |
| `int` for `n(n+1)/2` | `long long` |

## 3. In-place algorithms

| Mistake | Fix |
|---|---|
| Shifting right with a forward loop (smears one value) | loop backwards |
| Overwriting a value before saving it | store in a temporary first |
| Rotating by `k` without `k % n` | reduce `k`; guard `n == 0` |
| Using the two-pointer in-place method on unsorted data for "remove duplicates" | sort first or use a set |
| Forgetting the returned length when the tail is garbage | return `write` |
| Modifying a vector (`push_back`, `erase`) inside a range-for over it | use indices or collect changes |

## 4. Searching

| Mistake | Fix |
|---|---|
| Binary search on unsorted data | check the precondition |
| `while (l < r)` with `r = n-1` and `r = mid - 1` mixed | pick one template and keep its bounds consistent |
| Infinite loop from `l = mid` / `r = mid` in a closed-range loop | use `mid ± 1` in `[l, r]`, or the half-open template |
| Returning at the first match when asked for first/last | keep searching one side |
| `lower_bound` result used as an index without checking `== n` | check bounds |

## 5. Patterns

| Mistake | Fix |
|---|---|
| Sliding window with negative numbers | prefix sums + lookup structure |
| Opposite-end pointers on unsorted data | sort or hash map |
| Kadane initialised to 0 | initialise from `a[0]` |
| Hash-map Two Sum: insert before lookup | look up first |
| Counting array too small (`M` instead of `M+1`) or with negative indices | size `M+1`, offset or map |
| Prefix array of size n instead of n + 1 | include the empty prefix |

## 6. Process mistakes

* Coding before dry-running a small example.
* Memorising a solution without knowing its precondition.
* Not stating complexity (time **and** auxiliary space).
* Not testing: empty, single, duplicates, negatives, sorted, reverse sorted, all equal, boundaries.
* Copying a library call (`sort`, `max_element`) where the exercise asks you to implement the idea.
