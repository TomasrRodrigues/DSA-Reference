#include <queue>

// Simple Binary Tree Node
template <typename T>
struct BTNode {
    T element;           // Data stored in node
    BTNode* left;        // Pointer to left child
    BTNode* right;       // Pointer to right child
    
    // Constructor
    BTNode(const T& el, BTNode* l = nullptr, BTNode* r = nullptr)
        : element(el), left(l), right(r) {}
};


template <typename T>
class BinaryTree {
private:
    BTNode<T>* root;
    
    // Helper functions for recursion
    void destroyTree(BTNode<T>* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    
    BTNode<T>* copyTree(BTNode<T>* node) {
        if (node == nullptr) {
            return nullptr;
        }
        return new BTNode<T>(
            node->element,
            copyTree(node->left),
            copyTree(node->right)
        );
    }
    
    int getHeight(BTNode<T>* node) const {
        if (node == nullptr) {
            return -1;  // Height of empty tree is -1
        }
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
    
    int getSize(BTNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + getSize(node->left) + getSize(node->right);
    }
    
public:
    // Constructor
    BinaryTree() : root(nullptr) {}
    
    // Constructor with root element
    BinaryTree(const T& el) {
        root = new BTNode<T>(el);
    }
    
    // Constructor with root and subtrees
    BinaryTree(const T& el, const BinaryTree& left, const BinaryTree& right) {
        root = new BTNode<T>(el, copyTree(left.root), copyTree(right.root));
    }
    
    // Copy constructor
    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root);
    }
    
    // Destructor
    ~BinaryTree() {
        destroyTree(root);
    }
    
    // Assignment operator
    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            destroyTree(root);
            root = copyTree(other.root);
        }
        return *this;
    }
    
    // Check if empty
    bool isEmpty() const {
        return root == nullptr;
    }
    
    // Get root element
    T& getRoot() const {
        if (isEmpty()) {
            throw std::runtime_error("Tree is empty");
        }
        return root->element;
    }
    
    // Get height
    int height() const {
        return getHeight(root);
    }
    
    // Get size (number of nodes)
    int size() const {
        return getSize(root);
    }
    
    // Make tree empty
    void makeEmpty() {
        destroyTree(root);
        root = nullptr;
    }

    
    //Pre-Order Traversal
    template <typename T>
    void preOrderHelper(BTNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        
        std::cout << node->element << " ";  // Visit root
        preOrderHelper(node->left);          // Left subtree
        preOrderHelper(node->right);         // Right subtree
    }

    template <typename T>
    void BinaryTree<T>::preOrder() const {
        preOrderHelper(root);
        std::cout << std::endl;
    }
    template <typename T>


    //In-Order Traversal
    void inOrderHelper(BTNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        
        inOrderHelper(node->left);           // Left subtree
        std::cout << node->element << " ";   // Visit root
        inOrderHelper(node->right);          // Right subtree
    }

    template <typename T>
    void BinaryTree<T>::inOrder() const {
        inOrderHelper(root);
        std::cout << std::endl;
    }


    // Post-Order Traversal
    template <typename T>
    void postOrderHelper(BTNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        
        postOrderHelper(node->left);         // Left subtree
        postOrderHelper(node->right);        // Right subtree
        std::cout << node->element << " ";   // Visit root
    }

    template <typename T>
    void BinaryTree<T>::postOrder() const {
        postOrderHelper(root);
        std::cout << std::endl;
    }


    // Level-Order Traversal    
    template <typename T>
    void BinaryTree<T>::levelOrder() const {
        if (root == nullptr) {
            return;
        }
        
        std::queue<BTNode<T>*> q;
        q.push(root);
        
        while (!q.empty()) {
            BTNode<T>* current = q.front();
            q.pop();
            
            std::cout << current->element << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        
        std::cout << std::endl;
    }


    template <typename Comparable>
    BTNode<Comparable>* find(const Comparable& x, BTNode<Comparable>* node) const {
        if (node == nullptr) {
            return nullptr;  // Not found
        }
        
        if (x < node->element) {
            return find(x, node->left);   // Search left
        } else if (node->element < x) {
            return find(x, node->right);  // Search right
        } else {
            return node;  // Found (x == node->element)
        }
    }


    template <typename Comparable>
    BTNode<Comparable>* findMin(BTNode<Comparable>* node) const {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (node->left == nullptr) {
            return node;  // Found minimum
        }
        
        return findMin(node->left);
    }

    template <typename Comparable>
    BTNode<Comparable>* findMax(BTNode<Comparable>* node) const {
        if (node != nullptr) {
            while (node->right != nullptr) {
                node = node->right;
            }
        }
        return node;
    }


    template <typename Comparable>
    bool insert(const Comparable& x, BTNode<Comparable>*& node) {
        if (node == nullptr) {
            node = new BTNode<Comparable>(x, nullptr, nullptr);
            return true;
        }
        
        if (x < node->element) {
            return insert(x, node->left);
        } else if (node->element < x) {
            return insert(x, node->right);
        } else {
            return false;  // Duplicate, don't insert
        }
    }


    template <typename Comparable>
    bool remove(const Comparable& x, BTNode<Comparable>*& node) {
        if (node == nullptr) {
            return false;  // Not found
        }
        
        if (x < node->element) {
            return remove(x, node->left);
        } else if (node->element < x) {
            return remove(x, node->right);
        } else {
            // Found the node to delete
            
            // Case 1 & 2: Node has 0 or 1 child
            if (node->left == nullptr || node->right == nullptr) {
                BTNode<Comparable>* oldNode = node;
                node = (node->left != nullptr) ? node->left : node->right;
                delete oldNode;
                return true;
            }
            
            // Case 3: Node has 2 children
            // Find successor (minimum in right subtree)
            BTNode<Comparable>* successor = findMin(node->right);
            node->element = successor->element;  // Replace value
            return remove(successor->element, node->right);  // Delete successor
        }
    }
};