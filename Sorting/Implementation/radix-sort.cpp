void countingSortByDigit(std::vector<int>& v, int exp) {
    int n = v.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);  // Digits 0-9
    
    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (v[i] / exp) % 10;
        count[digit]++;
    }
    
    // Cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output
    for (int i = n - 1; i >= 0; i--) {
        int digit = (v[i] / exp) % 10;
        output[count[digit] - 1] = v[i];
        count[digit]--;
    }
    
    // Copy to original
    v = output;
}

void radixSort(std::vector<int>& v) {
    if (v.empty()) return;
    
    // Find maximum to know number of digits
    int maxVal = *std::max_element(v.begin(), v.end());
    
    // Sort for each digit position
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(v, exp);
    }
}