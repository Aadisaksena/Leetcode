class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back(
                {flights[i][1], flights[i][2]}
            );
        }

        vector<int> price(n, INT_MAX);
        queue<int> q;

        q.push(src);
        price[src] = 0;

        int stops = 0;

        while(!q.empty() && stops <= k) {

    int sz = q.size();

    vector<int> temp = price;

    while(sz--) {

        int top = q.front();
        q.pop();

        for(auto it : adj[top]) {

            int neighbour = it.first;
            int cost = it.second;

            if(price[top] != INT_MAX &&
               temp[neighbour] > price[top] + cost) {

                temp[neighbour] = price[top] + cost;
                q.push(neighbour);
            }
        }
    }

    price = temp;
    stops++;
}

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};