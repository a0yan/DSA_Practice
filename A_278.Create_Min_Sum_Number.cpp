long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long num1=0,num2=0;
        bool flag=true;
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            if(flag)
            num1=num1*10+val;
            else
            num2=num2*10+val;
            flag=!flag;
            
        }
        return num1+num2;
    }
