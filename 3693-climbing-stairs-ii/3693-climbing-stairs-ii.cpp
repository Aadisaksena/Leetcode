
class Solution {
public:
    int solve(int i, vector<int>& costs, vector<int>& dp) {

        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        // Jump from i-1
        if (i >= 1) {
            ans = min(ans, solve(i - 1, costs, dp)
                       + costs[i - 1] + 1);
        }

        // Jump from i-2
        if (i >= 2) {
            ans = min(ans, solve(i - 2, costs, dp)
                       + costs[i - 1] + 4);
        }

        // Jump from i-3
        if (i >= 3) {
            ans = min(ans, solve(i - 3, costs, dp)
                       + costs[i - 1] + 9);
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);

        return solve(n, costs, dp);
    }
};
