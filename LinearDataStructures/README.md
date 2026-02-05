# Linear Data Structures: List, Stack, Queue

#### Table of Contents
1. [Introduction](#introduction)
2. [Lists](#lists)
3. [Stacks](#stacks)
4. [Queues](#queues)

---
## Introduction
A Linear Data Structure is a data structure where elements are arranged sequentially, one after another. In this type of data structures, elements have a specific order, each element (except first and last) has exactly one predecessor and one successor and can be traversed sequentially.

The main types of Linear Data Structures are:
1. Lists: General sequence with access anywhere
2. Stack: LIFO (Last-In-First-Out) access
3. Queue: FIFO (First-In-First-Out) access


---
## Lists
By definition, a list is a sequence of elements of the same type: $A_0, A_1, A_2, ..., A_{n-1}$.

List Operations:

| Operation | Description | Example |
|-----------|-------------|---------|
| **Create** | Create empty list | `List()` |
| **Insert** | Add element at position | `insert(x, pos)` |
| **Remove** | Remove element | `remove(x)` |
| **Find** | Locate element position | `find(x)` |
| **Size** | Get number of elements | `size()` |
| **Concatenate** | Join two lists | `concat(L1, L2)` |

### Iterators

An iterator is an object that references an element of certain ADTs and provides a way to traverse the structure.

The purpose is to:
- **Encapsulate** information about current position
- **Abstract** the traversal mechanism
- **Separate** iteration logic from data structure

#### Pattern

```
┌──────────────────────┐
│   A₀  A₁  A₂  A₃  A₄ │  ← Data Structure
└──────────────────────┘
        ↑
        │
    Iterator (points to A₁)
```

#### Iterator Categories


| Category | Can Read | Can Write | Direction | Jump |
|----------|----------|-----------|-----------|------|
| **Input** | ✓ | | Forward | No |
| **Output** | | ✓ | Forward | No |
| **Forward** | ✓ | ✓ | Forward | No |
| **Bidirectional** | ✓ | ✓ | Both | No |
| **Random Access** | ✓ | ✓ | Both | ✓ |


### List Implementations

There are two main approaches when it comes to implementing Lists:
1. **Array-based** (contiguous memory)
2. **Linked list** (scattered memory with pointers)

#### Array-Based Lists

The structure looks something like this:

```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ x │ m │ s │   │   │   │   │   │   │  ← elements array
└───┴───┴───┴───┴───┴───┴───┴───┴───┘
capacity = 9
used = 3
```

The advantages of this implementation are:
- Fast random access: $O(1)$
- Simple implementation
- Cache-friendly (contiguous memory)

The disadvantages of this implementation are:
- Fixed capacity (need to resize/reallocate)
- Insertion/deletion in middle: $O(n)$
- Wasted space if not full

Complexity Analysis:

| Operation | Time Complexity |
|-----------|----------------|
| Access by index | O(1) |
| Insert at end | O(1) amortized* |
| Insert at position | O(n) |
| Remove from position | O(n) |
| Search | O(n) |

*Amortized: occasional O(n) for reallocation, but O(1) on average

[Array-Based List Implementation](/LinearDataStructures/Implementation/array-based-list.cpp)


#### Linked Lists

Linked Lists work differently. The structure looks like this:

```
┌────┬────┐   ┌────┬────┐   ┌────┬────┐   ┌────┬────┐
│ A₀ │  ●─┼──→│ A₁ │  ●─┼──→│ A₂ │  ●─┼──→│ A₃ │NULL│
└────┴────┘   └────┴────┘   └────┴────┘   └────┴────┘
```

Each node contains:
1. **Element**: The data being stored
2. **Next pointer**: Reference to the next node (or NULL)

The advantages of this implementation are:
- Dynamic size (no capacity limit)
- Fast insertion/deletion at any position: $O(1)$
- No wasted space (exact size needed)

The disadvantages are that:
- No random access: $O(n)$ to reach position
- Extra memory for pointers
- Cache-unfriednly (scattered in memory)

Complexity Analysis:

| Operation | Time Complexity |
|-----------|----------------|
| Access by index | O(n) |
| Insert at given position | O(1)* |
| Insert after search | O(n) |
| Remove at given position | O(1)* |
| Remove after search | O(n) |
| Search | O(n) |

*If we already have a pointer to that position

##### Using a Header (Dummy Node)

**Benefits:**
- Simplifies code (no special case for empty list)
- First element is no longer special
- Makes operations more uniform


```
Empty list with header:
┌────┬────┐
│    │NULL│  ← header (dummy node)
└────┴────┘

Non-empty list with header:
┌────┬────┐   ┌────┬────┐   ┌────┬────┐
│    │  ●─┼──→│ A₀ │  ●─┼──→│ A₁ │NULL│
└────┴────┘   └────┴────┘   └────┴────┘
  header      element next  element next
```

[Linked List Implementation](/LinearDataStructures/Implementation/linked-list.cpp)


##### Insertion Operation

```
Before insertion of N between P and Q:
┌────┬────┐   ┌────┬────┐
│ P  │  ●─┼──→│ Q  │  ●─┼──→ ...
└────┴────┘   └────┴────┘

┌────┬────┐
│ N  │    │  ← New node
└────┴────┘

After insertion:
┌────┬────┐   ┌────┬────┐   ┌────┬────┐
│ P  │  ●─┼──→│ N  │  ●─┼──→│ Q  │  ●─┼──→ ...
└────┴────┘   └────┴────┘   └────┴────┘

Code:
N->next = P->next;  // N points to Q
P->next = N;        // P points to N
```

##### Deletion Operation

```
Before deletion of D:
┌────┬────┐   ┌────┬────┐   ┌────┬────┐
│ P  │  ●─┼──→│ D  │  ●─┼──→│ Q  │  ●─┼──→ ...
└────┴────┘   └────┴────┘   └────┴────┘

After deletion:
┌────┬────┐   ┌────┬────┐
│ P  │  ●─┼──→│ Q  │  ●─┼──→ ...
└────┴────┘   └────┴────┘

┌────┬────┐
│ D  │    │  ← To be deleted
└────┴────┘

Code:
P->next = D->next;  // P points to Q
delete D;           // Free memory
```

#### Variations of Linked Lists

##### 1. Doubly Linked List
It works just like a simple Linked List but instead of having only one pointer pointing forward, it has another pointer pointing back:
- **next**: pointer to next node
- **prev**: pointer to previous node


```
┌────┬────┬────┐   ┌────┬────┬────┐   ┌────┬────┬────┐
│NULL│ A₀ │  ●─┼──→│ ←● │ A₁ │  ●─┼──→│ ←● │ A₂ │NULL│
└────┴────┴────┘   └────┴────┴────┘   └────┴────┴────┘
 prev element next  prev element next  prev element next
```

**Advantages:**
- Can traverse in both directions
- Easier deletion (don't need previous node)

**Disadvantages:**
- More memory (two pointers per node)
- More complex to maintain


##### 2. Circular Linked List

Last node points back to first (or header):

```
      ┌────────────────────────────────┐
      │                                │
      ↓                                │
┌────┬────┐   ┌────┬────┐   ┌────┬────┐
│ A₀ │  ●─┼──→│ A₁ │  ●─┼──→│ A₂ │  ●─┤
└────┴────┘   └────┴────┘   └────┴────┘
```

**Advantages:**
- Can start anywhere and reach all nodes
- Useful for round-robin scheduling


##### 3. Doubly Circular Linked List

Combines both:
- Each node has prev and next
- Last connects to first


#### Array vs Linked List Comparison


| Feature | Array-Based | Linked List |
|---------|-------------|-------------|
| **Random Access** | O(1) ✓ | O(n) ✗ |
| **Insert/Delete at end** | O(1) ✓ | O(n)* |
| **Insert/Delete at position** | O(n) | O(1)** |
| **Memory** | May waste space | Exact size + pointers |
| **Cache Performance** | Good ✓ | Poor ✗ |
| **Implementation** | Simple ✓ | More complex |

*Need to traverse to end
**Given pointer to position

We should use:
- Array-Based when:
    - Need random access
    - Size is relatively stable
    - Insertions/deletions are rare or at end only
    - Cache performance matters
- Linked-List when:
    - Frequent insertions/deletions in middle
    - Size changes dramatically
    - Don't need random access
    - Have pointers to positions


---

## Stacks

By definition a Stack is a Last-In-First-Out sequence. We can think of it as a stack of plates where we add new plates to the top of the stack and remove them from the top also.

Visually:

```
┌───┐
│ 5 │ ← top
├───┤
│ 4 │
├───┤
│ 3 │
├───┤
│ 2 │
├───┤
│ 1 │
└───┘
```

Typical Operations:

| Operation | Description | Complexity |
|-----------|-------------|------------|
| **push(x)** | Add x to top | O(1) |
| **pop()** | Remove top element | O(1) |
| **top()** | View top element | O(1) |
| **isEmpty()** | Check if empty | O(1) |
| **size()** | Get number of elements | O(1) |

### Stack Implementation
We can use either:
1. **Array-based** (vector)
2. **Linked list-based**

Both support $O(1)$ operations.

[Stack Implementation using Linked List](/LinearDataStructures/Implementation/stack-linked-list.cpp)



---
## Queues

By definition, a queue is a First-In-First-Out (FIFO) sequence.
This works like a line at a store where the first person in line is served first.

It looks like this:
Front                         Rear
  ↓                            ↓
┌───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 4 │ 5 │
└───┴───┴───┴───┴───┘
  ↑                     ↑
Dequeue here      Enqueue here

Typical operations:

| Operation | Description | Complexity |
|-----------|-------------|------------|
| **enqueue(x)** | Add x to rear | O(1) |
| **dequeue()** | Remove from front | O(1) |
| **front()** | View front element | O(1) |
| **isEmpty()** | Check if empty | O(1) |
| **size()** | Get number of elements | O(1) |


### Queue Implementations

#### 1. Using Linked List

This implementation is simple but `enqueue()` is $O(n)$ because we need to find the end. Better implementation would keep a tail pointer.

[Queue Implementation using Linked List](/LinearDataStructures/Implementation/queue-linked-list.cpp)

#### 2. Optimized Linked List Queue
Similar logic to the linked list one but keeping a pointer to the front and to the end of the list.

[Queue Optimized Implementation using Linked List](/LinearDataStructures/Implementation/queue-optimized-linked-list.cpp)


#### 3. Circular Array Implementation
Using a circular array efficiently uses space.

**Circular Array Visualization**:

```
Initial: capacity=8, front=0, rear=0, count=0
┌───┬───┬───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
 0   1   2   3   4   5   6   7
 ↑
front, rear

After enqueue(A,B,C,D): front=0, rear=4, count=4
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ A │ B │ C │ D │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
 0   1   2   3   4   5   6   7
 ↑               ↑
front           rear

After dequeue() twice: front=2, rear=4, count=2
┌───┬───┬───┬───┬───┬───┬───┬───┐
│   │   │ C │ D │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
 0   1   2   3   4   5   6   7
         ↑       ↑
       front    rear

After enqueue(E,F,G,H,I): front=2, rear=1, count=7 (WRAPPED!)
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ I │   │ C │ D │ E │ F │ G │ H │
└───┴───┴───┴───┴───┴───┴───┴───┘
 0   1   2   3   4   5   6   7
     ↑   ↑
   rear front
```

[Queue Circular Array Implementation](/LinearDataStructures/Implementation/queue-circular-array-implementation.cpp)

