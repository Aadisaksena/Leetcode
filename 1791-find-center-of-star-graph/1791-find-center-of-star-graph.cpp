class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1; i <= n; i++) {
            if(adj[i].size() == n - 1) {
                return i;
            }
        }

        return -1;
    }
};