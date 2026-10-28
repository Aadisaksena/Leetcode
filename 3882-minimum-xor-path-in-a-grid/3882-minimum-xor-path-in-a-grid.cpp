class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<int>>& grid, int i, int j, int x) {
        if (i < 0 || j < 0)
            return false;

        if (i == 0 && j == 0)
            return x == grid[0][0];

        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        int prev = x ^ grid[i][j];

        bool ans = solve(grid, i - 1, j, prev) ||
                   solve(grid, i, j - 1, prev);

        return dp[i][j][x] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1024, -1)
        ));

        for (int x = 0; x < 1024; x++) {
            if (solve(grid, m - 1, n - 1, x))
                return x;
        }

        return -1;
    }
};