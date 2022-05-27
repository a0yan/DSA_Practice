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
    ListNode* getMid(ListNode* head){
        if(!head ||!head->next)return head;
        ListNode* slow,*fast,*prev;
        slow=head;
        fast=head;
        while(fast and fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=nullptr;
        return slow;
    }
    ListNode* merge(ListNode* head,ListNode* mid){
        if(!head){
            return mid;
        }
        if(!mid){
            return head;
        }
        ListNode* result;
        if(head->val<=mid->val){
            result=head;
            result->next=merge(head->next,mid);
        }
        else{
            result=mid;
            result->next=merge(head,mid->next);
        }
        return result;
    }
    ListNode* merge_sort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* mid=getMid(head);
        ListNode* l1=merge_sort(head);
        ListNode* l2=merge_sort(mid);
        return merge(l1,l2);
        }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};
