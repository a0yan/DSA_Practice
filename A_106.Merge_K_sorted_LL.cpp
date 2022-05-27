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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l2){
            return l1;
        }
        if(!l1){
            return l2;
        }
        ListNode* result;
        if(l1->val<=l2->val){
            result=l1;
            result->next=merge(l1->next,l2);
        }else{
            result=l2;
            result->next=merge(l1,l2->next);
        }
        return result;
    }
    ListNode* helper(vector<ListNode*>& lists,int i){
        if(i==lists.size())return nullptr;
        if(i==lists.size()-1)return lists[i];
        ListNode* temp=helper(lists,i+1);
        return merge(lists[i],temp);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists,0);
    }
};
