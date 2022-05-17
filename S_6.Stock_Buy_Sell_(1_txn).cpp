class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-min_so_far);
            min_so_far=min(min_so_far,prices[i]);
        }
        return profit;
    }
};
