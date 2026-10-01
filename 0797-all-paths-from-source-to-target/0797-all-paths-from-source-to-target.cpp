class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(path,0,graph.size()-1,graph);
        return ans;
    }
    void dfs(vector<int> &path, int current, int target,vector<vector<int>>& graph){
        if(current==target){
            path.push_back(current);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(current);
        for(int i=0;i<graph[current].size();i++){
            dfs(path,graph[current][i],target,graph);
        }
        path.pop_back();
        return;
    }

};