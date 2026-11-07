class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //making the adj list
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int mincount = INT_MAX;
int ans = -1;
        for(int i=0;i<adj.size();i++){
            vector<int> dist(n, INT_MAX);
            dijkstra(dist,i,adj);
           
            int count=0;
            for(int j=0;j<dist.size();j++){
                if(dist[j]<=distanceThreshold)
                count++;
            }
            if(count<=mincount){
                mincount=count;
                ans=i;
            }
        }
        return ans;
    }
    void dijkstra(vector<int>& dist, int src,vector<vector<pair<int,int>>>& adj) {

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto& edge : adj[node]) {

            int next = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[next]) {

                dist[next] = dist[node] + weight;

                pq.push({
                    dist[next],
                    next
                });
            }
        }
    }
}
};