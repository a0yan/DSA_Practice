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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        if(!slow||slow->next==nullptr){
            return nullptr;
        }
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
            
        }
        if(!fast || !fast->next)
            return nullptr;
        fast=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
    }
};
