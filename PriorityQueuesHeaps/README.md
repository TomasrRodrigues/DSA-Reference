# Priority Queues and Heaps

#### Table of Contents


---
## Introduction
A Priority Queue is an Abstract Data Type where each element has an associated priority. Elements are served based on their priority, not insertion order.

The key difference from a regular queue to a priority queue is that a Queue is FIFO (First In, First Out) while in the Priority Queue, highest priority comes first.

Common operations are:
- insert(x)/push(x): Add element with priority
- findMax()/top(): Return element with highest priority
- deleteMax()/pop(): Remove and return highest priority element
- isEmpty(): Checks if empty
- size(): Number of elements

This can be implemented using one of many other data structures:

| Implementation | insert | findMax | deleteMax |
|----------------|--------|---------|-----------|
| **Unsorted Array** | O(1) | O(n) | O(n) |
| **Sorted Array** | O(n) | O(1) | O(1) |
| **Unsorted Linked List** | O(1) | O(n) | O(n) |
| **Sorted Linked List** | O(n) | O(1) | O(1) |
| **Binary Search Tree** | O(log n) | O(log n) | O(log n) |
| **Binary Heap** | **O(log n)** | **O(1)** | **O(log n)** |


---
## Binary Heap Structure

A Binary Heap is a complete binary tree that satisfies the heap property:
- Max-Heap Property: For every node i (except root): $value(parent(i)) \geq value(i)$
- Min-Heap Property: For every node i (except root): $value(parent(i)) \leq value(i)$



# TODO- FINISH
