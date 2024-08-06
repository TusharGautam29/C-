#include<iostream>
class Node{
    public:
        int val;
        Node* next;
    
    Node(int val):val(val),next(nullptr);
};
Node* swapnodes(Node* head){
    Node* dummy= new Node(0);
    dummy->next = head;
    Node* current = dummy;

    while (current->next && current->next->next) {
        ListNode* temp1 = current->next;
        ListNode* temp2 = current->next->next;
        temp1->next = temp2->next;
        temp2->next = temp1;
        current->next = temp2;
        current = temp1;
    }
    return dummy->next;
};
