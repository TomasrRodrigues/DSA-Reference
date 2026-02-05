void countingSort(std::vector<int>& v) {
    if (v.empty()) return;
    
    // Find range
    int maxVal = *std::max_element(v.begin(), v.end());
    int minVal = *std::min_element(v.begin(), v.end());
    int range = maxVal - minVal + 1;
    
    // Count array
    std::vector<int> count(range, 0);
    std::vector<int> output(v.size());
    
    // Count occurrences
    for (int num : v) {
        count[num - minVal]++;
    }
    
    // Cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output (backwards for stability)
    for (int i = v.size() - 1; i >= 0; i--) {
        output[count[v[i] - minVal] - 1] = v[i];
        count[v[i] - minVal]--;
    }
    
    // Copy to original
    v = output;
}