class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1){
                    if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    q.push({i, j});
                }
                }
            }
        }
        bfs(grid, q);
        int c=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                c++;
            }
        }
        return c;
    }
    void bfs(vector<vector<int>>&grid, queue<pair<int, int>> q) {

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r + 1 <grid.size() &&grid[r + 1][c] == 1) {
                    q.push({r + 1, c});
                grid[r + 1][c] = 2;
                }
                if (r - 1 >=0 &&grid[r - 1][c] == 1) {
                    q.push({r - 1, c});
                grid[r - 1][c] = 2;
                }
                if (c + 1 <grid[0].size() &&grid[r][c+1] == 1) {
                    q.push({r, c+1});
                grid[r ][c+1] = 2;
                }
                if (c - 1 >=0 &&grid[r][c-1] == 1) {
                    q.push({r, c-1});
                grid[r][c-1] = 2;
                }
            }
        }
    }
};