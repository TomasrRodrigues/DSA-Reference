class GraphMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int V;  // Number of vertices
    
public:
    GraphMatrix(int vertices) : V(vertices) {
        matrix.resize(V, std::vector<int>(V, 0));
    }
    
    void addEdge(int u, int v, int weight = 1) {
        matrix[u][v] = weight;
        matrix[v][u] = weight;  // Undirected
    }
    
    bool hasEdge(int u, int v) const {
        return matrix[u][v] != 0;
    }
    
    int getWeight(int u, int v) const {
        return matrix[u][v];
    }
    
    std::vector<int> getNeighbors(int u) const {
        std::vector<int> neighbors;
        for (int v = 0; v < V; v++) {
            if (matrix[u][v] != 0) {
                neighbors.push_back(v);
            }
        }
        return neighbors;
    }
};