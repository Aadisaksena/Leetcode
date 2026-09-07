class Solution {
public:

    int minutes = 0;

    void BFS(vector<pair<int, int>>& oranges, vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Put all initially rotten oranges into the queue
        for (auto p : oranges) {
            q.push(p);
        }

        while (!q.empty()) {

            int size = q.size();

            // Process one complete level
            for (int i = 0; i < size; i++) {

                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                // A - 1 : upper row
                if (a - 1 >= 0 && grid[a - 1][b] == 1) {
                    grid[a - 1][b] = 2;
                    q.push({a - 1, b});
                }

                // A + 1 : lower row
                if (a + 1 < n && grid[a + 1][b] == 1) {
                    grid[a + 1][b] = 2;
                    q.push({a + 1, b});
                }

                // B - 1 : left column
                if (b - 1 >= 0 && grid[a][b - 1] == 1) {
                    grid[a][b - 1] = 2;
                    q.push({a, b - 1});
                }

                // B + 1 : right column
                if (b + 1 < m && grid[a][b + 1] == 1) {
                    grid[a][b + 1] = 2;
                    q.push({a, b + 1});
                }
            }

            // One BFS level = one minute
            minutes++;
        }

        // The last increment happens even though no new orange
        // was rotten during that final level.
        if (minutes > 0)
            minutes--;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> oranges;

        // Store coordinates of all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    oranges.push_back({i, j});
                }
            }
        }

        // Perform multi-source BFS
        BFS(oranges, grid);

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};