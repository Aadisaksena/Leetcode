class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Reverse graph
        vector<vector<int>> rev(n);

        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                rev[node].push_back(i);
            }
        }

        // Outdegree of each node
        vector<int> outdegree(n);

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            // Traverse reverse edges
            for (int prev : rev[node]) {
                outdegree[prev]--;

                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};