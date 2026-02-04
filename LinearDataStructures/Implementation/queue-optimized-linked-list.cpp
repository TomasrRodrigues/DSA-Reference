template 
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* frontPtr;
    Node* rearPtr;
    int count;
    
public:
    LinkedQueue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}
    
    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    bool isEmpty() const {
        return frontPtr == nullptr;
    }
    
    int size() const {
        return count;
    }
    
    void enqueue(const T& x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        count++;
    }
    
    void dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        
        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
        
        delete temp;
        count--;
    }
    
    T front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return frontPtr->data;
    }
};