template <typename T>
void maxHeapify(std::vector<T>& v, int i, int heapSize) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // Check if left child is larger
    if (left < heapSize && v[left] > v[largest]) {
        largest = left;
    }
    
    // Check if right child is larger
    if (right < heapSize && v[right] > v[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        std::swap(v[i], v[largest]);
        
        // Recursively heapify affected subtree
        maxHeapify(v, largest, heapSize);
    }
}

template <typename T>
void buildMaxHeap(std::vector<T>& v) {
    int n = v.size();
    
    // Start from last non-leaf node and heapify each
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(v, i, n);
    }
}

template <typename T>
void heapSort(std::vector<T>& v) {
    int n = v.size();
    
    // Build max heap
    buildMaxHeap(v);
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(v[0], v[i]);
        
        // Heapify reduced heap
        maxHeapify(v, 0, i);
    }
}