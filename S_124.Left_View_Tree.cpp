vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   queue<Node*>q;
   if(!root){
       return ans;
   }
   q.push(root);
   while(!q.empty()){
       ans.push_back(q.front()->data);
       
       int sz=q.size();
       while(sz--){
           Node* n=q.front();
           q.pop();
           if(n->left){
               q.push(n->left);
           }
           if(n->right){
               q.push(n->right);
           }
       }
   }
   return ans;
}
