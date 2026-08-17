class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return uniqtre(n,dp);
    }
    int uniqtre(int n,vector<int>& dp){
        if(n==0)return 1;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            //for a given index
            ans+=uniqtre(i-1,dp)*uniqtre(n-i,dp);
        }
        dp[n]=ans;
        return dp[n];
    }
};