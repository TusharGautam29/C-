#include<iostream>
//Q1 1 pointer needs to be modified for deletion
//Q2 135
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;
    ListNode* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int idx) {
        ListNode* newNode = new ListNode(10);
        if (idx == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = head;
            }
            return;
        }

        ListNode* temp = head;
        for (int i = 0; i < idx - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        return;
    }

    void deleteNode(int idx) {
        if (head == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        if (idx == 0) {
            ListNode* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        ListNode* temp = head;
        for (int i = 0; i < idx - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next == nullptr) {
            tail = temp;
        }
        delete nodeToDelete;
    }

    int get(int idx) {
        ListNode* temp = head;
        for (int i = 0; i < idx && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            return -1;
        }
        return temp->val;
    }

    void display() {
        ListNode* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};