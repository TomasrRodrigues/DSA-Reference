template <typename T>
void merge(std::vector<T>& v, int left, int mid, int right) {
    // Create temporary arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }
    
    // Merge temp arrays back
    int i = 0;    // Initial index of L
    int j = 0;    // Initial index of R
    int k = left; // Initial index of merged array
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {  // Use <= for stability!
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L, if any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R, if any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSortHelper(std::vector<T>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        // Sort left half
        mergeSortHelper(v, left, mid);
        
        // Sort right half
        mergeSortHelper(v, mid + 1, right);
        
        // Merge sorted halves
        merge(v, left, mid, right);
    }
}

template <typename T>
void mergeSort(std::vector<T>& v) {
    mergeSortHelper(v, 0, v.size() - 1);
}