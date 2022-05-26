/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* curr,*nxt;
        curr=head;
        while(curr){
            nxt=curr->next;
            Node* copy=new Node(curr->val);
            curr->next=copy;
            copy->next=nxt;
            curr=nxt;
        }
        curr=head;
        while(curr){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node* dummy_head=new Node(-1);
        Node*prev=dummy_head;
        curr=head;
        while(curr){
            Node* front=curr->next->next;
            prev->next=curr->next;
            curr->next=front;
            curr=curr->next;
            prev=prev->next;
            
        }
        return dummy_head->next;
    }
};
