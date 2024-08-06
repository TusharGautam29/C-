struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int listLength = getLength(head);
        if (!head || listLength < k) return head;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* current = dummyNode;
        ListNode* previousGroupEnd = dummyNode;
        ListNode* nextNode = dummyNode;

        while (listLength >= k) {
            current = previousGroupEnd->next;
            nextNode = current->next;
            for (int i = 1; i < k; ++i) {
                current->next = nextNode->next;
                nextNode->next = previousGroupEnd->next;
                previousGroupEnd->next = nextNode;
                nextNode = current->next;
            }
            previousGroupEnd = current;
            listLength -= k;
        }

        return dummyNode->next;
    }
};