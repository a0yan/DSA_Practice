#include<bits/stdc++.h>
bool cmp(pair<int, int>&a,pair<int, int>&b){
    return ((double)a.second/(double)a.first)>=((double)b.second/(double)b.first);
}
double maximumValue (vector<pair<int, int>>& arr, int n, int W)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
 sort(arr.begin(), arr.end(), cmp);
 
   
 
    double finalvalue = 0.0; // Result (value in Knapsack)
 
    // Looping through all Items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (arr[i].first <= W) {
            W -= arr[i].first;
            finalvalue += arr[i].second;
        }
 
        // If we can't add current Item, add fractional part
        // of it
        else {
            finalvalue += arr[i].second
                          * ((double)W
                             / (double)arr[i].first);
            break;
        }
    }
 
    // Returning final value
    return finalvalue;
}
