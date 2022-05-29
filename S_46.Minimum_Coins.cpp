int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>coins{1,2,5,10,20,50,100,500,1000};
    int coin_count=0;
    for(int i=8;i>=0;i--){
        while(amount>=coins[i]){
            int div=(amount/coins[i]);
            amount=amount-(coins[i]*div);
            coin_count+=div;
        }
        if(amount==0)
            break;
    }
    return coin_count;
}
