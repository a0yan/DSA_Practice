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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* curr=head;
        while(curr){
            l++;
            curr=curr->next;
        }
        int front=l-n;
        // cout<<front<<endl;
        if(front==0){
            return head->next;
        }
        else{
            front--;
            curr=head;
            int count=0;
            while(count<front){
                
                curr=curr->next;
                count++;
                // cout<<curr->val<<endl;
            }
            // ListNode* nex=curr->next;
            curr->next=curr->next->next;
        }
return head;
    }

};
