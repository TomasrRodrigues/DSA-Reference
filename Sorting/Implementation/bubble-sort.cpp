template <typename T>
void bubbleSort(std::vector<T>& v) {
    int n = v.size();
    
    // Outer loop: number of passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: bubble up largest element
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}


template <typename T>
void bubbleSortOptimized(std::vector<T>& v) {
    int n = v.size();
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;  // Track if any swap happened
        
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                swapped = true;  // Swap occurred
            }
        }
        
        // If no swaps, array is sorted!
        if (!swapped) {
            break;
        }
    }
}


