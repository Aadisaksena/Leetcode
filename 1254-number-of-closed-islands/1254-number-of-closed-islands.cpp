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
    grid[i][j] = 1;  // Mark visited immediately

    while (!q.empty()) {
        auto aage = q.front();
        int row = aage.first;
        int col = aage.second;
        q.pop();

        if (row - 1 >= 0 && grid[row - 1][col] == 0) {
            grid[row - 1][col] = 1;
            q.push({row - 1, col});
        }

        if (row + 1 < grid.size() && grid[row + 1][col] == 0) {
            grid[row + 1][col] = 1;
            q.push({row + 1, col});
        }

        if (col - 1 >= 0 && grid[row][col - 1] == 0) {
            grid[row][col - 1] = 1;
            q.push({row, col - 1});
        }

        if (col + 1 < grid[0].size() && grid[row][col + 1] == 0) {
            grid[row][col + 1] = 1;
            q.push({row, col + 1});
        }
    }
}

};