struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* dummy=new ListNode(0);
        ListNode* cur=head;

        while(cur!=NULL){
            ListNode* pre=dummy;
            ListNode* next=cur->next;

            while(pre->next!=NULL && pre->next->val<cur->val)
                pre=pre->next;
            
            cur->next=pre->next;
            pre->next=cur;
            cur=next;
        }

        return dummy->next;
    }
};