# Array Fundamentals

[← Module index](../README.md) · Next: [Memory layout](array-memory-layout.md)

## 1. What an array is

An **array** is a numbered sequence of elements of the same type stored one after another. Each element is reached by its **index**, and indexing starts at 0.

```
index:   0    1    2    3    4
       +----+----+----+----+----+
value: | 12 | -4 |  7 |  7 | 30 |      n = 5, valid indices 0 .. n-1
       +----+----+----+----+----+
```

Two properties drive almost everything in this module:

1. **Random access in O(1):** `a[i]` costs the same for i = 0 and i = 99 999.
2. **Fixed neighbours:** inserting or deleting in the middle forces the elements after it to move.

In C++ you will almost always use `std::vector<int>` (a resizable array). See [C++ arrays vs vectors](cpp-arrays-vs-vectors.md) and the [vector guide](vector-stl-guide.md).

## 2. Operation costs

| Operation | Cost on an array / vector | Why |
|---|---|---|
| Read or write `a[i]` | O(1) | address arithmetic, see [memory layout](array-memory-layout.md) |
| Append (`push_back`) | O(1) amortised | occasional reallocation is spread over many appends |
| Remove last (`pop_back`) | O(1) | nothing has to move |
| Insert / erase at index i | O(n − i) | later elements shift ([016](../02-array-manipulation/016_insert_element.cpp)) |
| Search, unsorted | O(n) | must look at elements ([018](../03-searching/018_linear_search.cpp)) |
| Search, sorted | O(log n) | binary search ([019](../03-searching/019_binary_search_intro.cpp)) |
| Traverse everything | O(n) | one visit per element |

## 3. Indexing rules to internalise

* Valid indices are `0 … n−1`. The last element is `a[n-1]`, never `a[n]`.
* `a[i]` with a bad `i` is **undefined behaviour** in C++ (no automatic error). It may crash, or silently read garbage.
* `a.size()` is **unsigned**. `a.size() - 1` on an empty vector wraps to a gigantic number. Convert first: `int n = static_cast<int>(a.size());`.
* An empty array is legal input unless the constraints say otherwise. Always ask: *what happens when n = 0 and n = 1?*

## 4. Off-by-one errors

The most common array bug. Habits that prevent it:

| Situation | Safe pattern |
|---|---|
| Visit every element | `for (int i = 0; i < n; ++i)` |
| Compare neighbours | start at `i = 1` and use `a[i-1]`, `a[i]` (never reach `a[n]`) |
| Visit from the back | `for (int i = n - 1; i >= 0; --i)` (use a signed `int`!) |
| Range of indices | prefer **half-open** `[left, right)`: length is `right - left`, no +1 |

## 5. How to read a problem about arrays

Before coding, extract:

1. **Size limits** (n up to 10³? 10⁵? 10⁶?). They decide which complexity is acceptable ([complexity guide](array-complexity.md)).
2. **Value limits** (negative? zero? beyond `int` when summed?).
3. **Order guarantees** (sorted? distinct? only 0/1?). Every guarantee is a free hint.
4. **Allowed extra memory** ("in place" = O(1) extra).
5. **Output form** (value, index, count, modified array, new array).

## 6. Common mistakes

* Assuming the array is non-empty without checking the constraints.
* Using `int` for sums, products, or prefix sums that may overflow.
* Modifying an array while another part of the algorithm still needs the old value.
* Confusing "index of the element" with "the element".

## 7. Revision questions

1. What is the index of the last element of an array of size n?
2. Why is inserting at the front of a vector O(n) but `push_back` amortised O(1)?
3. What goes wrong with `for (size_t i = a.size() - 1; i >= 0; --i)`?

<details><summary>Answers</summary>

1. `n − 1`.
2. Inserting at the front moves all n elements one step right; appending usually just writes into spare capacity.
3. `size_t` is unsigned, so `i >= 0` is always true. When `i` reaches 0 and is decremented it wraps to a huge number: an infinite loop / out-of-bounds access.

</details>
