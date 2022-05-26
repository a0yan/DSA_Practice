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
    int length(ListNode* head){
        ListNode* curr=head;
        int l=0;
        while(curr){
            curr=curr->next;
            l++;
        }
        return l;
    }
    long long pow(int y){
        long long res=1;
        long long x=2;
        while(y){
            if(y&1){
                res=res*x;
                
            }
            x=x*x;
            y=y>>1;
        }
        return res;
    }
    int getDecimalValue(ListNode* head) {
        int l=0;
        l=length(head);
        long long exp=pow(l-1);
        int val=0;
        ListNode* curr=head;
        while(curr){
            if(curr->val==1){
                val+=exp*1;
            }
            exp/=2;
            curr=curr->next;
        }
        return val;
        
    }
};
