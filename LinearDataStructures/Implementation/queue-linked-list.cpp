template 
class LQueue {
private:
    LList list;
    
public:
    bool isEmpty() const {
        return list.isEmpty();
    }
    
    void enqueue(const T& x) {
        list.insert(x, list.size());  // Insert at end
    }
    
    T front() const {
        if (isEmpty()) {
            throw NoElement();
        }
        return list.first().retrieve();
    }
    
    void dequeue() {
        if (isEmpty()) {
            throw NoElement();
        }
        list.remove(front());
    }
};