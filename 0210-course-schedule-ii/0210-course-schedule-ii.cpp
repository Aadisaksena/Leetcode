class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int u=q.front();
            topo.push_back(u);
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                indegree[adj[u][i]]--;

                if(indegree[adj[u][i]]==0)
                q.push(adj[u][i]);
            }
        }
        if(topo.size()!=numCourses)
        return {};
        return topo;
    }
};