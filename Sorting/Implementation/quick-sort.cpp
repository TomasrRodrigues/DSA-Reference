template <typename T>
int partition(std::vector<T>& v, int low, int high) {
    T pivot = v[high];  // Choose last element as pivot
    int i = low - 1;    // Index of smaller element
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than pivot
        if (v[j] < pivot) {
            i++;  // Increment index of smaller element
            std::swap(v[i], v[j]);
        }
    }
    
    // Place pivot in correct position
    std::swap(v[i + 1], v[high]);
    return i + 1;  // Return pivot index
}

template <typename T>
void quickSortHelper(std::vector<T>& v, int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(v, low, high);
        
        // Recursively sort elements before and after partition
        quickSortHelper(v, low, pi - 1);
        quickSortHelper(v, pi + 1, high);
    }
}

template <typename T>
void quickSort(std::vector<T>& v) {
    quickSortHelper(v, 0, v.size() - 1);
}




template <typename T>
int hoarePartition(std::vector<T>& v, int low, int high) {
    T pivot = v[low];  // Choose first element
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        // Find element >= pivot from left
        do {
            i++;
        } while (v[i] < pivot);
        
        // Find element <= pivot from right
        do {
            j--;
        } while (v[j] > pivot);
        
        if (i >= j) {
            return j;  // Return partition point
        }
        
        std::swap(v[i], v[j]);
    }
}

template <typename T>
void quickSortHoare(std::vector<T>& v, int low, int high) {
    if (low < high) {
        int pi = hoarePartition(v, low, high);
        
        quickSortHoare(v, low, pi);      // Note: pi, not pi-1
        quickSortHoare(v, pi + 1, high);
    }
}