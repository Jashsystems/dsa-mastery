# Array Memory Layout

[← Fundamentals](array-fundamentals.md) · Next: [Traversal](array-traversal.md)

## 1. Contiguous storage

Elements of an array sit in **adjacent memory cells**. If an `int` occupies 4 bytes and the array starts at address `1000`:

```
address:  1000   1004   1008   1012   1016
         +------+------+------+------+------+
         | a[0] | a[1] | a[2] | a[3] | a[4] |
         +------+------+------+------+------+
```

The address of `a[i]` is computed, not searched for:

```
address(a[i]) = base_address + i * sizeof(element)
```

That single multiplication and addition is why **`a[i]` is O(1)**, whatever `i` is.

## 2. Consequences

| Consequence | Explanation |
|---|---|
| Fast random access | direct address arithmetic |
| Fast sequential scans | the CPU loads a whole *cache line* (typically 64 bytes = 16 ints) at once, so the next elements are already in cache. This is called **cache locality** and is a real reason arrays beat linked lists in practice |
| Costly middle insert/erase | there is no gap; neighbours must be shifted ([016](../02-array-manipulation/016_insert_element.cpp)) |
| Fixed capacity (C arrays) | growing needs a new, larger block and a copy |

```
Insert 3 at index 2 of {1, 2, 4, 5}:

before: | 1 | 2 | 4 | 5 |   |        (one slot added by push_back)
shift:  | 1 | 2 | 4 | 4 | 5 |        elements move right, from the back
write:  | 1 | 2 | 3 | 4 | 5 |
```

## 3. What a `std::vector` actually holds

A vector object is small and fixed in size; it *points to* a separately allocated block:

```
vector object            heap block (capacity = 8)
+-----------+           +---+---+---+---+---+---+---+---+
| pointer ──┼─────────► | 7 | 3 | 9 | ? | ? | ? | ? | ? |
| size = 3  |           +---+---+---+---+---+---+---+---+
| capacity=8|             used ▲          unused spare room
+-----------+
```

* `size()` = elements in use, `capacity()` = room before reallocation.
* `push_back` when `size == capacity`: allocate a bigger block (commonly ×2), copy everything, free the old one. That copy is O(n) but happens rarely, so the **amortised** cost per append is O(1).
* Any pointer, reference or iterator into the old block becomes **invalid** after a reallocation.
* `reserve(k)` pre-allocates capacity without changing `size()` ([017](../02-array-manipulation/017_merge_sorted_arrays.cpp) uses it).

## 4. Two-dimensional arrays

A `vector<vector<int>>` is a vector of row-vectors: rows are separate blocks. A plain C array `int m[3][4]` is **row-major**: row 0, then row 1, then row 2 in one block. Scanning row by row is cache-friendly; scanning column by column jumps through memory.

## 5. Common mistakes

* Thinking `a[i]` "searches" for position i.
* Keeping a reference like `int& first = v[0];` across a `push_back` (it can dangle after reallocation).
* Assuming `v.size()` equals `v.capacity()`.

## 6. Revision questions

1. Array starts at address 2000, elements are 8-byte `long long`. What is the address of `a[5]`?
2. Why is traversing an array usually faster than traversing a linked list of the same length?

<details><summary>Answers</summary>

1. `2000 + 5 × 8 = 2040`.
2. Contiguous elements share cache lines, so the CPU rarely waits for memory; list nodes are scattered.

</details>
