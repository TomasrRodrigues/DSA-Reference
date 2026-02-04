template 
class LStack {
private:
    LList list;  // Use our linked list
    
public:
    bool isEmpty() const {
        return list.isEmpty();
    }
    
    void push(const T& x) {
        list.insert(x, 0);  // Insert at beginning
    }
    
    T top() const {
        if (isEmpty()) {
            throw NoElement();
        }
        return list.first().retrieve();
    }
    
    void pop() {
        if (isEmpty()) {
            throw NoElement();
        }
        list.remove(top());
    }
};