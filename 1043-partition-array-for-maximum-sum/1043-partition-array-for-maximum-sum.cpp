class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return solve(arr,k,0,dp);
    }
    int solve(vector<int>& arr, int k,int start,vector<int>& dp){
        if(start==arr.size()){
            return 0;
        }
        if(dp[start]!=-1)
        return dp[start];
        int maxx=INT_MIN;
        int sum=0;
        int ans=INT_MIN;
        for(int i=start;i<start+k && i<arr.size();i++){
            maxx=max(maxx,arr[i]);
            //if i choose to partition
            sum=(i-start+1)* maxx + solve(arr,k,i+1,dp);
            ans=max(ans,sum);
        }
        dp[start]=ans;
        return dp[start];
    }
};