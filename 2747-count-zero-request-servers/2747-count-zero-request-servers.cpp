class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Step 1: Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // Step 2: Store query time with original index
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        // Step 3: Sort queries by time
        sort(q.begin(), q.end());

        // Step 4: Frequency map
        unordered_map<int,int> mp;

        vector<int> ans(queries.size());

        // Step 5: Sliding window pointers
        int left = 0;
        int right = 0;

        for(pair<int,int>& p : q) {

            int time = p.first;
            int idx = p.second;

            int start = time - x;

            // Expand right boundary
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                int server = logs[right][0];

                mp[server]++;
                right++;
            }

            // Shrink left boundary
            while(left < logs.size() &&
                  logs[left][1] < start) {

                int server = logs[left][0];

                mp[server]--;

                if(mp[server] == 0) {
                    mp.erase(server);
                }

                left++;
            }

            // Calculate inactive servers
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};