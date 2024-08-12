#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;

    node(int data) {
        val = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        node* newNode = new node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtBeg(int data) {
        node* newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }

    void addAtPos(int pos, int data) {
        if (pos <= 0) {
            std::cout << "Position must be greater than 0." << std::endl;
            return;
        }

        if (pos == 1) {
            addAtBeg(data);
            return;
        }

        node* newNode = new node(data);
        node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Position is out of bounds." << std::endl;
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int getLength() {
        int length = 0;
        node* temp = head;
        while (temp != nullptr) {
            ++length;
            temp = temp->next;
        }
        return length;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void deleteNode(int key) {
        node* temp = head;
        node* prev = nullptr;

        if (temp != nullptr && temp->val == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->val != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void reverse() {
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;

    list.append(40);  
    list.addAtBeg(30); 
    list.addAtPos(1,50); 

    cout << "Length of the list: " << list.getLength() << endl;

    cout << "Linked List: ";
    list.display();  

    return 0;
}