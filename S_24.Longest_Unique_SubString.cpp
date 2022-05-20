#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code hereinput[]
	int n=input.size();
	int ml=0;
	int end=0,start=0;
	unordered_set<char>hm;
	while(end<n){
		while(end<n and hm.find(input[end])==hm.end()){
			ml=max(ml,end-start+1);
			hm.insert(input[end]);
			end++;
		}
		while(start<end and input[start]!=input[end]){
			hm.erase(input[start]);
			start++;
		}
		hm.erase(input[start]);
			start++;
	}
	return ml;
}
-----------Optimised Approach-------------------
int uniqueSubstrings(string s)
{
    vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
