/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode* curr=headA;
        while(curr){
            l1++;
            curr=curr->next;
        }
        curr=headB;
        while(curr){
            l2++;
            curr=curr->next;
        }
        ListNode *start_e,*start_l;
        if(l1>l2){
        start_e=headA;
        start_l=headB;
        }
        else{
            start_e=headB;
            start_l=headA;
        }
        int diff=abs(l1-l2);
        while(diff){
            start_e=start_e->next;
            diff--;
        }
        while(start_e!=start_l){
            start_e=start_e->next;
            start_l=start_l->next;
        }
        return start_e;
        
    }
};
