#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = nullptr;
    }
};

class OddEvenList {
private:
    Node* oddHead;
    Node* evenHead;
    Node* oddTail;
    Node* evenTail;

public:
    OddEvenList() : oddHead(nullptr), evenHead(nullptr), oddTail(nullptr), evenTail(nullptr) {}

   
    void add(int value) {
        Node* newNode = new Node(value);
        if (value % 2 != 0) { 
            if (oddHead == nullptr) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else {
            if (evenHead == nullptr) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
    }

    void display() {
        Node* temp = oddHead;
        cout << "Odd elements: ";
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        temp = evenHead;
        cout << "Even elements: ";
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayMore() {
        Node* temp = oddHead;
        cout << "Odd elements detailed info:" << endl;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Value: " << temp->value;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }

        temp = evenHead;
        cout << "Even elements detailed info:" << endl;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Value: " << temp->value;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    void deleteAtStartOdd() {
        if (oddHead == nullptr) {
            cout << "Odd list is empty!" << endl;
            return;
        }
        Node* temp = oddHead;
        oddHead = oddHead->next;
        delete temp;
        if (oddHead == nullptr) {
            oddTail = nullptr;
        }
    }

    void deleteAtEndOdd() {
        if (oddHead == nullptr) {
            cout << "Odd list is empty!" << endl;
            return;
        }
        if (oddHead->next == nullptr) {
            delete oddHead;
            oddHead = nullptr;
            oddTail = nullptr;
            return;
        }
        Node* secondLast = oddHead;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        oddTail = secondLast;
        delete temp;
    }

    void deleteAtStartEven() {
        if (evenHead == nullptr) {
            cout << "Even list is empty!" << endl;
            return;
        }
        Node* temp = evenHead;
        evenHead = evenHead->next;
        delete temp;
        if (evenHead == nullptr) {
            evenTail = nullptr;
        }
    }

    void deleteAtEndEven() {
        if (evenHead == nullptr) {
            cout << "Even list is empty!" << endl;
            return;
        }
        if (evenHead->next == nullptr) {
            delete evenHead;
            evenHead = nullptr;
            evenTail = nullptr;
            return;
        }
        Node* secondLast = evenHead;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        evenTail = secondLast;
        delete temp;
    }

    int getLengthOdd() {
        Node* temp = oddHead;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    int getLengthEven() {
        Node* temp = evenHead;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    
};

int main() {
    OddEvenList list;   
    list.add(1);   
    list.add(2);   
    list.add(3);   
    list.add(4);   

    cout << "List of elements: " << endl;
    list.display();

    cout << "Detailed list info:" << endl;
    list.displayMore();
    list.deleteAtStartOdd();
    list.deleteAtEndEven();
    list.deleteAtStartEven();

    cout << "List of elements after removals: " << endl;
    list.display();
    return 0;
}