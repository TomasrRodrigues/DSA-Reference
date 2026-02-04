# Abstract Data Types (ADT)

#### Table of Contents

1. [Introduction](#introduction)
2. [Procedural vs. Data Abstraction](#procedural-vs-data-abstraction)
3. [What is an ADT?](#what-is-an-adt)
4. [Types of Operations](#types-of-operations)

---
## Introduction

An Abstract Data Type (ADT) is a data type defined by its behavior (operations) from the user's point of view, hiding implementation details.

The key concepts here are:
- Abstraction: Focus on what, not how
- Encapsulation: Bundle data and operations together
- Information Hiding: Hide implementation details from users

Without ADTs, data structure decisions are made too early, the effort to create derived data is much higher and it is very hard to change key data structures. 

Benefits of ADTs:
- Easier to maintain and modify
- Reduce coupling between components
- Allow implementation changes without affecting users
- Enable reasoning about correctness more easily

---
## Procedural vs Data Abstraction

There are two main ways of abstraction: Procedural Abstraction and Data Abstraction.

#### Procedural Abstraction

Procedural abstraction consists in:
- Abstract from details of procedures
- Specification is the abstraction
- Satisfy specification with an implementation
- Use depends on what it does, not how it does it

Example:
```cpp
// User knows what this does (sorts), not how
void sort(vector<int>& v);
```

#### Data Abstraction
Data abstraction consists in:
- Abstract from details of data representation
- Also a specification mechanism
- Users depend on operations, not internal structure

```cpp
// User knows they can push/pop, not how stack is implemented
class Stack {
    void push(int x);
    int pop();
    // Implementation hidden
};
```

---
## What is an ADT?

Definition:
$$
ADT = Data + Operations
$$

An ADT is a specification of:
1. Data that can be stored
2. Operations that can be performed on that data

Basically, users interact only through operations, never directly with data.

#### Example: Different Representation, Same ADT

Consider a 2D point:
```cpp
// Representation 1: Cartesian coordinates
class Point {
    float x;
    float y;
};

// Representation 2: Polar coordinates
class Point {
    float r;      // radius
    float theta;  // angle
};
```

Key Insight: Both represent the same concept ("2D Point"), just with different internal representations.

The goal of ADT Methodology is to express the sameness of different implementations:
- Users depend only on the concept
- Implementation can change without affecting user code
- Choose representation based on efficiency needs


---
## Types of Operations

ADT operations are classified into four categories:

#### 1. Creators
Create new objects of the type
```cpp
// IntSet: empty set
IntSet()

// IntSet: set with single element
IntSet(int x)

// Point: from coordinates
Point(float x, float y)
```
Applicable to both mutable and immutable types


#### 2. Producers
Create new objects from old objects of the type

```cpp
// IntSet: union of two sets
IntSet union(const IntSet& s2) const

// Point: translate by vector
Point translate(float dx, float dy) const
```

Characteristics:
- More common in immutable ADTs
- Mutable ADTs may have producers too
- Do NOT modify original object


#### 3. Observers
Extract information from objects (return different type)

```cpp
// IntSet: check membership
bool contains(int x) const

// IntSet: get size
int size() const

// Point: get X coordinate
float getX() const
```

Characteristics:
- Return type $≠$ the ADT type
- Don't modify the object (usually const)
- Used to obtain information about objects

#### 4. Mutators
Modify objects of the type:
```cpp
// IntSet: add element
bool add(int x)

// IntSet: remove element
bool remove(int x)

// Point: set coordinates
void setX(float x)
```

Characteristics:
- Only in mutable ADTs
- Modify the object's state
- Often return success/failure status


---
## Mutable vs Immutable Types

Comparison Table:

| Feature | Mutable | Immutable |
|---------|---------|-----------|
| **Can be changed** | ✓ | ✗ |
| **Creators** | ✓ | ✓ |
| **Producers** | ✓ | ✓ |
| **Observers** | ✓ | ✓ |
| **Mutators** | ✓ | ✗ |

Advantages of Immutability are that:
1. Thread-safe: No synchronizaation needed
2. Easier to reason about: Object never changes
3. Can be shared freely: No defensive copying needed
4. Better for Hashing: Hash value never changes

Advantages of Mutability:
1. More efficient: No need to create new objects
2. Natural for some problems: e.g., accumulating results
3. Less memory usage: Modify-in-place


---
## Representation Exposure

Representation exposure occurs when code outside the class can modigy the representation directly, breaking encapsulation.

```cpp
// Intended to be immutable!
class Tweet {
    string author;
    string text;
    Date timestamp;  // Date is MUTABLE
    
public:
    Tweet(string a, string t, Date ts) 
        : author(a), text(t), timestamp(ts) {}
    
    string getAuthor() const { return author; }
    string getText() const { return text; }
    
    // DANGER! Returns reference to mutable object
    Date& getTimestamp() { return timestamp; }
};
```

There are some rules to avoid representation exposure:
1. Never return references/pointers to mutable fields
2. Make defensive copies when returning mutable objects
3. Use const liberally to prevent modification
4. Consider immutable types for fields when possible
5. In constructors: Make defensive copies of mutable parameters

