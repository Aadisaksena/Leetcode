class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int> parent(nums.size(),-1);
        for (int i = 0; i < nums.size(); i++) {

    int best = 0;          // Best dp value among valid predecessors
    int bestIndex = -1;    // Index of that predecessor

    for (int j = i - 1; j >= 0; j--) {

        if (nums[i] % nums[j] == 0) {

            if (dp[j] > best) {
                best = dp[j];
                bestIndex = j;
            }

        }
    }

    if (bestIndex != -1) {
        dp[i] = best + 1;
        parent[i] = bestIndex;
    }
}
        //now we find the max elemet of the parent array and record its index
        int pos = 0;
int maxi = dp[0];

for (int i = 1; i < dp.size(); i++) {
    if (dp[i] > maxi) {
        maxi = dp[i];
        pos = i;
    }
}
    vector<int> lds;
    while(parent[pos]!=-1){
        lds.push_back(nums[pos]);
        pos=parent[pos];
    }
    lds.push_back(nums[pos]);
    return lds;
}
};