ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* dh=new ListNode(INT_MAX);
        ListNode* prev=dh,*curr=head;
        while(curr){
            while(curr and curr->val==prev->val){
                curr=curr->next;
            }
            prev->next=curr;
            if(curr)
            curr=curr->next;
            prev=prev->next;
        }
        return dh->next;
    }
};
