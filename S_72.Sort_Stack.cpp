stack<int> helper(stack<int>st){
    if(st.size()==0){
        return st;
    }
    stack<int>temp,sorted;
    int value=st.top();
    st.pop();
    sorted=helper(st);
    while(!sorted.empty() and value<sorted.top()){
        temp.push(sorted.top());
        sorted.pop();
    }
    sorted.push(value);
    while(!temp.empty()){
        sorted.push(temp.top());
        temp.pop();
    }
    return sorted;
}
void sortStack(stack<int> &st)
{
    st=helper(st);
	// Write your code here
}
