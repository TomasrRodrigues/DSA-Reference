# Abstract Data Types (ADT)

#### Table of Contents

1. [Introduction](#introduction)
2. [The Concept of Abstraction](#the-concept-of-abstraction)
3. [Procedural vs. Data Abstraction](#procedural-vs-data-abstraction)
4. [What is an ADT?](#what-is-an-adt)
5. [ADT Specification](#adt-specification)
6. [Types of Operations](#types-of-operations)
7. [Mutable vs Immutable Types](#mutable-vs-immutable-types)
8. [Information Hiding and Encapsulation](#information-hiding-and-encapsulation)
9. [Representation Independence](#representation-independence)
10. [Representation Exposure](#representation-exposure)


---
## Introduction

An **Abstract Data Type (ADT)** is one of the most fundamental concepts in computer science and software engineering. It represents a mathematical abstraction—a set of values and operations on those values, defined purely by their behavior rather than their implementation.

The ADT concept embodies several key principles of good software design:
- **Separation of Concerns**: Users of an ADT don't need to know how it works internally—they only need to know what it does.
- **Modularity**: ADTs can be developed, tested, and maintained independently of the code that uses them.
- **Flexibility**: The implementation can be changed without affecting client code, as long as the interface remains the same.
- **Abstraction**: Focus on the essential properties while hiding irrelevant details.

Without ADTs, we would have:
1. **Tight Coupling**: Changes in data structure require changes throughout codebase
2. **Duplicated Effort**: Each piece of code reimplements similar functionality
3. **Error-Prone Ccode**: Direct manipulation of data structures leads to inconsistencies
4. **Poor Maintainability**: Understanding requires knowledge of low-level implementation
5. **Limited Reusability**: Code is too specific to be reused


With ADTs, we achieve:
1. **Loose Coupling**: Client code depends only on the interface
2. **Code Reuse**: Well-designed ADTs can be used in many contexts
3. **Reliability**: Invariants are enforced by the ADT implementation
4. **Maintainability**: Implementation changes don't affect clients
5. **Reasoning**: Can prove properties about ADT operations independently

---
## The Concept of Abstraction

**Abstraction** is the process of removing irrelevant details to focus on the essential characteristics of something.

Computing involves multiple levels of abstraction. 

It works like a stack of abstraction where each level hides details from the level above:
- Applications don't worry about how lists are implemented
- ADTs don't worry about assembly instructions
- Assembly doesn't worry about transistor switching

#### Types of Abstraction

**Procedural Abstraction**: Hides details of how computations are performed. Let's take as an example the sqrt function:
```cpp
double x = sqrt(25.0);  // User doesn't need to know Newton's method
```
Benefits:
- Can optimize implementation without affecting callers
- Can add error checking transparently
- Different implementations for different platforms

**Data Abstraction**: Hides details of how data is represented and organized. Let's take as an example the Stack:
```cpp
Stack<int> s;
s.push(5);
s.push(10);
int x = s.pop();  // User doesn't need to know if it's array or linked list
```
Benefits:
- Can change representation without affecting clients
- Can add invariant checking
- Can optimize for specific usage patterns

**Control Abstraction**: Hides details of control flow. Let's take as an example the for-each loop:
```cpp
for (int x : collection) {
    process(x);  // Don't need to know if it's array, list, tree, etc.
}
```


#### The Abstraction Principle

The abstraction Principle states that each significant piece of functionality in a program should be implemented in just one place. Whenever a similar function is required, the existing function should be called with the appropriate parameters.

**Violation Example**:
```cpp
// Computing average in multiple places
double avg1 = (a + b + c) / 3.0;
double avg2 = (x + y + z) / 3.0;
double avg3 = (p + q + r) / 3.0;
```
**Proper Abstraction**:
```cpp
double average(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

double avg1 = average(a, b, c);
double avg2 = average(x, y, z);
double avg3 = average(p, q, r);
```

---
## Procedural vs Data Abstraction

While related, procedural and data abstraction serve different purposes.

#### Procedural Abstraction

Procedural Abstractions consists on a specification of an operation independent of its implementation. Components:
1. **Signature**: Name and parameters
2. **Specification**: What it does (preconditions, postconditions)
3. **Implementation**: How it does it (hidden from clients)

Example:
```cpp
// Specification (what)
// Precondition: x >= 0
// Postcondition: returns square root of x (within epsilon)
double sqrt(double x);

// Implementation (how) - hidden
double sqrt(double x) {
    // Newton's method implementation
    // Clients don't see this!
}
```

**Benefits**:
- Can swap implementations
- Can optimize for specific ranges of x
- Can add caching/memoization
- Can parallelize if beneficial


#### Data Abstraction
Data abstraction consists on a representation of data independent of its implementation.

**Components**:
1. **Type**: Name and kind
2. **Operations**: What can be done with the data
3. **Representation**: How data is stored

```cpp
// Interface (what)
class Stack {
public:
    void push(int x);
    int pop();
    bool empty();
    // Representation hidden
};

// Implementation options (how) - hidden
// Option 1: Array-based
// Option 2: Linked-list-based
// Clients don't need to know!
```

**Benefits**:
- Can choose best representation for usage pattern
- Can add integrity checks
- Can optimize storage
- Can change representation as requirements evolve


#### Comparison

| Aspect | Procedural Abstraction | Data Abstraction |
|-----|----------|----------| 
| Focus | Operations/Functions | Data + Operations  |
| Hides | Algorithm details | Representation details  |
| Client depends on | Signature & specification | Interface (operations) |
| Example | sort(array) | Stack, Queue |

Best Software relies on both.



---
## What is an ADT?

An **Abstract Data Type** is a mathematical model consisting of:
1. A set of values (the domain)
2. A set of operations on those values
3. A set of properties (axioms) that the operations satisfy

Formally:

$$
ADT = \langle V, O, A \rangle
$$

where:
- $ V=$ set of values
- $O=$ set of operations
- $A=$ set of axioms/properties

#### The Three Perspectives

An ADT can be viewed from three perspectives:

**1. User Perspective** *(What can I do with this ADT)*. It focus on:
- Available operations
- Preconditions and postconditions
- Expected behavior

Example:
```cpp
Stack<int> s;
s.push(5);    // Add element
s.push(10);
int x = s.pop();  // x = 10 (LIFO order)
```

**2. Implementer Perspective** *(How do I implement this ADT efficiently?)*: It focus on:
- Data representation
- Algorithm choice
- Efficiency trade-offs

Example:
```cpp
template<typename T>
class Stack {
private:
    vector<T> items;  // Choice: use vector
    
public:
    void push(T x) { items.push_back(x); }  // O(1) amortized
    T pop() { 
        T x = items.back();
        items.pop_back();
        return x;
    }
};
```

**3. Designer Perspective** *(What operations should this ADT provide?)*: It focus on:
- Completeness (sufficient operations)
- Minimality (no redundant operations)
- Orthogonality (operations independent)
- Consistency (operations work together)

#### The ADT Contract
ADTs establish a contract between users and implementers:
- User Obligations:
    - Respect preconditions
    - Use only public interface
    - Don't depend on representation
- Implementer Obligations:
    - Satisfy postconditions
    - Maintain invariants
    - Provide specified complexity


---
## ADT Specification

Specifying an ADT precisely requires defining its syntax (operations) and semantics (behavior).

**Signature-Based Specifications**: Components:
1. Type name: What the ADT is called
2. Operation signatures: Name, parameters, return type
3. Preconditions: What must be true before operation
4. Postconditions: What will be true after operation

**Axiomatic Specification**: Define ADT through axioms - fundamental properties that hold. These axioms completely define stack behavior.

**Algebraic Specification**: Express operations in terms of each other.

**Invariants**: A property that is always true for a well-formed instance of the ADT. Invariantss simplify reasoning about ADT correctness

---
## Types of Operations

ADT operations fall into four categories based on their effect:

#### 1. Creators
Create new instances of the ADT from scratch. Characteristics:
- No existing ADT instance required
- Return new ADT instance
- May take parameters for initialization

**Examples**:

Stack:
```cpp
Stack<int>();           // Empty stack
Stack<int>(capacity);   // Pre-allocated capacity
```

List:
```cpp
List<int>();                        // Empty list
List<int>{1, 2, 3};                // From initializer list
List<int>(5, 42);                  // 5 elements, all 42
List<int>(other.begin(), other.end()); // From iterators
```

Set:
```cpp
Set<string>();          // Empty set
Set<string>{"a", "b"};  // From initializer list
```

String:
```cpp
string();               // Empty string ""
string("hello");        // From C-string
string(5, 'x');        // "xxxxx"
```


#### 2. Producers
Create new ADT instances from existing ones. Characteristics:

- Take ADT instance(s) as input
- Return new ADT instance
- Don't modify input instances (for immutable ADTs)


**Examples:**

Set:
```cpp
Set<int> union(const Set<int>& other) const;
Set<int> intersection(const Set<int>& other) const;
Set<int> difference(const Set<int>& other) const;
```

String:
```cpp
string substring(int start, int length) const;
string concat(const string& other) const;
string toUpperCase() const;
```

List:
```cpp
List<int> append(const List<int>& other) const;
List<int> reverse() const;
List<int> sublist(int start, int end) const;
```

Mathematical Operations:
```cpp
// Vector ADT
Vector add(const Vector& other) const;
Vector scale(double factor) const;
Vector cross(const Vector& other) const;  // Cross product
```


For immutable ADTs, producers are the main way to "modify" (by creating modified copies).


#### 3. Observers

Extract information from ADT instance. Characteristics:
- Take ADT instance as input
- Return different type (not ADT type)
- Don't modify the instance
- Usually const methods

**Examples**:

Stack:
```cpp
bool empty() const;     // Returns boolean
int size() const;       // Returns integer
int top() const;        // Returns element (not stack)
```

List:
```cpp
int size() const;
bool contains(int x) const;
int get(int index) const;
int indexOf(int x) const;
```

Set:
```cpp
int size() const;
bool contains(int x) const;
bool isSubsetOf(const Set& other) const;
```

String:
```cpp
int length() const;
char charAt(int index) const;
bool startsWith(const string& prefix) const;
int indexOf(char c) const;
```

Map:
```cpp
bool containsKey(const K& key) const;
int size() const;
Set<K> keySet() const;  // Returns set of keys
```



#### 4. Mutators
Modify existing ADT instance. Characteristics:
- Take ADT instance as input (implicit `this`)
- Modify the instance
- Often return void (or reference for chaining)
- Only in mutable ADTs

**Examples**:

Stack (mutable):
```cpp
void push(int x);       // Adds element
void pop();            // Removes element
void clear();          // Removes all elements
```

List (mutable):
```cpp
void add(int x);
void remove(int index);
void set(int index, int value);
void sort();
void clear();
```

Set (mutable):
```cpp
void insert(int x);
void remove(int x);
void clear();
```

Map (mutable):
```cpp
void put(K key, V value);
void remove(K key);
void clear();
```


Immutable ADTs have no mutators


#### Design Considerations

**Completeness**: Does the ADT provide all necessary operations?
**Minimality**: Are there redundant operations?
**Balance**: Provide convenience methods that are frequently useful, but not every possible combination.


---
## Mutable vs Immutable Types

One of the most important design decisions is whether an ADT should be mutable or immutable.

#### Mutable ADTs

Mutable ADTs instances can be modified after creation. Characteristics:
- Have mutator operations
- Single instance can change over time
- More memory efficient (modify in place)
- Can lead to aliasing issues

The advantages are:
1. Memory Efficiency: Modify in place, no copying
2. Performance: Can be faster (no allocation/deallocation)
3. Natural for some problems: Accumulation, state machines
4. Matches imperative style: Familiar to most programmers

The disadvantages are:
1. liasing Issues: Multiple references to same object
2. Side Effects: Hard to reason about which operations modify what
3. Thread Safety: Concurrent access requires synchronization
4. Debugging: State changes over time, harder to track
5. Undo/History: Can't keep old versions without explicit copying


#### Immutable ADTs
Immutable ADT instances cannot be modified after creation. Characteristics:
- No mutator operations
- All "modifications" create new instances
- Original instance never changes
- Safe to share references


The advantages are:
- Thread Safety: Multiple threads can safely access without synchronization
- Reasoning: Easier to reason about code (no side effects)
- Caching: Can safely cache references
- Hashing: Hash value never changes
- History/Undo: Old versions automatically preserved
- Aliasing Safe: Sharing is safe

The disadvantages are:
- Memory Overhead: Creating many instances
- Performance: Allocation/deallocation costs
- Unnatural for some problems: Accumulation requires many intermediate objects
- Requires functional style: Less familiar to imperative programmers


#### When to choose which?

Choose mutable when:
- Building up large collections incrementally
- Performance is critical and modification is frequent
- Working in single-threaded context
- Natural imperative algorithm

Choose immutable when:
- Concurrent access is needed
- Values used as keys in hash tables
- Want functional programming style
- History/undo is important
- Value objects (coordinates, dates, etc.)

Sometimes the best approach is both (Hybrid Approach):
- Mutable for construction
- Immutable after construction

---
## Information Hiding and Encapsulation

Two related but distinct concepts that are fundamental to ADTs.

**Information Hiding**: Design principle that module's implementation details should be hidden from clients. The purpose is to:
- Reduce coupling between modules
- Allow implementation changes without affecting clients
- Simplify client code


**Encapsulation**: Bundling data and operations that work on that data into a single unit (object/class). The purpose is to:
- Group related functionality
- Maintain invariants
- Provide coherent interface

Encapsulation allows enforcing invariants.

**Information Hiding vs Encapsulation**:

| Aspect | Information Hiding | Encapsulation |
|-----|----------|----------|
| Focus | What to Hide | What to bundle |
| Goal | Reduces dependencies | Group related items |
| Mechanism | Private/protected access | Classes/objects |
| Benefits | Flexibility to change | Coherent interface |

Envapsulation bundles things together and information hiding decides what to expose.


---
## Representation Independence

**Representation Independence**: Clients should be independent of the ADT's internal representation. The benefit is that implementation can change without affecting client code.

#### Example: 2D Point

**Representation 1**: Cartesian coordinates
```cpp
class Point {
private:
    double x, y;
    
public:
    Point(double x, double y) : x(x), y(y) {}
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    double getR() const { return sqrt(x*x + y*y); }
    double getTheta() const { return atan2(y, x); }
};
```

**Representation 2**: Polar coordinates
```cpp
class Point {
private:
    double r, theta;
    
public:
    Point(double x, double y) : r(sqrt(x*x + y*y)), theta(atan2(y, x)) {}
    
    double getX() const { return r * cos(theta); }
    double getY() const { return r * sin(theta); }
    
    double getR() const { return r; }
    double getTheta() const { return theta; }
};
```

For the client, code looks the same:
```cpp
Point p(3, 4);
cout << p.getX();     // Works with both representations
cout << p.getR();     // Works with both representations
```

The benefirs of this are:
1. Optimization: Choose best representation for use case
2. Evolution: Change representation as requirements change
3. Multiple Implementations: Provide alternatives for different scenarios


To achieve representation independence, some techniques are followed:
1. Hide representation (private)
2. Provide abstract interface (public methods)
3. Document behavior, not implementation
4. Avoid representation exposure

---
## Representation Exposure

Representation exposure occurs when internal representation details are visible or modifiable by clients, breaking encapsulation and representation independence.

#### Common Causes

**1. Public Fields**: Fields must be private:
```cpp
class GoodPoint {
private:
    double x, y;
    
public:
    void setX(double newX) {
        // Can add validation
        x = newX;
    }
};
```

**2. Returning References to Mutable Fields**: Two options:
- Return by value:
```cpp
Date getTimestamp() const {
    return timestamp;  // Returns copy
}
```

- Return const reference:
```cpp
const Date& getTimestamp() const {
    return timestamp;  // Can't modify
}
```

**3. Accepting Mutable Parameters**:
Bad:
```cpp
class Gradebook {
private:
    vector<int> grades;
    
public:
    Gradebook(vector<int>& g) : grades(g) {}  // Stores reference!
};

// Client can modify internal state
vector<int> myGrades = {90, 85, 95};
Gradebook book(myGrades);
myGrades[0] = 100;  // Oops! Modified gradebook's internal data
```

Two options to fix it:
- Copy:
```cpp
Gradebook(const vector<int>& g) : grades(g) {}  // Makes copy
```

- Move:
```cpp
Gradebook(vector<int>&& g) : grades(std::move(g)) {}  // Takes ownership
```


**4. Aliasing Through Iterators**


#### Defensive Copying

The strategy is to make copies to prevent representation exposure. This should be used when:
1. In Constructors: Copy mutable parameters
2. In accessors: Return copies of mutable fields
3. When accepting collections: Copy to prevent external modification

