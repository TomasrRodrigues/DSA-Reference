template <typename T>
void selectionSort(std::vector<T>& v) {
    int n = v.size();
    
    // Outer loop: position to fill
    for (int i = 0; i < n - 1; i++) {
        // Find minimum in unsorted part
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;  // Update minimum index
            }
        }
        
        // Swap minimum with current position
        if (minIndex != i) {
            std::swap(v[i], v[minIndex]);
        }
    }
}