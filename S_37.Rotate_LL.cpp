class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		//Condition to check if head is null or head's next is null or k = 0 in this case we return head
        if(!head || !head->next || k==0) return head;
        
		//intitialize current node at head
        ListNode* curr = head;
        
		//intitalize len variable to count length of list
        int len = 1;
        while(curr->next) {
            len++;
            curr = curr->next;
        }
        
		//connect tail of list to head
        curr->next = head;
        
		//if k is greater than length of list
        k %= len;
		// we have to iterate length - k - 1 time so that we can reach at that ListNode which we should break
        k = len - k - 1; 
        
        curr = head;
        while(k--)
            curr = curr->next;
        
		//new head
        head = curr->next;
		//finally breaking the loop of list
        curr->next = nullptr;
        
        return head;
    }
};
