template <typename T>
int sequentialSearch(const std::vector<T>& v, const T& target) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

template <typename T>
int sequentialSearchLast(const std::vector<T>& v, const T& target) {
    for (int i = v.size() - 1; i >= 0; i--) {  // Search backwards
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}