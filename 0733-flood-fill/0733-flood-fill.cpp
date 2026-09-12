class Solution {
public:

    void bfs(vector<vector<int>>& image, int sr, int sc,
             int oldColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr, sc});

        image[sr][sc] = newColor;

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // UP
            if (r - 1 >= 0 && image[r - 1][c] == oldColor) {
                image[r - 1][c] = newColor;
                q.push({r - 1, c});
            }

            // DOWN
            if (r + 1 < m && image[r + 1][c] == oldColor) {
                image[r + 1][c] = newColor;
                q.push({r + 1, c});
            }

            // LEFT
            if (c - 1 >= 0 && image[r][c - 1] == oldColor) {
                image[r][c - 1] = newColor;
                q.push({r, c - 1});
            }

            // RIGHT
            if (c + 1 < n && image[r][c + 1] == oldColor) {
                image[r][c + 1] = newColor;
                q.push({r, c + 1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        bfs(image, sr, sc, oldColor, color);

        return image;
    }
};