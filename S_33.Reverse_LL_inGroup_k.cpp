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
    ListNode* helper(ListNode* head,int k){
        ListNode *prev,*nxt,*curr;
        curr=head;
        for(int i=0;i<k;i++){
            if(curr==nullptr){
                return head;
            }
            curr=curr->next;
        }
        prev=nullptr;
        curr=head;
        int count=0;
        while(count<k && curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        if(curr){
            head->next=helper(curr,k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(head,k);
        
    }
};
