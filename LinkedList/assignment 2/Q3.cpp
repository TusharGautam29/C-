
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp= temp->next;
            count++;
        }
        for(int i=1;i<k;i++) slow=slow->next;
        for(int i=0;i<count-k;i++) fast=fast->next;
        int temp2=slow->val;
        slow->val=fast->val;
        fast->val=temp2;
        return head;
    }
};