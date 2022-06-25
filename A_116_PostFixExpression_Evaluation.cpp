int evaluatePostfix(string exp)
    {
        
    stack<int>st;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int ans=0;
            switch(exp[i]){
                case'*':
                    ans+=b*a;
                    break;
                case '+':
                    ans+=b+a;
                    break;
                case '-':
                    ans+=b-a;
                    break;
                case '/':
                    ans+=b/a;
                    break;
            }
            st.push(ans);
        }
        else{
            st.push(exp[i]-'0');
        }
    }
    return st.top();
    }
