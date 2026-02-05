template <typename T>
void insertionSort(std::vector<T>& v) {
    int n = v.size();
    
    // Start from second element (first is already "sorted")
    for (int i = 1; i < n; i++) {
        T key = v[i];  // Element to insert
        int j = i - 1;
        
        // Move elements greater than key one position right
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];  // Shift right
            j--;
        }
        
        // Insert key at correct position
        v[j + 1] = key;
    }
}