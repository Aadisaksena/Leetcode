class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Available servers
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Busy servers: {finish_time, server_id}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests have finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // Wrap around if no such server exists
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request to this server
            available.erase(it);

            // Mark server as busy
            busy.push({arrival[i] + load[i], server});

            // Increment handled requests
            handled[server]++;
        }

        // Find maximum number of handled requests
        int mx = *max_element(handled.begin(), handled.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (handled[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};