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
        Node* tail;

    public:
        queue() : head(nullptr), tail(nullptr) {}

        // insert node to back of queue
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

        int remove() {
            // check if queue empty
            if(head == nullptr) {
                cout << "Queue is empty, cannot remove anything\n";
                throw runtime_error("Empty Queue");
            }
            // check if only one node in queue
            if(head->prev == nullptr) {
                cout << "one elem queue" << endl;
                int d = head->data; // get data and store
                head = nullptr; // head points to null
                tail = nullptr; // tail points to null
                return d; // return
            }
            Node* tmp = head; // temp node to hold return node

            head = head->prev; // move back head
            head->next = nullptr; // set head's next ptr to null
            return tmp->data; // return data
        }
};

int main() {
    cout << "main function started\n" << endl;

    queue q;

    try {
        // test empty remove
        q.remove();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    // test insert and remove with one item
    q.insert(6);
    cout << q.remove() << endl;

    // test inserting many elements
    q.insert(1);
    q.insert(2);    
    q.insert(3);
    q.insert(4);
    q.insert(5);

    cout << q.remove() << endl;
    cout << q.remove() << endl;

}