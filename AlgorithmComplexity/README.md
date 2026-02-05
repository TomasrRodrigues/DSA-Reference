# Algorithm Complexity 

#### Table of Contents
1. [Introduction](#introduction)
2. [Time and Space Complexity](#time-and-space-complexity)
3. [Big-O Notation](#big-o-notation)
4. [Analyzing Algorithms](#analyzing-algorithms)
5. [Case Study: Maximum Subsequence Sum](#case-study-maximum-subsequence-sum)

---
## Introduction

An algorithm is a set of precise intructions for solving a problem. The key distinction between an algorithm and a program is that an algorithm is abstract while a program is a concrete implementation.

In algorithm we must analyze:
1. Correctness: Prove the algorithm is correct
2. Efficiency: Determine resources required (time, space)

We must analyze complexity to:
- Compare different algorithms for the same problem
- Predict how resource requirements grow with input size
- Choose the most efficient algorithm for a problem

---
## Time and Space Complexity

To analyze efficiency we must analyze both the time and space complexity:
- Time Complexity ($T(n)$): Execution time as a function of input size n
- Space Complexity ($S(n)$): Memory space required as a function of input size n

For that we analyze three "types" of cases - The Best, the Average and the worst cases:

| Case | Description | Usefulness |
|--|----|---|
| Best Case | Minimum time/space needed | Not very useful (optimistic) |
| Average Case | Expected time/space on typical inputs | Very useful |
| Worst Case | Maximum time/space needed | Very useful (guarantees) |


---
## Big-O Notation

To analyze complexity we usually do an asymptotic analysis. This means that we focus on growth rate rather than exact values:
- For large inputs, dominant terms matter most
- Constant coefficients become less significant
- We want to know how the algorithm scales

Only the dominant term is used because it is the one that determines the behavior. Let's suppose we have a function $f(n)= n^3 + 350n^2 + n$. For $n=10,000$, the real value is $=1,000,350,010,000$ and the estimated (using $n^3$) is $=1,000,000,000,000$. The error is only $0,35%. This error diminishes even more with bigger inputs.

#### Big-O Definition

$f(n) = O(g(n))$ if there exist positive constants $c$ and $n_0$ such that:

$$
f(n) \leq c \cdot g(n) \quad \text{for all } n > n_0
$$

This means that $g(n)$ is an upper bound on the growth of $f(n)$ for large n.

Important properties:
1. If $f(n) = O(n^2)$, it is also $O(n^3)$ (but we want the tightest bound)
2. Polynomial complexity: $c_k \cdot n^k + c_{k-1} \cdot n^{k-1} + ... + c_1 \cdot n + c_0 = O(n^k)$
3. Logarithmic base doesn't matter: $log_2(n) = O(log (n))$
4. Constants: $4 = O(1)$

#### Other Asymptotic Notations

##### Big-Omega (Ω) - Lower Bound
$f(n) = Ω(g(n))$ if there exists positive constants $c$ and $n_0$, such that:
$$
f(n) \geq c \cdot g(n) \quad \text{for all } n \geq n_0
$$

##### Big-Theta (Θ) - Tight Bound
$f(n) = Θ(g(n))$ if:
$$
f(n) = O(g(n)) \quad \text{and} \quad f(n) = Ω(g(n))
$$

##### Little-o (o) - Strict Upper Bound
$f(n) = o(g(n))$ if there exist positive constants $c$ and $n_0$ such that:
$$
f(n) < c \cdot g(n) \quad \text{for all } n \geq n_0
$$

($g(n)$ is both upper and lower bound)


#### Common Orders of Growth

From fastest to slowest:

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Array access, arithmetic operations |
| O(log n) | Logarithmic | Binary search, balanced tree operations |
| O(n) | Linear | Linear search, traversing an array |
| O(n log n) | Linearithmic | Efficient sorting (MergeSort, QuickSort) |
| O(n²) | Quadratic | Simple sorting (BubbleSort, InsertionSort) |
| O(n³) | Cubic | Matrix multiplication (naive) |
| O(2ⁿ) | Exponential | Generating all subsets, some recursive algorithms |
| O(n!) | Factorial | Generating all permutations, traveling salesman (brute force) |

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

Rules for Analysis:
1. **Sequential statements:** Add complexities
```cpp
S1; S2; S3;
```
$\rightarrow T(n) = T(S1) + T(S2) + T(S3)$

2. **Conditionals:** Take maximum
```cpp
    if (condition) {
       S1;  // O(f(n))
   } else {
       S2;  // O(g(n))
   }
```

$\rightarrow T(n) = max(O(f(n)), O(g(n)))$

3. **Loops:** Multiply iterations by body complexity
```cpp
    for (int i = 0; i < n; i++) {
       S;  // O(f(n))
   }
```
$\rightarrow T(n) = n \cdot O(f(n))$

4. **Nested loops:** Multiply complexities
```cpp
for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           S;  // O(1)
       }
   }
```
$\rightarrow T(n) = O(n \cdot n \cdot 1) = O(n^2)$

---
## Case Study: Maximum Subsequence Sum

**Problem:** Given integers $a_1, a_2, ..., a_n$ (positive and/or negative), find the highest sum of consecutive elements.

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

We don't need the inner k loop. We can compute `sum[i,j]` from `sum[i,j-1]`.

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

If a subsequence [i, j] has negative sum, then [i, q] (where q>j) cannot be the maximum.

The key idea here is to:
- Scan the array from left to right 
- Keep running sum
- If running sum becomes negative, reset to 0
- Track maximum sum seen

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
1. Entirely in left half (recursive)
2. Entirely in right half (recursive)
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

Comparison of all Four Algorithms

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Algorithm 1 | O(n³) | O(1) | 
| Algorithm 2 | O(n²) | O(1) |
| Algorithm 3 | O(n) | O(1) |
| Algorithm 4 | O(n log n) | O(log n) |
