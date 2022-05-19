#include<bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map < int,int > hm;
    int n=arr.size();
    int summ=0;
    int ml=0;
    for(int i=0;i<n;i++){
        summ+=arr[i];
        if(summ==0){
            ml=max(ml,i+1);
        }
        else{
            if(hm.find(summ)!=hm.end()){
                ml=max(ml,i-hm[summ]-1);
                // j-1-(i+1)+1
                //j-i-2+1
                //j-i-1;
            }
            else{
                hm[summ]=i;
            }
        }
    }
return ml;
}
