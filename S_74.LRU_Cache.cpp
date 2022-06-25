class Node{
    public:
        int data;
        int key;
        Node* next;
        Node* prev;
        Node(int key,int data){
            this->data=data;
            this->key=key;
            this->next=NULL;
            this->prev=NULL;
        }
}; 
class LRUCache {
public:
    int cap;
    Node* dh=new Node(-1,-1);
    Node* dt=new Node(-1,-1);
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        dh->next=dt;
        dt->prev=dh;
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int k=mp[key]->key;
        int v=mp[key]->data;
        remove(mp[key]);
        add(k,v);
        return v;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(cap==0){
            remove(dt->prev);
            add(key,value);
            }
            else{
                add(key,value);
                cap--;
            }
            return;
        }
        remove(mp[key]);
            add(key,value);
    }
    void add(int k,int v){
        Node* temp=new Node(k,v);
        Node* nx=dh->next;
        dh->next=temp;
        temp->prev=dh;
        temp->next=nx;
        nx->prev=temp;
        mp[k]=temp;
    }
    void remove(Node* curr){
        Node*pre=curr->prev;
        Node* nx=curr->next;
        pre->next=nx;
        nx->prev=pre;
        mp.erase(curr->key);
        delete curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
