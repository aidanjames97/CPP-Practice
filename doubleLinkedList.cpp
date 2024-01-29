struct Node {
    // define struct variables
    int data;
    Node* prev;
    Node* next;
    // constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the structure for a double linked list
// data is of type int
// prev points behind, next points in front
class DoubleLinkedLink {
    private:
        Node * head; // private var pointing to head (start) of double linked list
    public:
        DoubleLinkedLink() : head(nullptr) {}

        // insert new node at beginning of list
        void insertAtBeginning(int value) {

        }

        // insert new node after specified node
        bool insertAfter(int refr, int value) {

        }

        // insert new node before specified node
        bool insertBefore(int refr, int value) {
            
        }

        // destructor to free memory used by list
};