bool check_diff(vector<int> positions , int n ,  int c,int diff){
    int cows=1;
    int last_pos=positions[0];
    for(int i=1;i<n;i++){
        if(positions[i]-last_pos>=diff){
            cows++;
            last_pos=positions[i];
        }
    }
    return cows>=c;
    
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int low=1;
    int high=positions[n-1]-positions[0];
    int ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check_diff(positions,n,c,mid)==true){
            ans=mid;
            low=mid+1;
        }
           else{
              high=mid-1; 
           }
        
    }
    return ans;
}
