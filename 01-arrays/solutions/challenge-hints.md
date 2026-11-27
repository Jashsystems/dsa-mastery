# Challenge Hints (reveal one level at a time)

[← Module index](../README.md) · [Solution notes](solution-notes.md)

For the challenge problems [032](../05-interview-problems/032_subarray_sum_equals_k.cpp) and [033](../05-interview-problems/033_longest_subarray_sum_k.cpp). Work on paper first. Only read the next level after you have genuinely tried the previous one for 15–20 minutes. If a mentor is guiding you, let them reveal the levels.

## 032 - Subarray sum equals K

<details><summary>Level 1 - get a baseline</summary>

How many (start, end) pairs are there? Can a running sum give you each subarray's total without re-adding? What complexity is that, and does it pass for n = 2·10⁵?
</details>

<details><summary>Level 2 - why the usual pattern fails</summary>

Try a sliding window on `{1, -1, 0}` with k = 0. What property of the numbers does a window rely on, and which numbers violate it here?
</details>

<details><summary>Level 3 - reframe the sum</summary>

Define `prefix[i]` as the sum of the first `i` elements. Write the sum of the subarray from position `j+1` to position `i` using only prefix values.
</details>

<details><summary>Level 4 - turn it into a lookup</summary>

Fix the right end `i`. Which value must `prefix[j]` have for the subarray to sum to `k`? You now need to know *how many earlier* positions had that prefix value. Which data structure answers that, and what must be in it before the loop starts to count subarrays that begin at index 0?
</details>

<details><summary>Level 5 - order of operations</summary>

At each step: look up first, insert the current prefix second. Why does the order matter when `k = 0`? Then compare with [the reference](solution-notes.md) only after your own version passes the samples.
</details>

## 033 - Longest subarray with sum K

Do 032 first.

<details><summary>Level 1</summary>

Does your 032 idea still apply? What do you need to *remember* about each prefix value now that you want a **length** rather than a **count**?
</details>

<details><summary>Level 2</summary>

For a fixed right end `i`, several earlier positions may share the needed prefix value. Which of them gives the longest subarray: the earliest or the latest?
</details>

<details><summary>Level 3</summary>

So what do you store when a prefix value appears again: overwrite the old position, or keep it? What index represents "the empty prefix before the array starts"?
</details>

<details><summary>Level 4</summary>

If all numbers were non-negative, which simpler technique with O(1) space would work? Why does it stop working when negatives are allowed? (Compare with the [sliding window](../04-array-patterns/sliding-window.md) guide.)
</details>

<details><summary>Level 5</summary>

Check your solution against [the reference notes](solution-notes.md) only after it passes the samples `{1,-1,5,-2,3}, k=3 → 4` and `{-2,-1,2,1}, k=1 → 2`.
</details>
