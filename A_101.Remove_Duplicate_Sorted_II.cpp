class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* dummy = new ListNode(0);
    // dummy->next = head;
    ListNode* prev=dummy;
	ListNode* curr = head;
    while(curr){
        if(curr and curr->next and curr->val==curr->next->val){
            int val=curr->val;
        while(curr and curr->val==val){
            curr=curr->next;
        }
            prev->next=curr;
        }
        else{
            prev->next=curr;
            prev=prev->next;
            curr=curr->next;
        }
        
    }
	return dummy->next;
}
};
