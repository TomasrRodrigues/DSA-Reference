# Algorithm Complexity 

#### Table of Contents
1. [Introduction](#introduction)
2. [Time and Space Complexity](#time-and-space-complexity)
3. [Asymptotic Analysis Fundamentals](#asymptotic-analysis-fundamentals)
4. [Big-O Notation](#big-o-notation)
5. [Other Asymptotic Notations](#other-asymptotic-notations)
6. [Analyzing Algorithms](#analyzing-algorithms)
7. [Recurrence Relations](#recurrence-relations)
8. [Amortized Analysis](#amortized-analysis)
9. [Case Study: Maximum Subsequence Sum](#case-study-maximum-subsequence-sum)
10. [Practical Considerations](#practical-considerations)

---
## Introduction

Algorithm complexity analysis is the theoretical study of computer program performance and resource usage. Rather than measuring actual execution time (which varies by machine, implementation, and input), we analyze how the algorithm's resource requirements grow as the input size increases.

An algorithm is a clearly specified set of instructions to solve a problem. Once we establish correctness, the next crucial question we must answer is how much resources does it require?

There are two faces of efficiency:
1. **Time Complexity**: How execution time grows with input size
2. **Space Complexity**: How memory usage grows with input size

These are often trade-offs: faster algorithms may use more memory, and vice versa.

We must analyze complexity to:
- Compare different algorithms for the same problem
- Predict how resource requirements grow with input size
- Choose the most efficient algorithm for a problem

As Donald Knuth stated: "Premature optimization is the root of all evil." But informed optimization, guided by complexity analysis, is essential for building scalable systems.


---
## Time and Space Complexity

To analyze efficiency we must analyze both the time and space complexity.

#### Time Complexity
Time complexity, $T(n)$, is a function that describes the number of primitive operations an algorithm performs as a function of input size n.

Primitive Operations (each counted as one unit):
- Arithmetic operations: `+`, `-`, `*`, `/`, `%`
- Comparisons: `<`,`>`,`==`,`!=`,`<=`,`>=`
- Assignments: `=`
- Array access: `arr[i]`
- Function calls/returns

Not counted (absorbed into constants):
- Declaration statements
- Comments
- Syntax elements (braces, parentheses)

**Example: Counting Operations**:
```cpp
int sum_array(const vector<int>& arr) {
    int sum = 0;              // 1 operation (assignment)
    for (int i = 0; i < arr.size(); i++) {  // 1 (init) + n+1 (comparisons) + n (increments)
        sum += arr[i];        // n (additions) + n (array accesses) + n (assignments)
    }
    return sum;               // 1 operation (return)
}
```
**Total Operations**:
$$
T(n) = 1 + 1 + (n + 1) + n + 3n + 1 = 5n +4
$$

But we typically write this as $T(n)=O(n)$ because constants don't matter for large n.


#### Space Complexity

Space complexity $S(n)$ describes the amount of memory an algorithm uses as a function of input size n.

Components:
1. **Input Space**: Memory for input data (usually not counted)
2. **Auxiliary Space**: Extra memory used by algorithm
3. **Output Space**: Memory for output (sometimes counted)

Typically, when we say "space complexity," we mean auxiliary space.

**Example: Space Analysis**:
```cpp
// O(1) auxiliary space - only uses a few variables
int sum_array(const vector<int>& arr) {
    int sum = 0;      // O(1)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

// O(n) auxiliary space - creates new array
vector<int> double_array(const vector<int>& arr) {
    vector<int> result(arr.size());  // O(n) space
    for (int i = 0; i < arr.size(); i++) {
        result[i] = arr[i] * 2;
    }
    return result;
}

// O(n) auxiliary space - recursive call stack
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // Each call uses stack space
}
// Call stack depth = n, so S(n) = O(n)
```


| Case | Description | Usefulness |
|--|----|---|
| Best Case | Minimum time/space needed over all inputs of size $n$ | Usually not very informative |
| Average Case | Expected time/space over all inputs of size n | Most realistic, but hard to analyze |
| Worst Case | Maximum time/space needed over all inputs os size n | Provides guarantees, commonly analyzed |


**Example: Linear Search**:
```cpp
int linear_search(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Found!
        }
    }
    return -1;  // Not found
}
```
**Case Analysis:**
- **Best Case**: $T_{best} (n) = O(1)$ - target is first element
- **Worst Case**: $T_{worst} (n) = O(n)$ - target is last element or not present
- **Average Case**: $T_{avg}(n) = O(n)$ - on average, check half the elements

For most algorithms, we focus on worst-case complexity because it provides guarantees.


---
## Asymptotic Analysis Fundamentals

The key insight, is that for large inputs, the growth rate dominates the exact count of operations.

As n grows, the $n^2$ term dominates completely. The other terms become negligible. This is shy we can simplify $3n^2+100n+500$ to just $O(n^2)$

**Principles of Asymptotic Analysis**:
1. Ignore Constants
2. Ignore Lower-Order Terms
3. Focus on Dominant Term

By ignoring constants, we focus on the fundamental algorithmic efficiency, which is independent of these factors.


---
## Big-O Notation

Big-O notation provides an upper bound on the growth rate of a function. Let $f(n)$ and $g(n)$ be functions mapping positive integers to positive real numbers.

$$
f(n)=O(g(n))
$$

if and only if there exist positive constants $c$ and $n_0$ such that:
$$
f(n) \leq c \cdot g(n) \quad \text{for all } n \geq n_0
$$

Basically, big-O provides an upper bound on the growth rate of a function. For sufficiently large n, $f(n)$ grows no faster than $g(n)$.

**Properties of Big-O**:
1. **Transitivity**: If $f=O(g)$ and $g=O(h)$, then $f=O(h)$
2. **Sum Rule**: If $f_1=O(g_1)$ and $f_2=O(g_2)$, then:
$$
f_1+f_2 = O(max(g_1,g_2))
$$
More formally: $f_1+f_2=O(g_1+g_2)$
3. **Product Rule**: If $f_1 = O(g_1)$ and $f_2=O(g_2)$, then:
$$
f_1 \cdot f_2 = O(g_1 \cdot g_2)
$$
4. **Polynomial Rule**: If $f(n)$ is a polynomial of degree k:
$$
f(n)=a_kn^k+a_{k-1}n^{k-1} + ... + a_1n+ a_0
$$
Then: $f(n) = O(n^k)$
5. **Logarithm Rule**: For any constants $k>0$ and $b>1$:
$$
log^kn=O(n)
$$
That is, any power of logarithm grows slower than any positive power of n.

---
## Other Asymptotic Notations
While big-O is most common, other notations provide different bounds.

##### Big-Omega (Ω) - Lower Bound
$f(n) = Ω(g(n))$ if there exists positive constants $c$ and $n_0$, such that:
$$
f(n) \geq c \cdot g(n) \quad \text{for all } n \geq n_0
$$
This means that $g(n)$ is a lower bound on $f(n)$. The function grows at least as fast as $g(n)$

##### Big-Theta (Θ) - Tight Bound
$f(n) = Θ(g(n))$ if and only if:
$$
f(n) = O(g(n)) \quad \text{and} \quad f(n) = Ω(g(n))
$$

Equivalently: There exist positive constants $c_1$, $c_2$ and $n_0$ such that:
$$
c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n) \quad \text{for all } n \geq n_0
$$
Interpretation: $f(n)$ grows at exactly the same rate as $g(n)$ (up to constant factors)

##### Little-o (o) - Strict Upper Bound
$f(n) = o(g(n))$ if there exist positive constants $c$ and $n_0$ such that:
$$
f(n) < c \cdot g(n) \quad \text{for all } n \geq n_0
$$
Interpretation: $f$ grows strictly slower than g.
Equivalently: 
$$\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$$


($g(n)$ is both upper and lower bound)


#### Common Orders of Growth

From fastest to slowest:

| Notation | Name | Example | Problem Size Growth |
|----------|------|---------|---------|
| O(1) | Constant | Array access, arithmetic operations | No change |
| O(log n) | Logarithmic | Binary search, balanced tree operations | Doubles for +1 time |
| O(n) | Linear | Linear search, traversing an array | Doubles for 2x time |
| O(n log n) | Linearithmic | Efficient sorting (MergeSort, QuickSort) | Grows slightly faster than linear |
| O(n²) | Quadratic | Simple sorting (BubbleSort, InsertionSort) | Halves for 1/4 time |
| O(n³) | Cubic | Matrix multiplication (naive) | ~1/3 for 1/9 time |
| O(2ⁿ) | Exponential | Generating all subsets, some recursive algorithms | -1 for 1/2 time |
| O(n!) | Factorial | Generating all permutations, traveling salesman (brute force) | Very rapid growth |

Comparing them, for $n=1,000,000$:
| Complexity | Operations |
|------------|-----------|
| O(1) | 1 |
| O(log n) | ~20 |
| O(n) | 1,000,000 |
| O(n log n) | ~20,000,000 |
| O(n²) | 1,000,000,000,000 |
| O(2ⁿ) | ~10^301029 (effectively infinite) |


---
## Analyzing Algorithms

#### General Analysis Rules:
1. **Sequential Statements:** Add complexities
$$
T_{total} = T_1 + T_2 + ... + T_k = O(max(T_1, T_2, ..., T_k))
$$

Example:
```cpp
statement_1;  // O(n)
statement_2;  // O(n²)
statement_3;  // O(n log n)
```
Total: $O(n)+O(n^2)+O(n log(n))=O(n^2)$

2. **Conditionals Statements:** Take the maximum of the branches
```cpp
    if (condition) {
       // O(f(n))
   } else {
       // O(g(n))
   }
```
Total: $O(max(f(n), g(n)))$

3. **Loops:** Multiply iterations by loop body complexity
```cpp
    for (int i = 0; i < n; i++) {
       // O(f(n))
   }
```
Total: $O(n \cdot f(n))$


4. **Nested loops:** Multiply complexities of all loops
```cpp
for (int i = 0; i < n; i++) {           // O(n)
       for (int j = 0; j < n; j++) {    // O(n)
           // O(1)
       }
   }
```
Total: $O(n \cdot n \cdot 1) = O(n^2)$

5. **Recursive Algorithms**: For recursive algorithms, set up and solve a recurrence relation
```cpp
int factorial(int n) {
    if (n <= 1) return 1;           // T(1) = O(1)
    return n * factorial(n-1);      // T(n) = T(n-1) + O(1)
}
```
Recurrence:
$$T(n)=T(n-1)+c$$

$$T(1)=c$$


---
## Recurrence Relations
Recurrence relations are equations that define sequences recursively. They appear naturally when analyzing recursive algorithms.

**Common Forms and Solutions**:
1. Linear Recurrence with Constant Work
$$
T(n) = T(n-1) + c
$$
Solution: $T(n) = O(n)$

2. Divide and Conquer (Split in Half)
$$
T(n) = 2T(n/2) + cn
$$
Solution: $T(n) = O(n log(n))$

3. Single Recursive Call (Half Size)
$$
T(n)=T(n/2) +c
$$
Solution: $T(n)=O(log (n))$

4. Linear Work, Smaller Problem
$$
T(n) = T(n-1) +cn
$$
Solution: $T(n)=O(n^2)$


#### Master Theorem
The Master Theorem provides a cookbook method for solving divide-and-conquer recurrences of the form:
$$
T(n) = aT(n/b) + f(n)
$$
where:
- $a \geq 1$ (number of subproblems)
- $b>1$ (factor by which problem size is reduced)
- $f(n)$ (work done outside recursive calls)



---
## Amortized Analysis

Amortized analysis provides a way to analyze the average cost per operation over a sequence of operations, even when individual operations may have varying costs.

The key idea is that some expensive operations are compensated by many cheap operations, giving a better average cost than worst-case analysis of a single operation.

As an example, let's consider a dynamic array that doubles in size when full:
```cpp
void push_back(int x) {
    if (size == capacity) {
        // Expensive: O(n) to copy all elements
        resize(capacity * 2);
    }
    arr[size++] = x;  // Cheap: O(1)
}
```
Individual Operation Analysis:
- Most insertions: $O(1)$
- Occasional resize: $O(n)$

Even though some insertions cost $O(n)$, the average cost is $O(1)$


---
## Case Study: Maximum Subsequence Sum

Let's analyze four different algorithms for this classic problem in depth.

**Problem:** Given integers $a_1, a_2, ..., a_n$ (positive and/or negative), find the highest sum of consecutive elements:
$$
max_{1 \leq i \leq j \leq n} = \sum_{k=1}^j a_k​
$$

**Examples**:
1. [-2, 11, -4, 13, -4, 2]
> Answer: 20 (11 + (-4) + 13)
2. [1, -3, 4, -2, -1, 6]
> 7 (4 + (-2) + (-1) + 6)
3. [-3, 1, -8, 4, -1, 2, 1, -5, 5]
> Answer: 6 (4 + (-1) + 2 + 1)

**Note**: If all values are negative, the answer is 0 (empty subsequence).

#### Algorithm 1: Brute Force (Cubic)

The idea is to try all possible subsequences [i, j] and compute their sums.
Implementation:
```cpp
template 
Comparable maxSubSum1(const vector& a) {
    Comparable maxSum = 0;
    
    for (int i = 0; i < a.size(); i++) {           // Start position
        for (int j = i; j < a.size(); j++) {       // End position
            Comparable thisSum = 0;
            
            for (int k = i; k <= j; k++) {         // Compute sum [i,j]
                thisSum += a[k];
            }
            
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    
    return maxSum;
}
```

Complexity Analysis:
- **Three nested loops**, each potentially running n times
- **Time**: $T(n) = O(n^3)$
- **Space**: $S(n) = O(1)$ - only uses a few variables

This is very slow for large inputs


#### Algorithm 2: Improved (Quadratic)

Note that $sum[i,j]=sum[i,j-1]+a[j]$. No need to recompute.

```cpp
template 
Comparable maxSubSum2(const vector& a) {
    Comparable maxSum = 0;
    
    for (int i = 0; i < a.size(); i++) {
        Comparable thisSum = 0;
        
        for (int j = i; j < a.size(); j++) {
            thisSum += a[j];  // Incrementally compute sum
            
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    
    return maxSum;
}
```

Complexity Analysis:
- **Two nested loops**
- **Time**: $T(n) = O(n^2)$
- **Space**: $S(n) = O(1)$

This is much better but there is still some room for improvement.

#### Algorithm 3: Linear (Kadane's Algorithm)

The key insight of this approach is that if a partial sum becomes negative, it cannot contribute to a maximum sum that includes later elements. So reset to 0.

```cpp
template 
Comparable maxSubSum3(const vector& a) {
    Comparable thisSum = 0;
    Comparable maxSum = 0;
    
    for (int j = 0; j < a.size(); j++) {
        thisSum += a[j];
        
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;  // Reset if negative
        }
    }
    
    return maxSum;
}
```

Complexity Analysis:
- **Single loop**
- **Time**: $T(n) = O(n)$
- **Space**: $S(n) = O(1)$

Optimal.

#### Algorithm 4: Divide and Conquer

The idea behind this algorithm is to divide array in half. Maximum subsequence is either:
1. Entirely in left half (solve recursive)
2. Entirely in right half (solve recursive)
3. Crosses the middle (compute directly)

```cpp
template 
Comparable maxSubSum4(const vector& a, int left, int right) {
    // Base case
    if (left == right) {
        return (a[left] > 0 ? a[left] : 0);
    }
    
    int center = (left + right) / 2;
    
    // Recursive cases
    Comparable maxLeftSum = maxSubSum4(a, left, center);
    Comparable maxRightSum = maxSubSum4(a, center + 1, right);
    
    // Find max sum crossing the middle
    Comparable maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    
    Comparable maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }
    
    // Return maximum of three cases
    return max3(maxLeftSum, maxRightSum, 
                maxLeftBorderSum + maxRightBorderSum);
}

// Helper function
template 
Comparable max3(Comparable a, Comparable b, Comparable c) {
    return max(a, max(b, c));
}

// Wrapper function
template 
Comparable maxSubSum4(const vector& a) {
    return maxSubSum4(a, 0, a.size() - 1);
}
```

Recurrence:
$$
T(n) = 2T(n/2)+O(n)
$$

The $O(n)$ comes from the two loops finding max border sums. Using Master Theorem:
- $a=2$, $b=2$, $f(n)=n$
- $c=log_22=1$
- $f(n)=n=\Theta(n^c)$
- Case 2: $T(n)= \Theta(n log(n))$

Conclusion: $T(n)=\Theta (n log(n))$
Space: $S(n)=O(log(n))$


#### Comparison of all Four Algorithms

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Algorithm 1 | O(n³) | O(1) | 
| Algorithm 2 | O(n²) | O(1) |
| Algorithm 3 | O(n) | O(1) |
| Algorithm 4 | O(n log n) | O(log n) |


---
## Practical Considerations

There are some times when Big-O does not tell the whole story.

#### Hidden Constants
Let's suppose we have two algorithms A and B where:
- Algorithm A: $T_A(n)=100n$ (Time Complexity $O(n)$)
- Algorithm B: $T_B(n)=n^2$ (Time Complexity $O(n^2)$)

Growth rate of A is smaller, so we could predict that algorithm A would be faster every time. But in reality, for $n<100$, the algorithm B is faster.

For small inputs, constants matter.
Also, some times when there are big discrepencies between best-case, average-case and worst-case scenario, the best worst-case scenario might not be the best case scenario.

#### Cache Effects

Modern processors have memory hierarchies (L1/L2/L3 cache, RAM). Algorithms that access memory sequentially (good cache locality) can be much faster than random-access algorithms, even with same Big-O.

**Example**:
```cpp
// Good cache locality (row-major order)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        sum += matrix[i][j];  // Sequential access
    }
}

// Poor cache locality (column-major in row-major storage)
for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
        sum += matrix[i][j];  // Strided access
    }
}
```

Both are $O(n^2)$, but first can be 10x faster due to cache friendly usage.


#### Choosing the Right Algorithm

Decision Factors:
1. **Input size**
2. **Input characteristics**
3. **Required guarantees**
4. **Speed constraints**
5. **Implementation complexity**


#### Profiling vs Analysis

Theoretical analysis tells us:
- Scalability to large inputs
- Theoretical limits
- Asymptotic behavior

Profiling tells you:
- Actual bottlenexks in our code
- Real-world performance
- Implementation-specific issues

