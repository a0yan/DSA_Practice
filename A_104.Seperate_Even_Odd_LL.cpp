Node* divide(int N, Node *head){
        // code here
        if(!head||!head->next)return head;
        Node* e=new Node(-1),*o=new Node(-1),*curr=head;
        Node* temp1=e,*temp2=o;
        while(curr){
            if(curr->data%2==0){
                e->next=curr;
                e=e->next;
            }
            else{
                o->next=curr;
                o=o->next;
            }
            curr=curr->next;
        }
        e->next=temp2->next;
        o->next=nullptr;
        return temp1->next;
    }
