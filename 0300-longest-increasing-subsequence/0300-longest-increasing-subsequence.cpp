class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,dp,0,-1);
    }
    int solve(vector<int>& nums,vector<vector<int>>& dp, int index,int last_index){
        
        if(index==nums.size())
        return 0;

        if(dp[index][last_index+1]!=-1)
        return dp[index][last_index+1];

        //ek element pr hain ab agar eo humare pichle element se bada hai then we take it or skip it
        if(last_index==-1 || nums[index]>nums[last_index]){
           int take=1+ solve(nums,dp,index+1,index);
           int skip=solve(nums,dp,index+1,last_index);
           dp[index][last_index+1]=max(take,skip);
        }
        else{//we skip it
            dp[index][last_index+1]=solve(nums,dp,index+1,last_index);
        }

        return dp[index][last_index+1];
    }
};