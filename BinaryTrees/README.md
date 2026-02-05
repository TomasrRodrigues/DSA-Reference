# Binary Trees

#### Table of Contents
1. [Introduction](#introduction)
2. [Tree Terminology](#tree-terminology)
3. [Binary Trees](#binary-trees)
4. [Binary Search Trees (BST)](#binary-search-tree-bst)

---
## Introduction

A tree is a hierarchical data structure consisting of:
- A set of nodes (vertices)
- A set of edges connecting pairs of nodes

Visually, a tree looks like this:
```
         A          ← Root
       / | \
      B  C  D       ← Children of A
     /|    |\
    E F    G H      ← Leaves (no children)
```

Tree Properties:
1. One node is designated as the root
2. Every node (except root) has exactly one parent
3. Each node may have zero or more children
4. There is a unique path from root to each node
5. A tree with n nodes has exactly n-1 edges

Trees are useful when the data has a hierarchical representation, needs efficient search, insert and delete, want to maintain sorted data efficiently and when we want to represent file systems, organizational charts or expression parsing.

---
## Tree Terminology

**Node**: A basic unit containing:
- Data/Element: The value stored
- Links/Pointers: References to children

**Root**:
- The topmost node in the tree
- Has no parent
- Only one root per tree

**Parent**:
- A node that has children
- Every node except root has exactly one parent

**Child**: 
- A node that has a parent
- Can be child of only one parent

**Siblings**: Nodes with the same parent

**Leaf**:
- A node with no children
- Also called terminal nodes

**Internal Node**:
- A node with at least one child
- Not a leaf

**Path**:
- Sequence of nodes connected by edges
- From node u to node v

**Path Length**: Number of edges in the path

**Ancestor**: Node u is ancestor of v if there's a path from u to v

**Descendant**: Node v is descendant of u if u is ancestor of v

**Depth of a Node**: Length of a path from root to that node
- Depth of root = 0
- $depth_node = 1 + depth_parent$

**Height of a Node**: Length of longest path from that node to a leaf. Height of leaf = 0
- $height_node = 1 + max(height_children)$

**Height of Tree**:
- Height of the root
- Maximum depth of any node

**Size of a Node**:
- Number of descendants including itself

**Degree**:
- Number of children of a node

**Subtree**:
- A tree formed by a node and all its descendants

---
## Binary Trees
A binary tree is a tree where each node has at most two children:
- Left child
- Right child

#### Binary Tree Properties
For a binary tree with n nodes and height h:
- Minimum Number of Nodes: $h+1$ nodes
- Maximum Number of Nodes: $2^{h+1}-1$
- Minimum Height: $|log_2(n+1)|$
- Maximum Height: $n-1$ for n nodes 
- Number of Leaves:
    - In a full binary tree: $leaves= [n/2]$
    - In a perfect binary tree of height h: $leaves = 2^h$

#### Types of Binary Trees
1. **Full Binary Tree**: Every node has either 0 or 2 children (never 1)
2. **Complete Binary Tree**: All levels are compeltely filled except possibly the lasat, which is filled from left to right
3. **Perfect Binary Tree**: All internal nodes have 2 children and all leaves are at same level. Properties:
    - Number of nodes $= 2^{h+1} - 1$
    - Number of leaves $= 2^h$
    - Number of internal nodes $= 2^h - 1$
4. **Balanced Binary Tree**: For each node, heights of left and right subtrees differ by at most 1
5. **Degenerate (Skewed) Tree**: Each parent has only one child (essentially a lnked list). Properties:
    - Height $= n - 1$
    - Performance degrades to $O(n)$

[Implementation of Binary Tree](/BinaryTrees/Implementation/binary-tree.cpp)


---
## Tree Traversals

Tree traversal means visiting each node exactly once in a specific order. Types of Traversals:
#### Depth-First Traversals
Depth-First Traversal mechanisms work by using recursion and stack

##### Preorder Traversal
Visit root, then left subtree, then right subtree. The pseudo-algorithm looks like this:
```
preorder(node):
    if node is null:
        return
    visit(node)           // Process root
    preorder(node.left)   // Traverse left
    preorder(node.right)  // Traverse right
```

#### Inorder Traversal
Visit left subtree, then root, then right subtree. The pseudo-algorithm looks like this:
```
inorder(node):
    if node is null:
        return
    inorder(node.left)    // Traverse left
    visit(node)           // Process root
    inorder(node.right)   // Traverse right
```

#### Postorder Traversal (Left-Right-Root)
Visit left subtree, then right subtree, then root. The pseudo-algorithm looks like this:
```
postorder(node):
    if node is null:
        return
    postorder(node.left)   // Traverse left
    postorder(node.right)  // Traverse right
    visit(node)            // Process root
```

#### Breadth-First Traversal (using queue)
Visit nodes level by level, left to right. The pseudo algorithm looks like this:
```
levelorder(root):
    if root is null:
        return
    queue Q
    Q.enqueue(root)
    
    while Q is not empty:
        node = Q.dequeue()
        visit(node)
        
        if node.left exists:
            Q.enqueue(node.left)
        if node.right exists:
            Q.enqueue(node.right)
```


---
## Binary Search Tree (BST)
A binary Search Tree is a binary tree with the BST property: For every node X
- All values in left subtree $<X$
- All values in right subtree $>X$

BSTs enable efficient operations:
- **Search**: $O(log (n))$ average, $O(n)$ worst
- **Insert**: $O(log (n))$ average, $O(n)$ worst
- **Delete**: $O(log (n))$ average, $O(n)$ worst
- Inorder traversal gives sorted order


#### BST Operations

##### 1. Search
Search works by comparing the goal value with the root:
- If smaller, go left
- If larger, go right

```
search(node, key):
    if node is null:
        return null  // Not found
    
    if key == node.element:
        return node  // Found
    else if key < node.element:
        return search(node.left, key)
    else:
        return search(node.right, key)
```

##### 2. Find Minimum/Maximum
Works by going as far left as possible for minimum value and by going as far right as possible.


##### 3. Insert
The algorithm works by searching for position and insert the value as leaf.
```
insert(node, key):
    if node is null:
        return new Node(key)  // Insert here
    
    if key < node.element:
        node.left = insert(node.left, key)
    else if key > node.element:
        node.right = insert(node.right, key)
    // else: duplicate, do nothing
    
    return node
```


##### 4. Delete

There are three cases:
- Case 1 - Node is a leaf (no children): Simply delete it
- Case 2 - Node has one child: Replace node with its child
- Case 3 - Node has two children:
    - Find successor (smallest in right subtree) or predecessor (largest in left subtree)
    - Replace node's value with successor's value
    - Delete successor


# TODO: FINISG UNBALANCED BST

