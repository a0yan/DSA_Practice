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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dh_head=new ListNode();
        ListNode* curr=dh_head;
        while(list1 and list2){
            ListNode*node_2=new ListNode();
            curr->next=node_2;
            curr=curr->next;
            if(list1->val<=list2->val){
                curr->val=list1->val;
                list1=list1->next;
            }
            else{
                curr->val=list2->val;
                list2=list2->next;
            }
            
        }
        while(list1){
            ListNode*node_2=new ListNode();
            curr->next=node_2;
            curr=curr->next;
            curr->val=list1->val;
            list1=list1->next;
            
        }
        while(list2){
            ListNode*node_2=new ListNode();
            curr->next=node_2;
            curr=curr->next;
            curr->val=list2->val;
            list2=list2->next;
            
        }
        return dh_head->next;
    }
};
