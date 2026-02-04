template 
class VList {
private:
    Object* elements;  // Dynamic array
    int used;         // Number of elements
    int capacity;     // Array size
    
    friend class VListItr;
    
public:
    VList(int size = 100) : used(0), capacity(size) {
        elements = new Object[capacity];
    }
    
    ~VList() {
        delete[] elements;
    }
    
    bool isEmpty() const {
        return used == 0;
    }
    
    void makeEmpty() {
        used = 0;
    }
    
    void insert(const Object& x, int pos) {
        if (used == capacity) {
            resize();  // Double capacity
        }
        
        // Shift elements right
        for (int i = used; i > pos; i--) {
            elements[i] = elements[i-1];
        }
        
        elements[pos] = x;
        used++;
    }
    
    void remove(const Object& x) {
        int pos = find(x);
        if (pos == -1) return;
        
        // Shift elements left
        for (int i = pos; i < used - 1; i++) {
            elements[i] = elements[i+1];
        }
        used--;
    }
    
    int find(const Object& x) const {
        for (int i = 0; i < used; i++) {
            if (elements[i] == x) return i;
        }
        return -1;
    }
    
private:
    void resize() {
        capacity *= 2;
        Object* newElements = new Object[capacity];
        
        for (int i = 0; i < used; i++) {
            newElements[i] = elements[i];
        }
        
        delete[] elements;
        elements = newElements;
    }
};