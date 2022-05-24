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
        ListNode *curr,*prev,*nxt;
        curr=head;
        prev=nullptr;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast,*prev,*curr,*temp;
        curr=head;
        fast=head;
        slow=head;
        prev=nullptr;
        if(!head->next){
            return true;
        }
        while(fast and fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=nullptr;
        ListNode* r_slow=reverse(slow);
        temp=r_slow;
        while(temp and curr){
            if(temp->val!=curr->val){
                return false;
            }
            temp=temp->next;
            curr=curr->next;
        }
        
        
        return true;
        
    }
};
