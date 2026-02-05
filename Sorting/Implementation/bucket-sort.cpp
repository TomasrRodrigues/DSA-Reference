void bucketSort(std::vector<float>& v) {
    int n = v.size();
    if (n <= 1) return;
    
    // Create n empty buckets
    std::vector<std::vector<float>> buckets(n);
    
    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * v[i];  // Assumes v[i] in [0, 1)
        buckets[bucketIndex].push_back(v[i]);
    }
    
    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    
    // Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            v[index++] = value;
        }
    }
}