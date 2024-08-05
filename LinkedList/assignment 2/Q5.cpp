struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int countNodesInLoop(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return getLoopLength(slow);
        }
        return 0;
    }
    
private:
    int getLoopLength(ListNode* start) {
        int length = 0;
        ListNode* current = start;
        
        do {
            current = current->next;
            length++;
        } while (current != start);
        
        return length;
    }
};