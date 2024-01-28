#include <iostream>

// Define the structure of a single node in the linked list
// data is of type int
// next points to another node struct
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Define the Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Display the elements of the linked list
    void display() {
        Node* current = head;
        while (current->next != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << current->data << "\n" << std::endl;
    }

    // Delete a node with a given value from the list
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the value to be deleted
        if (temp != nullptr && temp->data == value) {
            head = temp->next;
            delete temp;
            return;
        }

        // Search for the value to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // If the value was not present in the list
        if (temp == nullptr) return;

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
    }

    // Destructor to free the memory occupied by the linked list
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    std::cout << "\nMain Function Started\n" << std::endl;

    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);

    std::cout << "expected: 5 -> 10 -> 20" << std::endl;
    list.display(); // Output: 5 10 20
    list.deleteNode(10);
    std::cout << "expected: 5 -> 20" << std::endl;
    list.display(); // Output: 5 20
    return 0;
}