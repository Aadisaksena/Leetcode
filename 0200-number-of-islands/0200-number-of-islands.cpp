class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int islands=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    if(visited[i][j]==0){
                        pair<int,int>start={i,j};
                        bfs(grid,visited,start);
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,pair<int,int>& start){
       queue<pair<int, int>> q;

        q.push(start);
        visited[start.first][start.second] = 1;

        while (!q.empty()) {

            pair<int, int> current = q.front();
            q.pop();

            int i = current.first;
            int j = current.second;

            // UP
            if (i - 1 >= 0) {
                if (grid[i - 1][j] == '1' && visited[i - 1][j] == 0) {
                    visited[i - 1][j] = 1;
                    q.push({i - 1, j});
                }
            }

            // DOWN
            if (i + 1 < grid.size()) {
                if (grid[i + 1][j] == '1' && visited[i + 1][j] == 0) {
                    visited[i + 1][j] = 1;
                    q.push({i + 1, j});
                }
            }

            // LEFT
            if (j - 1 >= 0) {
                if (grid[i][j - 1] == '1' && visited[i][j - 1] == 0) {
                    visited[i][j - 1] = 1;
                    q.push({i, j - 1});
                }
            }

            // RIGHT
            if (j + 1 < grid[0].size()) {
                if (grid[i][j + 1] == '1' && visited[i][j + 1] == 0) {
                    visited[i][j + 1] = 1;
                    q.push({i, j + 1});
                }
            }
        }
    }
};