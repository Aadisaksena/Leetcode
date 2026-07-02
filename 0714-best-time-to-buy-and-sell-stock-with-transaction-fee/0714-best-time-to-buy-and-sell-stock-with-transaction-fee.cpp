class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        return solve(prices,dp,0,0,fee);
    }
    int solve(vector<int>& prices, vector<vector<int>>& dp, int index, int have, int fee){
        if(index>=prices.size())
        return 0;

        if(dp[index][have]!=-1)
        return dp[index][have];

        //if the person does not have a stock right now
        if(have==0){
            int buy=-prices[index]+solve(prices,dp,index+1,have+1,fee);
            int notbuy=solve(prices,dp,index+1,have,fee);
            dp[index][have]=max(buy,notbuy);
        }
        //the person already has stocks
        if(have==1)
        {
            int sell=prices[index]-fee+solve(prices,dp,index+1,have-1,fee);
            int notsell=solve(prices,dp,index+1,have,fee);
            dp[index][have]=max(sell,notsell);
        }

        return dp[index][have];
    }
};