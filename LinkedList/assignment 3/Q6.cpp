struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverselist(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* mid=middle(head);
        ListNode* rev=reverselist(mid);
        ListNode*head2 =rev;
        int ans=0;
        while(head2){
            int sum=head->val+head2->val;
            ans=max(ans,sum);
            head=head->next;
            head2=head2->next;
        }
        return ans;
    }
};