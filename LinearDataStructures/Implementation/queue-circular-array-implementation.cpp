template 
class ArrayQueue {
private:
    T* data;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;
    
public:
    ArrayQueue(int cap = 100) 
        : capacity(cap), frontIdx(0), rearIdx(0), count(0) {
        data = new T[capacity];
    }
    
    ~ArrayQueue() {
        delete[] data;
    }
    
    bool isEmpty() const {
        return count == 0;
    }
    
    bool isFull() const {
        return count == capacity;
    }
    
    int size() const {
        return count;
    }
    
    void enqueue(const T& x) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        
        data[rearIdx] = x;
        rearIdx = (rearIdx + 1) % capacity;  // Circular wrap
        count++;
    }
    
    void dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        
        frontIdx = (frontIdx + 1) % capacity;  // Circular wrap
        count--;
    }
    
    T front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return data[frontIdx];
    }
};