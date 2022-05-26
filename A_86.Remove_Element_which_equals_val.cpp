/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dh=new ListNode(-1);
        ListNode* prev=dh,*curr=head;
        curr=head;
        while(curr){
            while(curr and curr->val==val){
                curr=curr->next;
            }
            prev->next=curr;
            if(curr)
                curr=curr->next;
            prev=prev->next;
        }
        return dh->next;
    }
};
