class Solution {
public:
	int value(char op){
		if(op=='*' || op=='/') return 2;
		return 1;
	}
	int eval(int a,int b,char oper){
		if(oper=='*') return a*b;
		else if(oper=='/') return a/b;
		else if(oper=='-') return a-b;
		return a+b;
	}
	int calculate(string s) {
		 stack<int> num;
		 stack<char> op;
		for(int i=0;i<s.length();i++){
			if(s[i]==' ') continue;
			else if(isdigit(s[i])){   // for handling digits and numbers
				long long int temp=0;
				while(i<s.length() && isdigit(s[i])){
					temp=temp*10+s[i]-'0';
					i++;
				}
				i--;
				num.push(temp);
			}
			else{  //for handling operator
				if(op.empty() || value(s[i])>value(op.top()))
					 op.push(s[i]);
				else{
					while(!op.empty() && value(s[i])<=value(op.top())){
						int b=num.top();num.pop();
						int a=num.top();num.pop();
						int oper=op.top();op.pop();
						num.push(eval(a,b,oper));
					}
					op.push(s[i]);
				}
			}
		}
		 while(!op.empty()){
						int b=num.top();num.pop();
						int a=num.top();num.pop();
						int oper=op.top();op.pop();
						num.push(eval(a,b,oper));
					}
		return num.top();
	}    
};
