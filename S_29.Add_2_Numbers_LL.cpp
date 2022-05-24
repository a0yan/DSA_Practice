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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* dh=new ListNode();
     ListNode* curr=dh;   
    int carry=0;
    while(l1&&l2){
        ListNode* temp=new ListNode(0);
        curr->next=temp;
        int total=l1->val+l2->val+carry;
        if(total>=10){
            carry=1;
            total=total%10;
        }
        else{
            carry=0;
        }
        temp->val=total;
        curr=curr->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1){
        ListNode* temp=new ListNode(0);
        curr->next=temp;
        int total=l1->val+carry;
        if(total>=10){
            carry=1;
            total=total%10;
        }
        else{
            carry=0;
        }
        l1=l1->next;
        temp->val=total;
        curr=curr->next;
        
    }
        while(l2){
        ListNode* temp=new ListNode(0);
        curr->next=temp;
        int total=l2->val+carry;
        if(total>=10){
            carry=1;
            total=total%10;
        }
        else{
            carry=0;
        }
        l2=l2->next;
        temp->val=total;
        curr=curr->next;
        }
        if(carry){
            ListNode* temp=new ListNode(1);
        curr->next=temp;
        }
        return dh->next;
    }
};
