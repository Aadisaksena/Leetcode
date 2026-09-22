class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<int> dp(k,0);
        vector<long long> ans(k,0);
        for(int  i=0;i<nums.size();i++){
            int rem=nums[i]%k;
            
            vector<int>newdp(k,0);
            newdp[rem]++;
            for(int j=0;j<k;j++){//remainder traverseing
                int newr=(j * rem)%k;
                newdp[newr]+=dp[j];
            }
             for (int s = 0; s <  k; s++) {
                ans[s] += newdp[s];
            }
            dp=newdp;
        }
        return ans;
    }
};