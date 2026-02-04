# Algorithm Correctness Analysis

#### Table of Contents

1. [Introduction](#introduction)
2. [Algorithm Design Philosophy](#algorithm-design-philosophy)
3. [Preconditions and Postconditions](#preconditions-and-postconditions)
4. [Partial vs Total Correctness](#partial-and-total-correctness)
5. [Loop Invariants and Variants](#loop-invariants-and-variants)
6. [Implementation Examples](#implementation-examples)

---
## Introduction

Algorithm correctness analysis is fundamental to ensuring that the code behaves as expected. As Tony Hoare famously stated:
> "There are two ways of constructing a software desgin: One way is to make it so simple that there are obviously no deficiencies and the other way is to make it so complicated that there are no obvious deficiencies. The first method is far more difficult."

Therefore there are two approaches to analysis:

| Aspect | Theoretical Analysis | Experimental Analysis |
|---|---|---|
| Correctness | Proof or argumentation | Pre-defined or random tests* |
| Efficiency | Complexity Analysis | Performance Tests |

*As Dijkstra stated, "Testing shows the presence, not the absence of bugs"

---
## Algorithm Design Philosophy
Good algorithm design requires:
- Clear problem specification
- Strict algorithm specification
- Proof of correctness
- Efficiency analysis

---
## Preconditions and Postconditions
A problem is specified by:
- **Inputs:** Input data and associated restrictions
- **Outputs:** Output data and associated restrictions (postconditions)

To prove algorithm correctness we need to check the preconditions and the postconditions:
- **Preconditions:** Conditions that must be true before the algorithm executes
- **Postconditions:** Conditions that must be true after the algorithm executes (assuming preconditions were met)

#### Examples:
##### Square Root Function:
```cpp
double squareRoot(double x)
```
- Preconditions: $x \geq 0$
- Postconditions:
    - $RESULT * RESULT = x$ (within acceptable error)
    - $RESULT \geq 0$

##### Sum Function:
```cpp
long sum(int n)
```
- Preconditions: $n>0$
- Postconditions: $RESULT = 1 + 2 + ... + n$

##### Maximum Function
```cpp
template <typename T> T max(vector<T> v)
```
- Preconditions:
    - $v ≠ null$
    - Comparison operators defined in T
- Postconditions:
    - $RESULT = v[0]$ or $RESULT = v[1]$ or ... or $RESULT = v[n-1]$
    - $RESULT \geq v[0]$ and $RESULT \geq v[1]$ and ... and $RESULT \geq v[n-1]$

##### Sort Function
```cpp
template <typename T> void sort(vector<T> v)
```
- Preconditions: Comparison operators defined in T
- Postconditions:
    - $v[0] \leq v[1] \leq ... \leq v[n-1]$
    - v has the same elements as initially

---
## Partial and Total Correctness

An algorithm is said to be **partially correct** if the algorithm is executed with inputs that respect the precondition, then, if it ends, it produces correct outputs that respect the postconditions.

It is said to be **totally correct** if the algorithm is executed with inputs that respect the preconditions and then it ends producing correct outputs that respect the postconditions.

The key difference between being partially and total correctness is the guarantee of termination.

---
## Loop Invariants and Variants

A loop invariant is a statement about the state of some variable(s) that can be reliably held true before and after each iteration of the loop.

To prove loop correctness using an invariant, we must show that:
1. Initialization: The invariant is true initially (implied by precondition)
2. Maintenance: The invariant is maintained at each iteration
3. Termination: When the loop ends, the invariant guarantees the postcondition

We must use loop invariants like this:
1. Identify what should be true at each iteration
2. Prove it's true before the first iteration
3. Prove it remains true after each iteration
4. Show it implies the postcondition when the loop terminates

A loop invariant is a function a function using variables of the loop that is Integer, Non-Negative and decreases with each iteration. Loop variants prove that a loop terminates (ends). Properties:
- Must be $\geq$ 0
- Must decrease with each iteration
- Eventually reaches 0, causing termination

#### Examples
##### Sum Algorithm
```cpp
// Returns the sum 1+2+3+...+n
long sum(int n) {
    long sum = 0;
    int k = 1;
    while (k <= n) {
        sum += k;
        k++;
    }
    return sum;
}
```
- Loop Invariant: At step k, sum holds the sum of numbers 1 to k-1
- Proof of Correctness:
    1. Initialization:
        - Before first iteration: $k=1$, $sum=0$
        - The sum of numbers in range 1..0 is zero (no numbers)
        - Invariant is true
    2. Maintenance:
        - Assume invariant is true at beginning of step k: $sum = 1 + 2 + ... + (k-1)$
        - After executing step k:
            - $sum+=k \rightarrow sum = 1+2+...+(k-1)$ 
            - $k++ \rightarrow$ becomes k+1
        - At beginning of step k+1: $sum = 1 + 2 + ... + k$
        - Invariant holds for k+1
    3. Termination:
        - Loop terminates when $k = n+1$
        - At that point: $sum=1+2+...+(n+1-1) =1+2+...+n$
        - Postcondition satisfied
- Loop Variant: $variant = n+1-k$
    - Integer: Yes
    - Non-negative: Yes
    - Decreasing: Yes

Conclusion: Algorithm is correct

##### Maximum Value (Incorrect)
```cpp
// Returns the max value of vector v
int max(const vector<int> v) {
    int max = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        // invariant: max = max(v[0], v[1],..., v[i-1])
        if (v[i] > max)
            max = v[i];
    }
    return max;
}
```

Loop Invariant: At step i, max holds the maximum value of $v[0]...[i-1]$

This satisfies both termination and maintenance but does not satisfy initialization. This is because before the first iteration ($i=0$), max should equal max ($v[0]..v[-1]$). But there are no elements in that range, so the invariant doesn't hold properly.


##### Maximum Value (Corrected)

```cpp
// Returns the max value of vector v
int max(const vector<int> v) {
    if (v.size() == 0)
        throw std::invalid_argument("empty vector");
    
    int max = v[0];  // Initialize with first element
    for (int i = 1; i < v.size(); i++) {
        // invariant: max = max(v[0], v[1],..., v[i-1])
        if (v[i] > max)
            max = v[i];
    }
    return max;
}
```

Changes made:
1. Check for empty vector
2. Intialize $max = v[0]$ instead of INT_MIN
3. Start loop at $i=1$ instead of $i=0$

Now all three properties are satisfied
---
## Implementation Examples

TO ADD IMPLEMENTATIONS