/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* get_last(Node* head){
        if(!head){
            return head;
        }
        while(head->next){
            head=head->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
    if(!head)
        return head;
     Node* last,*curr=head,*temp;
    curr=head;
    while(curr){
        if(curr->child){
            Node* last=get_last(curr->child);
            last->next=curr->next;
            if(curr->next)
                curr->next->prev=last;
            curr->next=curr->child;
            curr->child->prev=curr;
            curr->child=nullptr;
        }
        curr=curr->next;
    }
        return head;
    }
};
