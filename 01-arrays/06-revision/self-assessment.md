# Self-Assessment (Arrays)

[← Module index](../README.md) · Timed practice: [timed assessments](../07-practice/timed-assessments.md)

Do this honestly **without** looking at the notes. A Green result in every section means you are ready to move on to the next module.

## Part A - Concepts (answers below)

1. What is the address of `a[7]` if `a` starts at 5000 and elements are 4 bytes?
2. State the complexity of `push_back`, insert at front, `std::find`, `std::sort`, `std::lower_bound`.
3. Which has more auxiliary space: reversing in place, or merging two sorted arrays into a new one?
4. For n = 2 × 10⁵ which complexities are acceptable?
5. Name two conditions that make a variable-size sliding window valid for a sum problem.
6. What is `prefix[4] - prefix[1]` for `prefix = {0, 3, 4, 8, 9, 14}`?
7. Why does `std::accumulate(a.begin(), a.end(), 0)` risk overflow?
8. What does `lower_bound` return when every element is smaller than the target?

<details><summary>Answers</summary>

1. 5000 + 7 × 4 = 5028.
2. O(1) amortised; O(n); O(n); O(n log n); O(log n) (sorted input).
3. Merging (O(n + m) output); in-place reversal uses O(1).
4. O(n) and O(n log n); O(n²) (about 4 × 10¹⁰ steps) is too slow.
5. Contiguous subarray, and monotone behaviour (e.g. non-negative elements, or an incrementally maintainable rule).
6. 9 − 3 = 6, the sum of `a[1..3]`.
7. The initial value `0` is an `int`, so the whole accumulation is `int`; use `0LL`.
8. The index n (one past the last element).

</details>

## Part B - Predict the output (answers below)

**B1**
```cpp
std::vector<int> a = {5, 1, 4};
a.push_back(2);
a.insert(a.begin() + 1, 9);
a.pop_back();
// print a
```

**B2** For `s = {1, 3, 3, 5, 8}`, what are the *indices* returned by `lower_bound(s, 4)`, `upper_bound(s, 3)` and `lower_bound(s, 3)`?

**B3**
```cpp
std::vector<int> b = {0, 2, 0, 3};
int w = 0;
for (int r = 0; r < 4; ++r)
    if (b[r] != 0) b[w++] = b[r];
// final b and w?
```

**B4** Right-rotate `{1, 2, 3}` by `k = 7` using the reversal algorithm. Result?

**B5** What is `4 ^ 1`, and what is `5 ^ 5 ^ 9`?

**B6** Is `std::vector<int>().size() - 1 > 0` true or false, and why?

<details><summary>Answers</summary>

* **B1** `5 9 1 4` (after push_back `{5,1,4,2}`, insert `{5,9,1,4,2}`, pop_back `{5,9,1,4}`).
* **B2** `3`, `3`, `1`.
* **B3** `b = {2, 3, 0, 3}`, `w = 2` (the entries after `w` are stale; this is why such algorithms return `w`).
* **B4** `7 % 3 = 1` → `{3, 1, 2}`.
* **B5** `5`; `9`.
* **B6** True: `size()` is 0 (unsigned), and `0 − 1` wraps to the largest unsigned value.

</details>

## Part C - Write from a blank file (no notes, time yourself)

| Task | Target time | Pass criteria |
|---|---|---|
| Reverse a vector in place | 5 min | correct on empty / single / even / odd |
| Move zeroes (stable, in place) | 8 min | states the loop invariant |
| Merge two sorted vectors | 10 min | leftover loops handled |
| First occurrence by binary search | 10 min | no infinite loop, returns −1 correctly |
| Rotate by k with reversals | 10 min | handles k > n and n = 0 |
| Kadane | 8 min | handles all-negative arrays |
| Two Sum with a hash map | 10 min | never pairs an element with itself |

Mark each one: ✅ passed all edge cases · 🟡 needed a hint · 🔴 could not complete.

## Part D - Explain it (spoken or written, 2 minutes each)

* Why is binary search O(log n)?
* Why does the hash-map Two Sum look up before inserting?
* Why does Kadane's algorithm work?
* When would you use a counting array vs a `std::map`?

## Scoring

| Section | Green | Amber | Red |
|---|---|---|---|
| A concepts | 8/8 | 6–7 | ≤ 5 |
| B predictions | 6/6 | 4–5 | ≤ 3 |
| C coding | all ✅ | any 🟡, no 🔴 | any 🔴 |
| D explanations | all clear | 1–2 shaky | cannot explain |

Re-read the matching guide for every Amber/Red item, then retake that part after 48 hours.
