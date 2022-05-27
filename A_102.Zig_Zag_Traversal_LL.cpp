Node *zigZag(Node* head)
    {
        if(!head || !head->next)return head;
        bool flag=0;
        Node* curr=head;
        while(curr and curr->next){
            if(flag==0){
                if(curr->data>curr->next->data){
                    swap(curr->data,curr->next->data);
                }
            }
            else{
                if(curr->data<curr->next->data){
                    swap(curr->data,curr->next->data);
                }
            }
            flag=!flag;
            curr=curr->next;
        }
        return head;
     // your code goes here
    }
