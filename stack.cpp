#include <iostream>
#include <stdexcept>
using namespace std;

// stack implementation using linked list
struct Node {
    int data;
    Node* prev;
    // constructoer
    Node(int value) : data(value), prev(nullptr) {}
};

class linkedListStack{
    private:
        Node* head;
        int len;
    public:
        linkedListStack() : head(nullptr), len(0) {} // constructor

        // push (add) value to head (top) of stack
        void push(int value) {
            Node* newNode = new Node(value);
            len++;
            newNode->prev = head;
            head = newNode;
        }

        // pop (remove and return) value from head (top) of stack
        int pop() {
            if(!isEmpty()) {
                int tmp = head->data; // temp to hold data
                head = head->prev; // chang head to point to prev
                len--; // decrement size
                return tmp;
            }
            throw runtime_error("stack contains no elements!");
        }

        // peek (return) value from head (top) of stack <done>
        int peek() {
            if(!isEmpty()) {
                return head->data;
            }
            throw runtime_error("stack contains no elements!"); 
        }

        // isEmpty, checks if stack contains value(s) <done>
        bool isEmpty() {
            if(this->len == 0) {
                return true;
            }
            return false;
        }

        // returns number of values / nodes in stack <done>
        int size() {
            return this->len;
        }

        // display all nodes in stack <done>
        void display() {
            Node* curr = head;
            for(int i = 0; i < len; i++) {
                cout << "| " << curr->data << " |" << endl;
                curr = curr->prev;
            }
            cout << "-----" << endl;
            delete curr;
        }

        // destructor to free memory used by stack <done>
        ~linkedListStack() {
            Node* curr = head;
            Node* next;
            while (curr != nullptr) {
                next = curr->prev;
                delete curr;
                curr = next;
            }
            head = nullptr;
        }
};

int main() {
    cout << "\nMain Function Started\n" << endl;

    linkedListStack stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    stack.display();
    cout << "popping (exp: 1): " << stack.pop() << endl;
    cout << "size (exp: 4): " << stack.size() << endl;
    cout << "peeking (exp: 2): " << stack.peek() << endl;
    cout << "isEmpty? (exp 0): " << stack.isEmpty() << endl;

    cout << "pushing 8 then 9" << endl;
    stack.push(8);
    stack.push(9);
    stack.display();
}