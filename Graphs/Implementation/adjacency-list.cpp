class GraphList {
private:
    std::vector<std::vector<int>> adj;
    int V;
    
public:
    GraphList(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected
    }
    
    const std::vector<int>& getNeighbors(int u) const {
        return adj[u];
    }
    
    bool hasEdge(int u, int v) const {
        return std::find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }
};