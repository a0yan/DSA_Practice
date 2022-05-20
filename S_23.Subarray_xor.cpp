#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	unordered_map<int,int>hm;
	int n=arr.size(),xr=0,count=0;
	for(int i=0;i<n;i++){
		xr=xr^arr[i];
		if(xr==x){
			count++;
		}
		if(hm.find(xr^x)!=hm.end()){
			count+=hm[xr^x];
		}
		hm[xr]++;
	}
	return count;
}
