class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        return solve(prices,dp,0,0);
    }
    int solve(vector<int>& prices, vector<vector<int>>& dp, int index, int have){
        if(index>=prices.size())
        return 0;

        if(dp[index][have]!=-1)
        return dp[index][have];

        //if the person does not have a stock right now
        if(have==0){
            int buy=-prices[index]+solve(prices,dp,index+1,have+1);
            int notbuy=solve(prices,dp,index+1,have);
            dp[index][have]=max(buy,notbuy);
        }
        //the person already has stocks
        if(have==1)
        {
            int sell=prices[index]+solve(prices,dp,index+2,have-1);
            int notsell=solve(prices,dp,index+1,have);
            dp[index][have]=max(sell,notsell);
        }

        return dp[index][have];
    }
};