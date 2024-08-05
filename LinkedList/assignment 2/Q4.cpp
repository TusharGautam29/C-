struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        
        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* nodeToRemove = current->next;
                current->next = current->next->next;
                delete nodeToRemove;
            } else {
                current = current->next;
            }
        }
        
        return dummy.next;
    }
};
