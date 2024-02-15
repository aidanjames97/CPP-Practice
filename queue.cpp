// queue class
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    // constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class queue {
    private:
        Node* head;
        Node * tail;

    public:
        queue() : head(nullptr), tail(nullptr) {}

        void insert(int value) {
            Node* newNode = new Node(value);

            // check if empty
            if(head == nullptr) {
                head = newNode;
                tail = newNode;
            }

            // queue not empty
            newNode->next = tail;
            tail->prev = newNode;
            tail = newNode;
        }
};

int main() {
    cout << "main function started\n" << endl;
}