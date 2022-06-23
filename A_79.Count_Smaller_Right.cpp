class Solution {
public:
    vector<int> sol;
    void merge(vector<pair<int,int>> &a,int start,int mid,int end){
        int i=start,j=mid+1;
        int k=0;
        vector<pair<int,int>>temp(end-start+1,{0,0});
        while(i<=mid && j<=end){
            if(a[i].first>a[j].first){
                sol[a[i].second]+=end-j+1;
                temp[k]=a[i];
                i++;
            }
            else{
                temp[k]=a[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            temp[k]=a[i];
                i++;
            k++;
        }
        while(j<=end){
            temp[k]=a[j];
            j++;
            k++;
        }
        for(int i=0;i<temp.size();i++){
            a[i+start]=temp[i];
        }
    }
    
    void mergesort(vector<pair<int,int>> &a,int start,int end){
        if(start>=end) return;
        int mid = start+(end-start)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        sol.resize(n,0);
        vector<pair<int,int>> idx;

        for(int i=0;i<n;i++)
            idx.push_back({nums[i],i});
        
        mergesort(idx,0,n-1);
        return sol;
    }
};
