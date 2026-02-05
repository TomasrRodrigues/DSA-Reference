# Searching Algorithms

#### Table of Contents
1. [Introduction](#introduction)
2. [Sequential Search](#sequential-search)
3. [Binary Search](#binary-search)

---
## Introduction
The search problem is an easy to understand, trivial one. Given an array/collection with n elements and a target element we want to find the position of a target element (or report not found). Other variants include finding first occurence, finding last occurence, finding any occurrence, counting occurrences or finding all occurrences.

Conventionally, return values are either:
- Return index if found
- Return -1 if not found (or `size()`, or iterator to `end()`)


---
## Sequential Search
Sequential search consist in doing something like a linear search, where we check each element one by one until found or reach end. This is a quite trivial way to solve the searching problem. The pseudo-algorithm looks like this:
```
sequentialSearch(array, target):
    for i = 0 to array.size() - 1:
        if array[i] == target:
            return i
    return -1  // Not found
```

Complexity Analysis:
- Time Complexity:
    - Best Case: $O(1)$ - target is first element
    - Worst case: $O(n)$ - target is last or not present
    - Average case: $O(n/2) = O(n)$ - target could be anywhere
- Space Complexity: $O(1)$ - only uses a few variables

We should use sequential search when the array is unsorted and small. We must use this implementation when simplicity is more important than speed. We should not use it when the array is sorted or when we need to search frequently in large array.

[Sequential Search Implementation](/Searching/Implementation/sequential-search.cpp)

---
## Binary Search
The idea behind the Binary Search Algorithm is to use divide and conquer:
1. Compare target with middle element
2. If equal: found
3. If target < middle: search left half
4. If target > middle: search right half
5. Repeat until found or search space is empty

For this to work, the array must be sorted initially.

Pseudo-algorithm looks like this:
```
binarySearch(array, target):
    left = 0
    right = array.size() - 1
    
    while left ≤ right:
        mid = left + (right - left) / 2
        
        if array[mid] == target:
            return mid  // Found
        else if array[mid] < target:
            left = mid + 1  // Search right
        else:
            right = mid - 1  // Search left
    
    return -1  // Not found
```

Complexity Analysis:
- Time Complexity: $O(log (n))$
- Space Complexity:
    - Iterative: $O(1)$
    - Recursive: $O(log (n))$


[Binary Search Implementation](/Searching/Implementation/binary-search.cpp)


---