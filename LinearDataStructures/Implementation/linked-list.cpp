template 
class LListNode {
private:
    Object element;
    LListNode* next;
    
    LListNode(const Object& el = Object(), LListNode* n = nullptr)
        : element(el), next(n) {}
    
    friend class LList;
    friend class LListItr;
};



template 
class LList {
private:
    LListNode* header;  // Dummy node
    
public:
    LList() {
        header = new LListNode();  // Create header
    }
    
    ~LList() {
        makeEmpty();
        delete header;
    }
    
    bool isEmpty() const {
        return header->next == nullptr;
    }
    
    void makeEmpty() {
        while (!isEmpty()) {
            remove(first().retrieve());
        }
    }
    
    LListItr first() const {
        return LListItr(header->next);
    }
    
    void insert(const Object& x, const LListItr& p) {
        if (p.current != nullptr) {
            p.current->next = new LListNode(x, p.current->next);
        }
    }
    
    void insert(const Object& x, int pos = 0) {
        LListNode* current = header;
        
        for (int i = 0; i < pos && current != nullptr; i++) {
            current = current->next;
        }
        
        if (current != nullptr) {
            current->next = new LListNode(x, current->next);
        }
    }
    
    LListItr find(const Object& x) const {
        LListNode* current = header->next;
        
        while (current != nullptr && current->element != x) {
            current = current->next;
        }
        
        return LListItr(current);
    }
    
    void remove(const Object& x) {
        LListNode* current = header;
        
        while (current->next != nullptr) {
            if (current->next->element == x) {
                LListNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
                return;
            }
            current = current->next;
        }
    }
};


template 
class LListItr {
private:
    LListNode* current;
    
    LListItr(LListNode* node) : current(node) {}
    
    friend class LList;
    
public:
    LListItr() : current(nullptr) {}
    
    bool isPastEnd() const {
        return current == nullptr;
    }
    
    void advance() {
        if (!isPastEnd()) {
            current = current->next;
        }
    }
    
    const Object& retrieve() const {
        if (isPastEnd()) {
            throw BadIterator();
        }
        return current->element;
    }
};