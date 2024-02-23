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

            // check for one element
            if(head->prev == nullptr) {
                head->prev = newNode;
            }

            // inserting
            tail->prev = newNode;
            newNode->next = tail;
            newNode->prev = nullptr;
            tail = newNode;
        }

        // remove and return the next element in the queue
        int remove() {
            // check if queue empty
            if(head == nullptr) {
                throw runtime_error("Empty Queue");
            }
            // check if only one node in queue
            if(head->prev == nullptr) {
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

        // display all elements in queue
        void display() {
            queue temp;
            cout << " HEAD" << endl;
            while(head != nullptr) {
                int tmp = remove();
                temp.insert(tmp);
                cout << "| " << tmp << " |" << endl;
            }
            cout << " TAIL" << endl;

            // set original queue to temp queue
            while(temp.head != nullptr) {
                insert(temp.remove());
            }
        }   
};

int main() {
    cout << "main function started\n" << endl;

    queue q;

    cout << "queue should be empty" << endl;

    try {
        // test empty remove
        q.remove();
    } catch (const exception& e) {
        cout << e.what() << "\n" << endl;
    }

    cout << "remove should be 6" << endl;

    // test insert and remove with one item
    q.insert(6);
    cout << q.remove() << endl;

    try {
        // test remove then empty queue
        cout << "should be Empty Queue" << endl;
        q.remove();
    } catch (const exception& e) {
        cout << e.what() << "\n" << endl;
    }

    // test inserting many elements
    q.insert(1);
    q.insert(2);    
    q.insert(3);
    q.insert(4);
    q.insert(5);

    cout << "should be 1,2,3,4,5" << endl;
    q.display();

    cout << "\nshould be 1 then 2" << endl;

    cout << q.remove() << endl;
    cout << q.remove() << "\n" << endl;

}