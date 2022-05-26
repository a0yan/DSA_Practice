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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode* curr=head;
        int l=0;
        while(curr){
            s.push(curr);
            curr=curr->next;
            l++;
        }
        curr=head;
        int i=1;
        while(i<=(l/2)and curr){
            ListNode* nxt=curr->next;
            curr->next=s.top();
            s.pop();
            curr->next->next=nxt;
            curr=nxt;
            i++;
        }
        curr->next=nullptr;
        // return head;
    }
};
