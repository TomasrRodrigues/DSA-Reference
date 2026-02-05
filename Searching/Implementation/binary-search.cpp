template <typename T>
int binarySearch(const std::vector<T>& v, const T& target) {
    int left = 0;
    int right = v.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (v[mid] == target) {
            return mid;  // Found
        } else if (v[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Not found
}



template <typename T>
int binarySearchRecursive(const std::vector<T>& v, const T& target, 
                          int left, int right) {
    if (left > right) {
        return -1;  // Not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (v[mid] == target) {
        return mid;  // Found
    } else if (v[mid] < target) {
        return binarySearchRecursive(v, target, mid + 1, right);
    } else {
        return binarySearchRecursive(v, target, left, mid - 1);
    }
}

// Wrapper function
template <typename T>
int binarySearch(const std::vector<T>& v, const T& target) {
    return binarySearchRecursive(v, target, 0, v.size() - 1);
}


template <typename T>
int binarySearchFirst(const std::vector<T>& v, const T& target) {
    int left = 0, right = v.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (v[mid] == target) {
            result = mid;      // Potential answer
            right = mid - 1;   // Keep searching left
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}



template <typename T>
int binarySearchLast(const std::vector<T>& v, const T& target) {
    int left = 0, right = v.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (v[mid] == target) {
            result = mid;      // Potential answer
            left = mid + 1;    // Keep searching right
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}


template <typename T>
int countOccurrences(const std::vector<T>& v, const T& target) {
    int first = binarySearchFirst(v, target);
    
    if (first == -1) {
        return 0;  // Not found
    }
    
    int last = binarySearchLast(v, target);
    return last - first + 1;
}


template <typename T>
int lowerBound(const std::vector<T>& v, const T& target) {
    int left = 0, right = v.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

template <typename T>
int upperBound(const std::vector<T>& v, const T& target) {
    int left = 0, right = v.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (v[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}