#include <iostream>

// Define the structure for a double linked list
// data is of type int
// prev points behind, next points in front
struct Node {
    // define struct variables
    int data;
    Node* prev;
    Node* next;
    // constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedLink {
    private:
        Node * head; // private var pointing to head (start) of double linked list
    public:
        DoubleLinkedLink() : head(nullptr) {}

        // insert new node at beginning of list
        void insertAtBeginning(int value) {
            Node* newNode = new Node(value); // init new node
            newNode->prev = nullptr; // set prev to null
            newNode->next = head; // set next to head
            head = newNode; // set head to new node
        }

        // insert new node after specified node
        bool insertAfter(int refr, int value) {
            Node* curr = head;
            Node* newNode = new Node(value);
            while (curr->data != refr) {
                if (curr->next == nullptr) {
                    // node not found, return false
                    return false;
                }
                curr = curr->next;
            }
            // checking for insert at last node
            if(curr->next != nullptr) {
                // not last node in list
                curr->next->prev = newNode;
                newNode->next = curr->next;
            } else {
                // last node in list, set next to null
                newNode->next = nullptr;
            }
            curr->next = newNode;
            newNode->prev = curr;
            return true;
        }

        // insert new node before specified node
        bool insertBefore(int refr, int value) {
            return true;
        }

        // insert new node at end of list
        void insertAtEnd(int value) {
            Node* newNode = new Node(value); // init new node
            if(head == nullptr) {
                head = newNode; // list empty, head points to new node
                return;
            } else {
                Node* curr = head; // list not empty, tmp variable to set through list
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode; // end found, insert
                newNode->prev = curr; // set new node's prev to ex last node in list
            }
        }

        // display elements of list starting w/ head
        void display() {
            Node* curr = head;
            while (curr->next != nullptr) {
                std::cout << curr->data << "->";
                curr = curr->next;
            }
            std::cout << curr->data << "\n" << std::endl;
        }

        // display elements of list starting w/ end
        void displayBackwards() {
            return;
        }

        // destructor to free memory used by list
};

int main() {
    std::cout << "\nMain Function Started\n" << std::endl;

    DoubleLinkedLink list;

    // testing insert before
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    std::cout << "expected: \n10->20" << std::endl;
    list.display();

    // testing insert at end
    list.insertAtEnd(80);
    list.insertAtEnd(90);
    std::cout << "expected: \n10->20->80->90" << std::endl;
    list.display();

    // testing insert after
    list.insertAfter(10, 15);
    list.insertAfter(20, 25);
    list.insertAfter(90, 95);
    std::cout << "expected: \n10->15->20->25->80->90->95" << std::endl;
    list.display();

    return 0;
}