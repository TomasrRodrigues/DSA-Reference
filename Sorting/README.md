# Sorting Algorithms

#### Table of Contents

1. [Introduction](#introduction)
2. [Selection Sort](#selection-sort)
3. [Bubble Sort](#bubble-sort)
4. [Insertion Sort](#insertion-sort)
5. [Merge Sort](#merge-sort)
6. [Quick Sort](#quick-sort)


## Introduction

The sorting problem consists in receiving a certain array of n elements as an input and to output a permutation of that same array where elements are in non-decreasing order.
For example:
```
Input:  [5, 2, 8, 1, 9, 3, 7]
Output: [1, 2, 3, 5, 7, 8, 9]
```

Sorting is one of the most fundamental operations in computer science because:
1. **Enables efficient searching**: Binary search requires sorted data ($O(log(n))$ vs $O(n)$)
2. **Data Presentation**: Humans prefer sorted information
3. **Algorithm Preprocessing**: Many algorithms work better on sorted data
4. **Database Operations**: ORDER BY clauses, index maintenance
5. **Finding duplicates**: Easy to spot in sorted data
6. **Finding median/percentiles**: Requires sorting
7. **Closest pair problems**: Often solved by sorting first

#### Sorting Terminology

**In-Place Sorting**: Sorting algorithms uses $O(1)$ extra space (only a constant amount of additional memory). Examples include Insertion Sort, Quick sort, Heap Sort.

**Stable Sorting**: A sorting algorithm is stable if it preserves the relative order of equal elements. Stability matters when sorting by multiple criteria. Stable Algorithms include Insertion Sort, Merge Sort and Bubble Sort.

**Comparison-Based Sorting**: Uses comparisons ($<$, $>$, $\leq$, $\geq$, $=$) to determine order. Any comparison-based sorting algorithm requires $Ω(n log(n))$ comparisons in worst case.

**Adaptive Sorting**: An algorithm is adaptive if it takes advantage of existing order in the input.


---
## Selection Sort
The idea behind selection sort is to repeatedly find the minimum element from unsorted part and move it to the beginning. The pseudo algorithm looks like this:

```
selectionSort(array):
    for i = 0 to n-2:
        minIndex = i
        
        // Find minimum in unsorted part [i+1, n-1]
        for j = i+1 to n-1:
            if array[j] < array[minIndex]:
                minIndex = j
        
        // Swap minimum with first unsorted element
        swap(array[i], array[minIndex])
```

Complexity Analysis:
- Time Complexity: Always $O(n^2)$
- Space Complexity: $O(1)$

This algorithm is In-Place, Simple but Unstable and Not Adaptive.

---
## Bubble Sort
The idea behind bubble sort is to repeatedly swap adjacent elements if they're in the wrong order. Larger elements "bubble up" to the end. The pseudo-algorithm looks like this:
```
bubbleSort(array):
    for i = 0 to n-2:
        for j = 0 to n-2-i:
            if array[j] > array[j+1]:
                swap(array[j], array[j+1])
```

Complexity Analysis:
- Time Complexity: $O(n^2)$ (while best case is $O(n)$)
- Space Complexity: $O(1)$

Bubble sort is In-Place, Stable, Adaptive and Simple.


---
## Insertion Sort
The idea of insertion sort is to build a sorted array one element at a time by inserting each element into its correct position. It works like sorting a hand of playing cards.

The pseudo-algorithm looks like this:
```
insertionSort(array):
    for i = 1 to n-1:
        key = array[i]
        j = i - 1
        
        // Shift elements > key to the right
        while j >= 0 and array[j] > key:
            array[j+1] = array[j]
            j = j - 1
        
        // Insert key at correct position
        array[j+1] = key
```

Complexity Analysis:
- Time Complexity: $O(n^2)$ (best case of $O(n)$)
- Space Complexity: $O(1)$

Insertion Sort is In-Place, Stable, Adaptive and Online.

---

## Merge Sort
Merge Sort takes advantage of the divide-and-conquer approach to solve this problem in a more efficient way. The idea is to divide array into halves and recursively sort each half and finally merge sorted halves.
The pseudo-algorithm looks like this:
```
mergeSort(array, left, right):
    if left < right:
        mid = (left + right) / 2
        
        // Divide
        mergeSort(array, left, mid)      // Sort left half
        mergeSort(array, mid+1, right)   // Sort right half
        
        // Conquer
        merge(array, left, mid, right)   // Merge sorted halves

merge(array, left, mid, right):
    // Create temporary arrays
    L = array[left...mid]
    R = array[mid+1...right]
    
    i = 0, j = 0, k = left
    
    // Merge L and R back into array
    while i < L.size() and j < R.size():
        if L[i] <= R[j]:
            array[k] = L[i]
            i++
        else:
            array[k] = R[j]
            j++
        k++
    
    // Copy remaining elements
    copy remaining L[i...] to array[k...]
    copy remaining R[j...] to array[k...]
```

Complexity Analysis:
- Time Complexity: O(n log(n))
- Space Complexity: O(n) - needs temporary arrays

This is Stable and Predictable but not In-place and not Adaptive.

---
## Quick Sort
The idea behind quick sort is to choose a pivot element, and partition array so elements < pivot are left, elements > pivot are right, then recursively sort partitions.

Pseudo-Algorithm:
```
quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)  // Partition index
        
        quickSort(array, low, pi - 1)     // Sort left
        quickSort(array, pi + 1, high)    // Sort right

partition(array, low, high):
    pivot = array[high]  // Choose last element as pivot
    i = low - 1          // Index of smaller element
    
    for j = low to high-1:
        if array[j] < pivot:
            i++
            swap(array[i], array[j])
    
    swap(array[i+1], array[high])
    return i + 1
```

Complexity Analysis:
- Time Complexity: Average is $O(n log(n))$, but worst case is $O(n^2)$
- Space Complexity: Average is $O(log(n))$, but worst case is $O(n)$

This is In-Place, but Unstable and not Adaptive.


---

## Heap Sort
The idea is to build a max heap, repeatedly extract maximum element (root), and rebuild heap

The pseudo algorithm looks like this:
```
heapSort(array):
    // Build max heap
    buildMaxHeap(array)
    
    // Extract elements one by one
    for i = n-1 down to 1:
        swap(array[0], array[i])  // Move max to end
        heapSize = heapSize - 1
        maxHeapify(array, 0, heapSize)  // Restore heap

maxHeapify(array, i, heapSize):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    
    if left < heapSize and array[left] > array[largest]:
        largest = left
    if right < heapSize and array[right] > array[largest]:
        largest = right
    
    if largest != i:
        swap(array[i], array[largest])
        maxHeapify(array, largest, heapSize)

buildMaxHeap(array):
    for i = n/2 - 1 down to 0:
        maxHeapify(array, i, n)
```

Complexity Analysis:
- Time complexity: $O(n log(n))$
- Space complexity: $O(1)$

Heap sort is In-Place and guaranteed but unstable and not adaptive.


---
## Counting Sort
The idea is to count frequency of each value then reconstruct sorted arrays. For this to work all the elements must be integers in small range [0, k].

Pseudo-Algorithm:
```
countingSort(array, k):
    count = array of size k+1, initialized to 0
    output = array of size n
    
    // Count occurrences
    for i = 0 to n-1:
        count[array[i]]++
    
    // Cumulative count
    for i = 1 to k:
        count[i] += count[i-1]
    
    // Build output (right to left for stability)
    for i = n-1 down to 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]]--
    
    return output
```

Complexity Analysis:
- Time Complexity: $O(n+k)$ where k=range of input
- Space Complexity: $O(n+k)$

The Counting sort is stable and fast for small range but is not In-Place.

---
## Radix Sort

The idea is to sort numbers digit by digit, from least significant to most significant, using stable sort.

Pseudo-Algorithm:
```
radixSort(array):
    maxVal = maximum value in array
    
    // Sort for each digit position
    for exp = 1; maxVal/exp > 0; exp *= 10:
        countingSortByDigit(array, exp)

countingSortByDigit(array, exp):
    // Counting sort on digit at position exp
    // (exp = 1 for 1s, 10 for 10s, 100 for 100s, etc.)
```

Complexity Analysis:
- Time Complexity: $O(d * (n+k))$
- Space Complexity: $O(n+k)$

Radix Sort is not In-Place but it is Stable. It is also fast for fixed digit length.

---
## Bucket Sort
The idea is to distribute elements into buckets, sort each bucket and then concatenate. 

Complexity Analysis:
- Time Complexity: $O(n^2)$
- Space Complexity: $O(n+k)$

