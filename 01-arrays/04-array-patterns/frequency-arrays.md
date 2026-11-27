# Frequency Arrays (Counting)

[← Prefix sums](prefix-sum.md) · [Pattern guide](explanations.md) · Code: [009_frequency_count.cpp](../01-basic-operations/009_frequency_count.cpp)

**Idea:** instead of comparing elements with each other (O(n²)), use each value as an **address** into a table of counters (O(1) per update).

## 1. Choosing the table

| Situation | Table | Update cost | Memory |
|---|---|---|---|
| values are small non-negative ints (`0..M`, M ≲ 10⁶) or letters | counting array `vector<int> count(M+1)` | O(1) | O(M) |
| values arbitrary, need sorted keys | `std::map<int,int>` | O(log d) | O(d) |
| values arbitrary, need fast lookup only | `std::unordered_map<int,int>` | O(1) average | O(d) |
| only presence matters | `vector<bool>` / set | as above | |

(d = number of distinct values.)

## 2. Letters and small alphabets

```cpp
int count[26] = {0};                    // 'a'..'z'
for (char c : word) ++count[c - 'a'];  // 'c' - 'a' == 2
```

## 3. Example: are two arrays permutations of each other?

```cpp
bool isPermutation(const std::vector<int>& a, const std::vector<int>& b, int maxValue) {
    if (a.size() != b.size()) return false;
    std::vector<int> count(maxValue + 1, 0);
    for (int v : a) ++count[v];
    for (int v : b) if (--count[v] < 0) return false;   // b has more copies of v than a
    return true;
}
```
**Dry run.** `a = {1,2,2}`, `b = {2,1,2}`, maxValue 2. After `a`: `[0,1,2]`. `b`: 2 → `[0,1,1]`; 1 → `[0,0,1]`; 2 → `[0,0,0]`; never negative → true. Time O(n + M), space O(M); the alternative (sort both) is O(n log n).

## 4. Typical uses

| Problem family | Use of counts |
|---|---|
| duplicates / "appears twice" | count > 1 |
| most / least frequent value | scan the counts |
| anagrams, permutations | compare count tables |
| "first non-repeating element" | count, then scan in original order |
| sliding window with "at most k distinct" | counts inside the window ([sliding window](sliding-window.md)) |
| values in the range `1..n` | the array itself can serve as the table (in-place marking, advanced) |

## 5. Complexity

Building the table is O(n). Scanning a counting array is O(M), so if M ≫ n (say n = 10, values up to 10⁹) use a map instead: a counting array of size 10⁹ would not even fit in memory.

## 6. Recognising the pattern

* "How many times", "duplicate", "unique", "anagram", "permutation", "majority".
* Constraints that bound the value range (digits, letters, `1 ≤ a[i] ≤ n`).
* A brute-force solution with a nested loop that *compares equal values*.

## 7. Common mistakes

* Counting-array size `M` instead of `M + 1`.
* Negative values used as indices (offset them, or use a map).
* Value range too large for the memory limit.
* Using `map::operator[]` just to *check* presence (it inserts the key); use `find` or `count`.
* Treating `char` arithmetic as unsigned/negative without care.

## 8. Revision questions

1. Why is a counting array O(1) per update but a `std::map` O(log d)?
2. When is a counting array a bad idea even though values are non-negative?
3. How would you find the first non-repeating element using counts?

<details><summary>Answers</summary>

1. Array indexing is direct address arithmetic; a map is a balanced tree searched by key.
2. When the maximum value is huge compared with n (memory and scan cost).
3. Count all values, then scan the original array and return the first element whose count is 1.

</details>
