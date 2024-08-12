#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(const string& data) {
        name = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addAtBeg(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    void append(const string& name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtPos(const string& name, int pos) {
        if (pos < 0 || pos > getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            addAtBeg(name);
            return;
        }
        Node* newNode = new Node(name);
        Node* temp = head;
        int currPos = 0;
        while (currPos != pos - 1) {
            temp = temp->next;
            currPos++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayMore() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Name: " << temp->name;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    void deleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (pos < 0 || pos >= getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            deleteAtStart();
            return;
        }
        Node* prev = head;
        int currPos = 0;
        while (currPos != pos - 1) {
            prev = prev->next;
            currPos++;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }

    int getLength() {
        Node* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    
};

int main() {
    LinkedList friendsList;
    friendsList.addAtBeg("Alice");
    friendsList.append("Bob");
    friendsList.addAtPos("Charlie", 1);
    
    cout << "List of friends: ";
    friendsList.display();

    cout << "Detailed list info:" << endl;
    friendsList.displayMore();

    friendsList.deleteAtStart();
    friendsList.deleteAtEnd();
    friendsList.deleteAtPos(0);

    cout << "List of friends after removals: ";
    friendsList.display();

    

    return 0;
}