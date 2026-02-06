struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

class WeightedGraph {
private:
    std::vector<std::vector<Edge>> adj;
    int V;
    
public:
    WeightedGraph(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }
    
    const std::vector<Edge>& getNeighbors(int u) const {
        return adj[u];
    }
};