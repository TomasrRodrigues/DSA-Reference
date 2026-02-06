void DFS(int v, std::vector<bool>& visited, 
         const std::vector<std::vector<int>>& adj) {
    visited[v] = true;
    std::cout << v << " ";
    
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adj);
        }
    }
}

void DFSGraph(const std::vector<std::vector<int>>& adj) {
    int V = adj.size();
    std::vector<bool> visited(V, false);
    
    // Handle disconnected graph
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            DFS(v, visited, adj);
        }
    }
}



void DFSIterative(int start, const std::vector<std::vector<int>>& adj) {
    int V = adj.size();
    std::vector<bool> visited(V, false);
    std::stack<int> stack;
    
    stack.push(start);
    
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        
        if (visited[v]) continue;
        
        visited[v] = true;
        std::cout << v << " ";
        
        // Push neighbors (reverse order for same order as recursive)
        for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
            if (!visited[*it]) {
                stack.push(*it);
            }
        }
    }
}




bool hasPath(int src, int dest, const std::vector<std::vector<int>>& adj) {
    if (src == dest) return true;
    
    int V = adj.size();
    std::vector<bool> visited(V, false);
    
    return hasPathDFS(src, dest, visited, adj);
}

bool hasPathDFS(int current, int dest, std::vector<bool>& visited,
                const std::vector<std::vector<int>>& adj) {
    visited[current] = true;
    
    if (current == dest) return true;
    
    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (hasPathDFS(neighbor, dest, visited, adj)) {
                return true;
            }
        }
    }
    
    return false;
}




void findAllPathsDFS(int current, int dest, 
                     std::vector<int>& path,
                     std::vector<bool>& visited,
                     std::vector<std::vector<int>>& allPaths,
                     const std::vector<std::vector<int>>& adj) {
    path.push_back(current);
    visited[current] = true;
    
    if (current == dest) {
        allPaths.push_back(path);
    } else {
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                findAllPathsDFS(neighbor, dest, path, visited, 
                               allPaths, adj);
            }
        }
    }
    
    // Backtrack
    path.pop_back();
    visited[current] = false;
}