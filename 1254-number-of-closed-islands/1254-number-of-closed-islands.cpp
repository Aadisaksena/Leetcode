class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // bfs via bordered zeroes
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 &&
                    (i == 0 || j == 0 || i == grid.size() - 1 ||
                     j == grid[0].size() - 1)) {
                    bfs(grid, i, j); // bfs to remove bordered zeroes
                }
            }
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto aage = q.front();
            int row = aage.first;
            int col = aage.second;
            grid[aage.first][aage.second] = 1;
            q.pop();
            if (row - 1 >= 0) {
                if (grid[row - 1][col] == 0)
                    q.push({row - 1, col});
            }
            if (row + 1 <= grid.size()-1) {
                if (grid[row + 1][col] == 0)
                    q.push({row + 1, col});
            }
            if (col - 1 >= 0) {
                if (grid[row][col - 1] == 0)
                    q.push({row, col - 1});
            }
            if (col + 1 <= grid[0].size() - 1) {
                if (grid[row][col + 1] == 0)
                    q.push({row, col + 1});
            }
        }
    }
};