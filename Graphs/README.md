# Graphs

#### Table of Contents
1. [Introduction](#introduction)
2. [Graph Traversal](#graph-traversals)
    1. [Depth-First Search (DFS)](#depth-first-search-dfs)
    2. [Breadth-First Search (BFS)]



---
## Introduction

A graph $G=(V,E)$ consists of:
- $V$: Set of vertices (nodes)
- $E$: Set of edges (connections between vertices)

Graphs model relationships and networks. This works perfectly with Social Networks, Road Networks, Web Pages, Computer Networks, Dependencies and State Transitions.

### Graphs Terminology

#### Basic Terms

**Vertex (Node)**: Basic Unit

**Edge**: Connection between two vertices

**Adjacent**: Two vertices connected by an edge are said to be adjacent

**Degree**: Number of edges connected to a vertex

#### Paths and Connectivity

**Path**: Sequence of vertices where each adjacent pair is connected by an edge

**Simple Path**: No repeated vertices

**Cycle**: Path that starts and ends at same vertex

**Acyclic**: Graph with no cycles

**Connected**: There exists a path between any two vertices

**Connected component**: Maximal connected subgraph


#### Directed vs Undirected

**Undirected Graph**: Edges have no direction

**Directed Graph (Digraph)**: Edges gave direction

**In-degree**: Number of incoming edges

**Out-degree**: Number of outgoing edges



### Graph Representations

#### Adjacency Matrix

Representing a graph works by maintaining a 2D array where $matrix[i][j]=1$ if edge exists and 0 otherwise. For weighted graphs instead of 1 we store the weight.

This is very efficient for lookups ($O(1)$ complexity) and easy to implement but occupies a lot of space ($O(V^2)$) and takes a lot of time to find all neighbors. This is good for dense graphs but bad for sparse graphs.

#### Adjacency List

This works by representing a graph by maintaining a array of lists where $list[i]$ contains neighbors of vertex $i$. 

This solution occupies less space ($O(V+E)$) and is fast to get all the neighbors ($O(n)$). This is efficient for sparse graphs. On the other hand, edge lookup is more complex.


As a rule of thumb:
- **Dense Graphs** ($E \approx V^2$): Use Matrix
- **Sparse Graphs** ($E << V^2$): Use List


### Types of Graphs

#### Directed Acyclic Graph (DAG)
No cycles, has topological ordering. USeful for Task scheduling and building systems.

#### Tree
Connected acyclic undirected graph. Properties:
- $V$ vertices, $V-1$ edges
- Unique path between any two vertices
- Adding any edge creates a cycle

#### Bipartite Graph
Vertices can be divided into two sets where all edges go between sets.

#### Complete Graph
Every pair of vertices connected.

#### Weighted vs Unweighted
**Weighted**: Edges have associated costs/weights
**Unweighted**: All edges equal (or $weight=1$)


---
## Graph Traversals

### Depth-First Search (DFS)
