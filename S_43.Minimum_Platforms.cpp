int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    
        // Your code here
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=1,j=0,p_c=1,m_c=1;
        while(i<n and j<n){
            if(arr[i]<=dep[j]){
                p_c++;
            
                i++;
            }
            else{
                p_c--;
            
                j++;
            }
        m_c=max(p_c,m_c);
            
        }
        while(i<n){
            p_c++;
            m_c=max(p_c,m_c);
            i++;
        }
        return m_c;
    
}
