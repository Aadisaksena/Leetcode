class Solution {
public:
int MOD=1E9+7;
    int subsequencePairCount(vector<int>& nums) {
        int smol=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(smol+1,vector<int>(smol+1,-1)));
        return (solve(nums,dp,0,0,0))%MOD;
    }
    int solve(vector<int>& nums, vector<vector<vector<int>>>& dp,int index, int gcd1, int gcd2){
        if(index==nums.size()){
            if(gcd1==gcd2 && gcd1!=0)
            return 1;
            else
            return 0;
        }
        if(dp[index][gcd1][gcd2]!=-1)
        return dp[index][gcd1][gcd2];

            //now we are at an element we have two choices
            int skip=solve(nums,dp,index+1,gcd1,gcd2);
            int newgcd1=gcd(gcd1,nums[index]);
            int sub1=solve(nums,dp,index+1,newgcd1,gcd2);
            int newgcd2=gcd(gcd2,nums[index]);
            int sub2=solve(nums,dp,index+1,gcd1,newgcd2);

            long long ans = (1LL * skip + sub1 + sub2) % MOD;

            dp[index][gcd1][gcd2]=(int)ans;
            return dp[index][gcd1][gcd2];
    }
};