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
    ListNode* reverse(ListNode* head){
        ListNode*curr=head,*prev=nullptr,*nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     if(!head||!head->next||left==right)
         return head;
        ListNode* curr,*prev,*nxt;
        ListNode* dh=new ListNode(-1);
        dh->next=head;
        prev=dh;
        curr=head;
        int pos=1;
        while(curr and pos<left){
            prev=curr;
            curr=curr->next;
            pos++;
        }
        while(curr and pos<right){
            curr=curr->next;
            pos++;
        }
        if(curr){
        nxt=curr->next;
        curr->next=nullptr;
        }
        else{
            nxt=nullptr;
        }
        prev->next=reverse(prev->next);
        curr=prev;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=nxt;
        return dh->next;
    }
};
