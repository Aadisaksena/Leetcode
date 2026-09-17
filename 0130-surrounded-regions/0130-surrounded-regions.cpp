class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // consider the boundary zeroes and traverse from them and thm mark them
        // a
        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1){
                    if (board[i][j] == 'O') {
                    board[i][j] = 'A';
                    q.push({i, j});
                }
                }
            }
        }
        bfs(board, q);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                    else if (board[i][j] == 'A') 
                    board[i][j] ='O';
            }
        }
    }
    void bfs(vector<vector<char>>&board, queue<pair<int, int>> q) {

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r + 1 < board.size() && board[r + 1][c] == 'O') {
                    q.push({r + 1, c});
                    board[r + 1][c] = 'A';
                }
                if (r - 1 >=0 && board[r - 1][c] == 'O') {
                    q.push({r - 1, c});
                    board[r - 1][c] = 'A';
                }
                if (c + 1 < board[0].size() && board[r][c+1] == 'O') {
                    q.push({r, c+1});
                    board[r ][c+1] = 'A';
                }
                if (c - 1 >=0 && board[r][c-1] == 'O') {
                    q.push({r, c-1});
                    board[r][c-1] = 'A';
                }
            }
        }
    }
};