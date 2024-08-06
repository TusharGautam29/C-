#include<iostream>
class Node{
    public:
        int val;
        Node* next;
    
    Node(int val):val(val),next(nullptr);
};

Node* mergeNodes(Node* head) {
    Node* newHead = new Node(0);
    Node* cur = newHead;
    int sum = 0;
    while (head && head->val == 0) head = head->next;
    while (head) {
        if (head->val == 0) {
            cur->next = new Node(sum);
            cur = cur->next;
            sum = 0;
        } 
        else sum += head->val;
        head = head->next;
    }
    return newHead->next;
};