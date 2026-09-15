class Solution {
public:
  vector<vector<int>> al;
    vector<bool> visited;
    vector<bool> path;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        al.resize(numCourses);
        visited.resize(numCourses, false);
path.resize(numCourses, false);

        for(int i=0;i<prerequisites.size();i++){
            al[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i))
                    return false;
            }}
            return true;
        }

       
    bool dfs(int node) {

        visited[node] = true;
        path[node] = true;

        for(int next : al[node]) {

            if(path[next])
                return false;

            if(!visited[next]) {
                if(!dfs(next))
                    return false;
            }
        }

        path[node] = false;

        return true;
    }
};