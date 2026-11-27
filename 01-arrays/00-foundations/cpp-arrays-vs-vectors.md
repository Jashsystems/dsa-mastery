# C++ Arrays vs `std::vector`

[← Complexity](array-complexity.md) · Next: [Vector STL guide](vector-stl-guide.md)

## 1. The three kinds of "array" in C++

```cpp
int raw[5] = {1, 2, 3, 4, 5};              // C-style array: size fixed at compile time
std::array<int, 5> fixed = {1, 2, 3, 4, 5}; // std::array (needs <array>): fixed size, safer wrapper
std::vector<int> dyn = {1, 2, 3, 4, 5};     // std::vector (needs <vector>): resizable
```

| Feature | C array `int a[N]` | `std::array<int,N>` | `std::vector<int>` |
|---|---|---|---|
| Size known at | compile time | compile time | run time, can change |
| Knows its own size | **no** | yes (`size()`) | yes (`size()`) |
| Grow / shrink | no | no | `push_back`, `pop_back`, `resize`, `insert`, `erase` |
| Where stored | stack (or static) | stack | elements on the heap |
| Copy with `=` | **not allowed** | copies elements | copies elements |
| Pass to a function | decays to a pointer (size lost) | by reference / copy | by reference / copy |
| `a.begin()` / `a.end()` | only via `std::begin(a)` | yes | yes |
| Comparison `==` | compares addresses (!) | compares elements | compares elements |
| Typical use | legacy code, tiny fixed tables | fixed small sizes | **default for algorithm problems** |

## 2. Why this module uses `std::vector`

* The input size n is usually only known at run time.
* It carries its size, so helper functions need no extra `n` parameter.
* It supports whole-container copy, comparison and standard algorithms.
* Same O(1) indexing and the same contiguous memory as a C array ([layout](array-memory-layout.md)).

## 3. Pitfalls of raw C arrays

**Size is lost when passed to a function:**

```cpp
void print(int a[]) {                 // really: int* a
    // sizeof(a) is the size of a POINTER (8 bytes), not of the array
}
int main() {
    int data[5] = {1, 2, 3, 4, 5};
    int count = sizeof(data) / sizeof(data[0]);   // 5, works only where `data` is the real array
    print(data);                                   // the callee cannot recover the 5
}
```

**No bounds checking**, and **large local arrays** (say `int a[10000000]` inside `main`) can overflow the stack. Large arrays belong in a vector or at global scope.

## 4. Passing vectors to functions

| Parameter type | Meaning | When |
|---|---|---|
| `std::vector<int> a` | a full **copy** | almost never for large data (O(n) copy) |
| `std::vector<int>& a` | the caller's vector; function may modify it | in-place algorithms ([006](../01-basic-operations/006_reverse_array.cpp)) |
| `const std::vector<int>& a` | the caller's vector, read-only, no copy | read-only algorithms (default choice) |

## 5. Initialisation cheat sheet

```cpp
std::vector<int> a;                  // empty
std::vector<int> b(5);               // five zeros
std::vector<int> c(5, -1);           // five copies of -1
std::vector<int> d = {4, 7, 9};      // listed values
std::vector<int> e(d);               // copy of d
std::vector<std::vector<int>> grid(3, std::vector<int>(4, 0));  // 3 x 4 zeros
```

## 6. Common mistakes

* `std::vector<int> a(n); a.push_back(x);` appends *after* n zeros (size n + 1).
* Declaring `int a[n]` with a non-constant `n` (a compiler extension in some compilers, not standard C++).
* Passing a vector by value into a recursive function.
* Comparing two C arrays with `==` and expecting element comparison.

## 7. Revision questions

1. Why can't a function that receives `int a[]` compute the array's length?
2. Which parameter type should a read-only algorithm use?
3. What is the size of `std::vector<int> v(3, 7);` and what does it hold?

<details><summary>Answers</summary>

1. The parameter is just a pointer to the first element; the length information is not part of it.
2. `const std::vector<int>&`.
3. Size 3, holding `{7, 7, 7}`.

</details>
